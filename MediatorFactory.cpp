#include "MediatorFactory.h"
#include "Trait.hpp"
#include "DataPool.h"

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


std::vector<AbstractMediator *> MediatorBuilder::Create(const AbstractCommand * command){
	assert(command);
	std::vector<AbstractMediator *> ret;
	// get data from command and get mediators types from data
	const AbstractData * d = command->GetData();
	if ( ! d ){
		std::cout << "ERROR : data not set yet for command " << command->Id() << std::endl;
		return ret;
	}
	const std::set<MediatorType> mediatorTypes = d->GetMediatorTypes();
	// iterate other needed mediators for current data
	std::cout << "Creating mediators for data " << d->Id() << std::endl;
	std::set<MediatorType>::const_iterator it = mediatorTypes.begin();
	for( ; it != mediatorTypes.end() ; ++it){
		// add in DataPool if needed
		if ( ! DataPool::Instance()->Contains(*it)){
			std::cout << "Instantiating mediator " << *it << std::endl;
			// delegate the mediator to DataPool
			DataPool::Instance()->Register(MediatorFactory::Create(*it));
			AbstractMediator * med = DataPool::Instance()->GetMediator(*it);
			if ( ! med->Init() ){
				std::cout << "Fail to init mediator " << med->Id() << std::endl;
			}
			ret.push_back(med);
		}
		else{
			std::cout << "Mediator already register in pool " << *it << std::endl;
		}
	}
	return ret;
}
