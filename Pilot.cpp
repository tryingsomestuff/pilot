#include <vector>
#include <map>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>

#include "Pilot.h"
#include "MediatorFactory.h"
#include "AbstractMediator.hpp"

typedef unsigned int uint;

Pilot::Pilot(){}

Pilot::~Pilot(){
	for(unsigned int k = 0 ; k < _commands.size(); ++k){
		delete _commands[k];
	}
}


void Pilot::AddTask(DataFactory::DataType data, CommandFactory::DataType command){
	std::cout << "Adding task " << data << " : " << command << std::endl;
	_datasType.push_back(data);
	_commandsType.push_back(command);
}


bool Pilot::Build(){
	std::cout << "Registering mediators in DataPool" << std::endl;

	assert(_datasType.size() == _commandsType.size());

	for(uint k = 0 ; k < _datasType.size() ; ++k){
		// instanciate data
		AbstractData *    d = DataFactory::Create(_datasType[k]);
		if ( !d ){
			std::cout << "Error data not built" << std::endl;
			return false;
		}
		// instanciate Command
		AbstractCommand * c = CommandFactory::Create(_commandsType[k]);
		// link data with command and delegate ownership
		c->SetData(d);
		if ( !c ){
			std::cout << "Error command not built" << std::endl;
			return false;
		}
		// append to internal command list
		_commands.push_back(c);
	}
	return true;
}

void Pilot::RegisterMediators(){
	for(uint k = 0 ; k < _commands.size() ; ++k){
		// instanciate needed mediators
		std::vector<AbstractMediator*> mediators = MediatorBuilder::Create(_commands[k]);
		for (uint m = 0 ; m < mediators.size(); ++m){
			std::cout << std::string("Init mediator ") + mediators[m]->Name() << std::endl;
			if ( ! mediators[m]->Init() ){
				std::cout << std::string("Fail to init mediator ") + mediators[m]->Name() << std::endl;
			}
		}
	}
}

void Pilot::Execute(){
	std::cout << "Executing pilot" << std::endl;
	for(unsigned int k = 0 ; k < _commands.size(); ++k){
		_commands[k]->Execute();
	}
}

void Pilot::Read(std::string fileName){
	std::ifstream file(fileName);
    std::string dataType,commandType;
	while (file >> dataType >> commandType){
        AddTask(dataType,commandType);       
    }
}

void Pilot::Execute(std::string filename){
	Read(filename);
	Build();
	RegisterMediators();
	Execute();
}
