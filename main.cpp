#include "pilot.h"

int main(int argc,char ** argv){
	std::vector<DataFactory::DataType> datas;
	std::vector<CommandFactory::CommandType> commands;
	datas.push_back(DataFactory::DT_1);
	commands.push_back(CommandFactory::CT_1);

	Pilot::RegisterMediators(datas);
	std::vector<AbstractCommand*> tasks = Pilot::Build(datas,commands);
	for(unsigned int k = 0 ; k < tasks.size(); ++k){
		tasks[k]->Execute();
	}
	return 0;
}
