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

// shared
CommandContainer Pilot::_containerContainer;

Pilot::Pilot(){}

Pilot::~Pilot(){}

void Pilot::AddTask(DataType data, CommandType command, const std::string & commandName){
	Logger::Instance() << "Adding task " << data << " : " << command;
	_datasType.push_back(data);
	_commandsType.push_back(command);
	_commandsName.push_back(commandName);
}

AbstractCommand * Pilot::BuildOne(DataType data, CommandType command, const std::string & commandName){
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
	// append to container (take ownership, will be deleted automatically)
    _containerContainer.Set(commandName,c);	
	return c;
}

bool Pilot::Build(){
	Logger::Instance() << "Instanciating necessary commands and datas";
	assert(_datasType.size() == _commandsType.size());
	assert(_datasType.size() == _commandsName.size());

	for(uint k = 0 ; k < _datasType.size() ; ++k){
		AbstractCommand * c = BuildOne(_datasType[k],_commandsType[k],_commandsName[k]);
		if ( !c ){
			return false;
		}
		// append to main stream
		if ( ! _containerContainer.AddToMainStream(_commandsName[k]) ){
		   return false; // should impossible here ... anyway ...
		}
	}
	return true;
}

void Pilot::RegisterMediators(){
	Logger::Instance() << "Registering mediators in DataPool";
	///@todo better with a pretty iterator :-)
	std::vector<AbstractCommand*> v = GetCommandContainer().GetMainStream();
	for(uint k = 0 ; k < v.size() ; ++k){
		// instanciate needed mediators
		MediatorBuilder::Create(v[k], false); // force mediator init on the fly
	}
}

void Pilot::Execute(){
	Logger::Instance() << "Executing pilot";
	///@todo better with a pretty iterator :-)
	std::vector<AbstractCommand*> v = GetCommandContainer().GetMainStream();
	for(unsigned int k = 0 ; k < v.size(); ++k){
		v[k]->Execute();
	}
}

void Pilot::Read(std::string fileName){
	std::ifstream file(fileName.c_str());
	DataType dataType;
	CommandType commandType;
	std::string commandName;
	while (file >> dataType >> commandType >> commandName ){
        AddTask(dataType,commandType,commandName);
    }
}

void Pilot::Execute(std::string filename){
	Read(filename);
	if ( ! Build()) return;
	RegisterMediators();
	Execute();
}
