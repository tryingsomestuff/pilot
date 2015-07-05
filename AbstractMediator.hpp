#ifndef ABSTRACT__MEDIATOR__H
#define ABSTRACT__MEDIATOR__H

#include <iostream>
#include "TraitMediator.hpp"

/**
 *  Abstract mediator container. Encapsulate any type of data.
 *  All data container must inherit from this one.
 *  Note that in some case mediators will probably contains
 *  some functional stuff also, and AbstractCommand::_Execute
 *  will eventually use those ...
 **/
class AbstractMediator{
	public:
		// is the mediator data ready to be used ?
		enum M_Status{
			M_READY     = 0,
			M_BAD       = 1,
			M_NOT_READY = 2
		};
		AbstractMediator();
		virtual ~AbstractMediator();
		// is the mediator data ready to be used ?
		virtual M_Status Status() = 0;
		// Init will be called just after the mediator is registered
		virtual bool Init() = 0;
		virtual std::string Name();
   protected:
        std::string _name;
};

/**
 *  Elegant use of CRTP to automatically define Name from Trait
 *  This allows Trait specialization to be done anywhere as soon
 *  as the header is accessible here ...
 **/
template< class T >
class AbstractMediatorBase : public AbstractMediator{ // CRTP
   public:
       AbstractMediatorBase():AbstractMediator(){
          _name = TraitMediatorName<T>::Name();
       }
};

#endif // ABSTRACT__MEDIATOR__H
