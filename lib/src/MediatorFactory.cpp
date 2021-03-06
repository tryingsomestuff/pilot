#include "MediatorFactory.h"
#include "Trait.hpp"
#include "DataPool.hpp"

#include "DataFactory.h"
#include "AbstractCommand.hpp"
#include "AbstractData.hpp"
#include "AbstractMediator.hpp"

#include <string>
#include <set>
#include <assert.h>

// Must defined corresponding static members ...

/*
template<>
MediatorFactory * MediatorFactory::_instance = NULL;
*/

template<>
std::map<MediatorType,CreatorBase<AbstractMediator>*>
MediatorFactory::_map = std::map<MediatorType,CreatorBase<AbstractMediator>*>();


std::vector<AbstractMediator *> MediatorBuilder::Create(const AbstractCommand * command, bool init){
	assert(command);
	std::vector<AbstractMediator *> ret;
	// get data from command and get mediators types from data
	const AbstractData * d = command->GetData();
	if ( ! d ){
		Logger::Instance() << "ERROR : data not set yet for command " << command->Id();
		return ret;
	}
	const std::set<MediatorType> mediatorTypes = d->GetMediatorTypes();
	// iterate other needed mediators for current data
	Logger::Instance() << "Creating mediators for data : " << d->Id();
	std::set<MediatorType>::const_iterator it = mediatorTypes.begin();
	for( ; it != mediatorTypes.end() ; ++it){
		// add in DataPool if needed
		if ( ! DataPool::Instance()->Contains(*it)){
			Logger::Instance() << "Instantiating mediator : " << *it;
			// delegate the mediator to DataPool
			DataPool::Instance()->Register(MediatorFactory::Create(*it));
			AbstractMediator * med = DataPool::Instance()->GetMediator(*it);
			if ( ! init ){
				Logger::Instance() << "Mediator registered in datapool without being initialized : " << med->Id();
			}
			else if ( ! med->Init() || med->Status() != AbstractMediator::M_READY ){
				Logger::Instance() << "Fail to init mediator : " << med->Id();
			}
			ret.push_back(med);
		}
		else{
			Logger::Instance() << "Mediator already register in pool : " << *it;
		}
	}
	return ret;
}
