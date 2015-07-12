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
AbstractFactory<AbstractMediator,std::string> *
AbstractFactory<AbstractMediator,std::string>::_instance = NULL;
*/

std::map<std::string,CreatorBase<AbstractMediator>*> 
AbstractFactory<AbstractMediator,std::string>::_map = std::map<std::string,CreatorBase<AbstractMediator>*>();

std::vector<AbstractMediator *> MediatorBuilder::Create(const AbstractCommand * command){
	std::vector<AbstractMediator *> ret;
	const std::set<std::string> mediatorTypes = command->GetData()->GetMediatorTypes();
	std::set<std::string>::const_iterator it = mediatorTypes.cbegin();
	std::cout << "Creating mediators for data " << command->GetData()->Name() << std::endl;
	for( ; it != mediatorTypes.cend() ; ++it){
		// add in DataPool if needed
		if ( ! DataPool::Instance()->Contains(*it)){
			std::cout << "Instantiating mediator " << *it << std::endl;
			// delegate the mediator to DataPool
			DataPool::Instance()->Register(MediatorFactory::Create(*it));
			ret.push_back(DataPool::Instance()->GetMediator(*it));
		}
	}
	return ret;
}
