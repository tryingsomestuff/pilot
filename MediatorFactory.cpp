#include "MediatorFactory.h"
#include "TraitMediator.hpp"
#include "DataPool.h"

#include "Mediator1.h"
#include "Mediator2.h"

std::vector<AbstractMediator *> MediatorFactory::Create(DataFactory::DataType type){
	switch(type){
		case DataFactory::DT_0:
			std::cout << "Error type not defined" << std::endl;
			break;
		case DataFactory::DT_1:
			{
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
		case DataFactory::DT_2:
			std::cout << "Error non implemented" << std::endl;
			break;
		default:
			std::cout << "Error type unknown" << std::endl;
			break;
	}
	return std::vector<AbstractMediator *> ();
}
