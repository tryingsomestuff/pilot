#include "MediatorFactory.h"
#include "Trait.hpp"
#include "DataPool.h"

#include "Mediator1.h"
#include "Mediator2.h"

#include "Data1.h"
#include "DataFactory.h"

#include <string>

std::vector<AbstractMediator *> MediatorFactory::Create(DataFactory::DataType type){

	if ( type == TraitDataName<Data1>::Name() ){
		std::cout << "Registering mediators for Data1" << std::endl;
		std::vector<AbstractMediator *> ret;
		// this one needs interact with two mediators ...
		if ( ! DataPool::Instance()->Contains(TraitMediatorName<Mediator1>::Name()) ){
			DataPool::Instance()->Register(new Mediator1());
			ret.push_back(DataPool::Instance()->GetMediator(TraitMediatorName<Mediator1>::Name()));
		}
		if ( ! DataPool::Instance()->Contains(TraitMediatorName<Mediator2>::Name()) ){
			DataPool::Instance()->Register(new Mediator2());
			ret.push_back(DataPool::Instance()->GetMediator(TraitMediatorName<Mediator2>::Name()));
		}
		return ret;
	}
	std::cout << "Error type not defined" << std::endl;
	return std::vector<AbstractMediator *> ();
}
