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
	Logger::Instance() << "Adding task " << data << " : " << command;
	_datasType.push_back(data);
	_commandsType.push_back(command);
}

AbstractCommand * Pilot::BuildOne(DataType data, CommandType command){
	// instanciate data
	AbstractData *    d = DataFactory::Create(data);
	if ( !d ){
		Logger::Instance() << "Error data not built";
		return NULL;
	}
	// instanciate Command
	AbstractCommand * c = CommandFactory::Create(command);
	if ( !c ){
		Logger::Instance() << "Error command not built";
		return NULL;
	}
	// link data with command and delegate ownership
	c->SetData(d);
	return c;
}

bool Pilot::Build(){
	Logger::Instance() << "Instanciating necessary commands and datas";
	assert(_datasType.size() == _commandsType.size());

	for(uint k = 0 ; k < _datasType.size() ; ++k){
		AbstractCommand * c = BuildOne(_datasType[k],_commandsType[k]);
		if ( !c ){
			return false;
		}
		// append to internal command list
		_commands.push_back(c);
	}
	return true;
}

void Pilot::RegisterMediators(){
	Logger::Instance() << "Registering mediators in DataPool";
	for(uint k = 0 ; k < _commands.size() ; ++k){
		// instanciate needed mediators
		MediatorBuilder::Create(_commands[k], false); // force mediator init on the fly
	}
}

void Pilot::Execute(){
	Logger::Instance() << "Executing pilot";
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
