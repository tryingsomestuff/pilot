#include "Pilot.h"

#include "Data1.h"
#include "Data2.h"

#include "Command1.h"
#include "Command2.h"

#include "Mediator1.h"
#include "Mediator2.h"

#include <string>

/**
 * The user is responsible for registering 
 * needed type of datas, commands and mediator to 
 * the corresponding factories !
 **/ 
void RegisterToFactories(){
	// Register all Data ...
	std::cout << "Registering Datas" << std::endl;
	DataFactoryTools::Register<Data1>();
	DataFactoryTools::Register<Data2>();

	// Register all Command
	std::cout << "Registering Commands" << std::endl;
	CommandFactoryTools::Register<Command1>();
    CommandFactoryTools::Register<Command2>();

	// Register mediator
	std::cout << "Registering Mediators" << std::endl;
	MediatorFactoryTools::Register<Mediator1>();
	MediatorFactoryTools::Register<Mediator2>();
}

int main(int argc,char ** argv){

	RegisterToFactories();

	Pilot pilot;
	// read datas/commands from input file
	pilot.Read("../../tasks.txt");
	// effectively create datas and commands
	pilot.Build();
	// Build necessary mediators
	pilot.RegisterMediators();
	// Execute pilot
	pilot.Execute();

	return 0;
}
