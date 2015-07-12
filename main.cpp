#include "Pilot.h"

#include "Data1.h"
#include "Data2.h"

#include "Command1.h"

#include "Mediator1.h"
#include "Mediator2.h"

#include <string>

int main(int argc,char ** argv){

	// Register all Data ...
	std::cout << "Registering Datas" << std::endl;
	DataFactoryTools::Register<Data1>();
	DataFactoryTools::Register<Data2>();

	// Register all Command
	std::cout << "Registering Commands" << std::endl;
	CommandFactoryTools::Register<Command1>();

	// Register mediator
	std::cout << "Registering Mediators" << std::endl;
	MediatorFactoryTools::Register<Mediator1>();
	MediatorFactoryTools::Register<Mediator2>();

	// shall become pilot.Read(json);
	std::vector<DataFactory::DataType> datas;
	std::vector<CommandFactory::DataType> commands;
	datas.push_back(TraitDataName<Data1>::Name());
	commands.push_back(TraitCommandName<Command1>::Name());

	Pilot pilot;
	// just give the datas/commands list to pilot
	pilot.AddTasks(datas,commands);
	// effectively create datas and commands
	pilot.Build();
	// Build necessary mediators
	pilot.RegisterMediators();
	// Execute pilot
	pilot.Execute();

	return 0;
}
