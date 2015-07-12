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
	DataFactory::Register(TraitDataName<Data1>::Name(),new DataCreator<Data1>);
	DataFactory::Register(TraitDataName<Data2>::Name(),new DataCreator<Data2>); // won't be used...

	// Register all Command
	std::cout << "Registering Commands" << std::endl;
	CommandFactory::Register(TraitCommandName<Command1>::Name(),new CommandCreator<Command1>);

	// Register mediator
	std::cout << "Registering Mediators" << std::endl;
	MediatorFactory::Register(TraitMediatorName<Mediator1>::Name(), new MediatorCreator<Mediator1>);
	MediatorFactory::Register(TraitMediatorName<Mediator2>::Name(), new MediatorCreator<Mediator2>);

	///@todo from here a Pilot is needed
	// delegate commands and datas to Pilot ???

	// Indeed create those Datas and Commands
	std::cout << "Instanciating data and commands" << std::endl;
	std::vector<DataFactory::DataType> datas;
	std::vector<CommandFactory::DataType> commands;
	datas.push_back(TraitDataName<Data1>::Name());
	commands.push_back(TraitCommandName<Command1>::Name());

	std::vector<AbstractCommand*> tasks = Pilot::Build(datas,commands);

	std::cout << "Registering mediators in DataPool" << std::endl;

	// Build necessary mediators
	Pilot::RegisterMediators(tasks);
	
	std::cout << "Executing pilot" << std::endl;

	// Execute pilot :: Pilot.Execute();
	for(unsigned int k = 0 ; k < tasks.size(); ++k){
		tasks[k]->Execute();
	}

	// clean up ???

	return 0;
}
