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
#include "AbstractCommand.hpp"

typedef unsigned int uint;

Pilot::Pilot(){}

Pilot::~Pilot(){
	for(unsigned int k = 0 ; k < _commands.size(); ++k){
		delete _commands[k];
	}
}

void Pilot::AddTask(DataType data, CommandType command){
	std::cout << "Adding task " << data << " : " << command << std::endl;
	_datasType.push_back(data);
	_commandsType.push_back(command);
}

AbstractCommand * Pilot::BuildOne(DataType data, CommandType command){
	// instanciate data
	AbstractData *    d = DataFactory::Create(data);
	if ( !d ){
		std::cout << "Error data not built" << std::endl;
		return NULL;
	}
	// instanciate Command
	AbstractCommand * c = CommandFactory::Create(command);
	if ( !c ){
		std::cout << "Error command not built" << std::endl;
		return NULL;
	}
	// link data with command and delegate ownership
	c->SetData(d);
	return c;
}

bool Pilot::Build(){
	std::cout << "Instanciating necessary commands and datas" << std::endl;
	assert(_datasType.size() == _commandsType.size());

	for(uint k = 0 ; k < _datasType.size() ; ++k){
		AbstractCommand * c = NULL;
		c = BuildOne(_datasType[k],_commandsType[k]);
		if ( !c ){
			return false;
		}
		// append to internal command list
		_commands.push_back(c);
	}
	return true;
}

void Pilot::RegisterMediators(){
	std::cout << "Registering mediators in DataPool" << std::endl;
	for(uint k = 0 ; k < _commands.size() ; ++k){
		// instanciate needed mediators
		MediatorBuilder::Create(_commands[k]);
	}
}

void Pilot::Execute(){
	std::cout << "Executing pilot" << std::endl;
	for(unsigned int k = 0 ; k < _commands.size(); ++k){
		_commands[k]->Execute();
	}
}

void Pilot::Read(std::string fileName){
	std::ifstream file(fileName.c_str());
	DataType dataType;
	CommandType commandType;
	while (file >> dataType >> commandType){
        AddTask(dataType,commandType);
    }
}

void Pilot::Execute(std::string filename){
	Read(filename);
	if ( ! Build()) return;
	RegisterMediators();
	Execute();
}
