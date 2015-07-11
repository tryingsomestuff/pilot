#include "Pilot.h"

#include "Data1.h"
#include "Data2.h"

#include "Command1.h"

#include <string>

int main(int argc,char ** argv){

	//Register all Data ...
	DataFactory::Instance()->Register(TraitDataName<Data1>::Name(),new DataCreator<Data1>);
	DataFactory::Instance()->Register(TraitDataName<Data2>::Name(),new DataCreator<Data2>);

	CommandFactory::Instance()->Register(TraitCommandName<Command1>::Name(),new CommandCreator<Command1>);

	std::vector<DataFactory::DataType> datas;
	std::vector<CommandFactory::DataType> commands;
	datas.push_back(TraitDataName<Data1>::Name());
	commands.push_back(TraitCommandName<Command1>::Name());

	Pilot::RegisterMediators(datas);
	std::vector<AbstractCommand*> tasks = Pilot::Build(datas,commands);
	for(unsigned int k = 0 ; k < tasks.size(); ++k){
		tasks[k]->Execute();
	}
	return 0;
}
