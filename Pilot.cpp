#include <vector>
#include <map>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <assert.h>

#include "Pilot.h"
#include "MediatorFactory.h"
#include "AbstractMediator.hpp"

namespace Pilot{

	typedef unsigned int uint;

	/**
	 * Abstract Pilot builder ...
	 **/
	std::vector<AbstractCommand*> Build(std::vector<DataFactory::DataType> datas, std::vector<CommandFactory::DataType> commands){
		assert(datas.size() == commands.size());
		std::vector<AbstractCommand*> ret;
		for(uint k = 0 ; k < datas.size() ; ++k){
			AbstractData *    d = DataFactory::Create(datas[k]);
			if ( !d ){
				std::cout << "Error data not built" << std::endl;
				return std::vector<AbstractCommand*>();
			}
			AbstractCommand * c = CommandFactory::Create(commands[k]);
			c->SetData(d);
			if ( !c ){
				std::cout << "Error command not built" << std::endl;
				return std::vector<AbstractCommand*>();
			}
			ret.push_back(c);
		}
		return ret;
	}

	/**
	 * Register all needed mediators for a given DataType
	 **/
	void RegisterMediators(std::vector<DataFactory::DataType> datas){
		for(uint k = 0 ; k < datas.size() ; ++k){
			std::vector<AbstractMediator*> mediators = MediatorFactory::Create(datas[k]);
			for (uint m = 0 ; m < mediators.size(); ++m){
				std::cout << std::string("Init mediator ") + mediators[m]->Name() << std::endl;
				if ( ! mediators[m]->Init() ){
					std::cout << std::string("Fail to init mediator ") + mediators[m]->Name() << std::endl;
				}
			}
		}
	}
} // Pilot
