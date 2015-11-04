#ifndef DATA__POOOL__H
#define DATA__POOOL__H

#include "MediatorFactory.h"
#include "AbstractMediator.hpp"
#include "Logger.hpp"

#include <map>

/**
 *  The DataPool singleton.
 *  You must register every Mediator in the DataPool.
 *  Use facade to mix up Mediator together and/or filter them !
 **/
class DataPool{ // singleton
	public:
		~DataPool();
		static DataPool *  Instance();
		// Delegate mediator to DataPool
		void               Register   (AbstractMediator * mediator); // take ownership
		AbstractMediator * GetMediator(MediatorType type);
		bool               Contains   (MediatorType type);
	private:
		explicit DataPool(){};
		static DataPool * _pool;
		std::map<MediatorType,AbstractMediator * > _mediators;
};

template< class T >
T * SafeMediatorAccess(){
	T * med = dynamic_cast<T*>(DataPool::Instance()->GetMediator(TraitMediatorId<T>::Id()));
	if ( ! med ){
		Logger::Instance() << "Cannot get mediator in DataPool : " << TraitMediatorId<T>::Id();
		return NULL;
	}
	if ( med->Status() == AbstractMediator::M_BAD ){
		Logger::Instance() << "Mediator is in BAD state : " << TraitMediatorId<T>::Id();
		return NULL;
	}
	if ( med->Status() == AbstractMediator::M_NOT_READY ){
		Logger::Instance() << "Mediator is not initialized yet. Forced init : " << TraitMediatorId<T>::Id();
		med->Init();
		return med;
	}
	// standard case
	return med;
}

#endif // DATA__POOOL__H
