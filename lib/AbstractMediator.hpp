#ifndef ABSTRACT__MEDIATOR__H
#define ABSTRACT__MEDIATOR__H

#include "Trait.hpp"
#include "Named.hpp"

/**
 *  Abstract mediator container. Encapsulate any type of data.
 *  All mediator container must inherit from this one.
 *  Note that in some case mediators will probably contains
 *  some functional stuff also, and AbstractCommand::_Execute
 *  will eventually use those throught data facades...
 *  You MUST NOT inherite from this one. See AbstractMediatorBase.
 **/
class AbstractMediator: public Named<MediatorType>{
	public:
		// is the mediator data ready to be used ?
		enum M_Status{
			M_READY     = 0,
			M_BAD       = -1,
			M_NOT_READY = -2
		};
        AbstractMediator();
		virtual ~AbstractMediator();
		/// Is the mediator data ready to be used ?
		/// virtual because things can become a little bit complex sometimes ...
		virtual M_Status Status()const; 
		/// Please note that Init() can be called automatically 
		/// just after the mediator is registered 
		/// in the DataPool in MediatorBuilder::Create(...) via
		/// DataPool::Instance()->Register(MediatorFactory::Create(...)
		/// Set status to M_READY by default. See _Init() to change this ...
		bool Init();
    protected:
	    M_Status _status;
		/// Init shall set _status to M_READY or M_BAD
		virtual bool     _Init() = 0;
};

/**
 *  The base implementation of an AbstractMediator.
 *  Automatically define Name from Trait
 *  This allows Trait specialization to be done anywhere as soon
 *  as the header is accessible there ...
 **/
template< class T >
class AbstractMediatorBase : public AbstractMediator{
   public:
       AbstractMediatorBase():AbstractMediator(){
          _id = TraitMediatorId<T>::Id();
       }
};

#endif // ABSTRACT__MEDIATOR__H
