#include "MediatorFactory.h"
#include "Trait.hpp"
#include "DataPool.h"

#include "DataFactory.h"
#include "AbstractCommand.hpp"
#include "AbstractData.hpp"

#include <string>
#include <set>

/**
 * Factory of command
 **/
// Must defined corresponding static members ...

/*
AbstractFactory<AbstractMediator,std::string> *
AbstractFactory<AbstractMediator,std::string>::_instance = NULL;
*/

std::map<std::string,CreatorBase<AbstractMediator>*> 
AbstractFactory<AbstractMediator,std::string>::_map = std::map<std::string,CreatorBase<AbstractMediator>*>();


///@TODO SHALL KNOW NOTHING ABOUT DATA1 !!!!!!
// so STATIC data1 shall already know the list of mediator needed !

std::vector<AbstractMediator *> MediatorBuilder::Create(const AbstractCommand * command){

	std::vector<AbstractMediator *> ret;

	const std::set<std::string> mediatorTypes = command->GetData()->GetMediatorTypes();
	std::set<std::string>::const_iterator it = mediatorTypes.cbegin();
	std::cout << "Creating mediators for data " << command->GetData()->Name() << std::endl;
	for( ; it != mediatorTypes.cend() ; ++it){
		if ( ! DataPool::Instance()->Contains(*it)){
			std::cout << "Instantiating mediator " << *it << std::endl;
			DataPool::Instance()->Register(MediatorFactory::Create(*it));
			ret.push_back(DataPool::Instance()->GetMediator(*it));
		}
	}

	return ret;
}
