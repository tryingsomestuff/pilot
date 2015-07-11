#ifndef ABSTRACT___COMMAND__H
#define ABSTRACT___COMMAND__H

#include "Trait.hpp"

class AbstractData;

/**
 *  Abstract command, use an AbstractData (facade) to access specified data from mediators in the DataPool
 *  _Execute must be defined in sub class to implement real stuff ...
 **/
class AbstractCommand:public Named{
	public:
		explicit AbstractCommand();
		virtual ~AbstractCommand();

		bool                  Execute(                );
		void                  SetData(AbstractData * d);
		AbstractData *        GetData(                );
		const AbstractData *  GetData(                )const;
	protected:
		virtual bool _Execute() = 0;
		AbstractData * _d;
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
          _name = TraitCommandName<T>::Name();
       }
};

#endif // ABSTRACT___COMMAND__H
