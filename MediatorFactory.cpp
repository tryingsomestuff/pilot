#include "MediatorFactory.h"
#include "Trait.hpp"
#include "DataPool.h"

#include "DataFactory.h"
#include "AbstractCommand.hpp"
#include "AbstractData.hpp"

#include <string>
#include <set>

// Must defined corresponding static members ...

/*
MediatorFactory * MediatorFactory::_instance = NULL;
*/

std::map<MediatorType,CreatorBase<AbstractMediator>*> 
MediatorFactory::_map = std::map<MediatorType,CreatorBase<AbstractMediator>*>();

std::vector<AbstractMediator *> MediatorBuilder::Create(const AbstractCommand * command){
	std::vector<AbstractMediator *> ret;
	const std::set<MediatorType> mediatorTypes = command->GetData()->GetMediatorTypes();
	std::set<MediatorType>::const_iterator it = mediatorTypes.cbegin();
	std::cout << "Creating mediators for data " << command->GetData()->Id() << std::endl;
	for( ; it != mediatorTypes.cend() ; ++it){
		// add in DataPool if needed
		if ( ! DataPool::Instance()->Contains(*it)){
			std::cout << "Instantiating mediator " << *it << std::endl;
			// delegate the mediator to DataPool
			DataPool::Instance()->Register(MediatorFactory::Create(*it));
			ret.push_back(DataPool::Instance()->GetMediator(*it));
		}
		else{
			std::cout << "Mediator already register in pool " << *it << std::endl;
		}
	}
	return ret;
}
