#ifndef ABSTRACT___COMMAND__H
#define ABSTRACT___COMMAND__H

#include "Trait.hpp"
#include "Named.hpp"

class AbstractData;

/**
 *  Abstract command, use an AbstractData (facade) to access specified data from mediators in the DataPool
 *  _Execute must be defined in sub class to implement real stuff ...
 **/
class AbstractCommand:public Named<CommandType>{
	public:
		explicit AbstractCommand();
		virtual ~AbstractCommand();

		virtual bool          Execute(                );     // THIS IS NOT THE ONE THAT SHALL BE OVERRIDEN BY UER ///@todo BETTER !!!!
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
 *  Automatically define Name from Trait
 *  This allows Trait specialization to be done anywhere as soon
 *  as the header is accessible there ...
 **/
template< class T >
class AbstractCommandBase : public AbstractCommand{
   public:
       AbstractCommandBase():AbstractCommand(){
          _id = TraitCommandId<T>::Id();
       }
};

/**
 *  Automatically define Name from Trait
 *  This allows Trait specialization to be done anywhere as soon
 *  as the header is accessible there ...
 *  Command that automatically iterate until a specified condition 
 *  is obtained
 **/
template< class T >
class AbstractCommandIterate : public AbstractCommand{
   public:
       AbstractCommandIterate():AbstractCommand(),_cond(0){
          _id = TraitCommandId<T>::Id();
       }

	   ~AbstractCommandIterate(){
		   if ( _cond ){
			   delete _cond;
			   _cond = NULL;
		   }
	   }

	   class IterateCondition{
	   public:
		   virtual bool Iterate() = 0; 
	   };

	   // !!!! override the standard one
	   bool  Execute ( ){
			// data is required for _Execute to work !
			if (! _d){
				std::cout << "Data pointer is requiered before executing a commands, use SetData" << std::endl;
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
