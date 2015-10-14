#ifndef ABSTRACT___COMMAND__H
#define ABSTRACT___COMMAND__H

#include "Trait.hpp"
#include "Named.hpp"
#include "Logger.hpp"

#include <list>

class AbstractData;

/**
*  Abstract command, use an AbstractData (facade) to access specified data from mediators in the DataPool
*  _Execute must be defined in sub class to implement real stuff ...
*  You MUST NOT inherite from this one. See AbstractCommandBase or AbstractCommandIterate.
**/
class AbstractCommand:public Named<CommandType>{
public:
	explicit AbstractCommand(AbstractData *d=0, AbstractCommand * n=0);
	virtual ~AbstractCommand();

	virtual bool          Execute(                ) = 0; // THIS IS NOT THE ONE THAT SHALL BE OVERRIDEN BY USER
	void                  SetData(AbstractData * d);     // take ownership
	AbstractData *        GetData(                );     // shall will really give this one ???
	const AbstractData *  GetData(                )const;

	void                  SetNext(AbstractCommand * c);  // just seting next command. This will not register the corresponding type or instanciate anything
protected:
	virtual bool _Execute() = 0;  // THIS IS THE ONE THAT MUST BE OVERRIDE
	AbstractData * _d;
	AbstractCommand * _n;
};

/**
*  The base implementation of an AbstractCommand.
*  Automatically define Name from Trait
*  This allows Trait specialization to be done anywhere as soon
*  as the header is accessible there ...
**/
template< class T >
class AbstractCommandBase : public AbstractCommand{
public:
	AbstractCommandBase(AbstractData *d=0, AbstractCommand * n=0):AbstractCommand(d,n){
		_id = TraitCommandId<T>::Id();
	}

	bool Execute(){
		// data is required for _Execute to work !
		if (! _d){
			Logger::Instance() << "Data pointer is requiered before executing a commands, use SetData";
			return false;
		}
		if (_Execute()){
			if (_n){
				return _n->Execute();
			}
			else{
				return true;
			}
		}
		return false;
	}
};

/**
 * IterateCondition is an abstract class 
 * Sub-classes must define bool Iterate()
 * that teels if iteration have to go on or not.
 **/
class IterateCondition{
public:
	virtual bool Iterate() = 0;
};

/**
 * MultipleIterateCondition is an concrete class 
 * that teels if iteration have to go on or not
 * based on many IterateCondition.
 **/
class MultipleIterateCondition{
public:
    enum Mode{
        M_AND = 0,
        M_OR  = 1
    };

    MultipleIterateCondition (Mode m );
    ~MultipleIterateCondition(       );

	bool Iterate      ( );
	void AddCondition ( IterateCondition * cond); // take ownership
private:
	std::list<IterateCondition*> _conditions;
	Mode _m;
};

/**
*  The iterative implementation of an AbstractCommand.
*  Automatically define Name from Trait
*  This allows Trait specialization to be done anywhere as soon
*  as the header is accessible there ...
*  Command that automatically iterate until a specified condition
*  is obtained
**/
template< class T >
class AbstractCommandIterate : public AbstractCommand{
public:
	AbstractCommandIterate(AbstractData *d=0, AbstractCommand * n=0):AbstractCommand(d,n),_cond(0){
		_id = TraitCommandId<T>::Id();
	}

	~AbstractCommandIterate(){
		if ( _cond ){
			delete _cond;
			_cond = NULL;
		}
	}

	bool Execute(){
		// data is required for _Execute to work !
		if (! _d){
			Logger::Instance() << "Data pointer is requiered before executing a commands, use SetData";
			return false;
		}
		if (_Execute()){
			if ( _cond && _cond->Iterate() ){
				return Execute();
			}
			else{
				if (_n){
					return _n->Execute();
				}
				else{
					return true;
				}
			}
		}
		return false;
	}
	
	void  SetCondition ( IterateCondition * cond){_cond=cond;} // take ownership
	
protected:
	IterateCondition * _cond;
};

#endif // ABSTRACT___COMMAND__H
