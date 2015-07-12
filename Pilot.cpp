#include <vector>
#include <map>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <assert.h>

#include "Pilot.h"
#include "MediatorFactory.h"
#include "AbstractMediator.hpp"

typedef unsigned int uint;

std::vector<AbstractCommand*> Pilot::Build(std::vector<DataFactory::DataType> datas, std::vector<CommandFactory::DataType> commands){
	assert(datas.size() == commands.size());

	std::vector<AbstractCommand*> ret;
	for(uint k = 0 ; k < datas.size() ; ++k){
		// instanciate data
		AbstractData *    d = DataFactory::Create(datas[k]);
		if ( !d ){
			std::cout << "Error data not built" << std::endl;
			return std::vector<AbstractCommand*>();
		}
		// instanciate Command
		AbstractCommand * c = CommandFactory::Create(commands[k]);
		// link data with command
		c->SetData(d);
		if ( !c ){
			std::cout << "Error command not built" << std::endl;
			return std::vector<AbstractCommand*>();
		}
		ret.push_back(c);
	}
	return ret;
}

void Pilot::RegisterMediators(std::vector<AbstractCommand *> commands){
	for(uint k = 0 ; k < commands.size() ; ++k){
		// instanciate needed mediators
		std::vector<AbstractMediator*> mediators = MediatorBuilder::Create(commands[k]);
		for (uint m = 0 ; m < mediators.size(); ++m){
			std::cout << std::string("Init mediator ") + mediators[m]->Name() << std::endl;
			if ( ! mediators[m]->Init() ){
				std::cout << std::string("Fail to init mediator ") + mediators[m]->Name() << std::endl;
			}
		}
	}
}

