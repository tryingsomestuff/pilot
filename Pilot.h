#ifndef PILOTE___H
#define PILOTE___H

#include <vector>

#include "AbstractCommand.h" // NOT a forward decl because this is the main entry point header ...
#include "DataFactory.h"
#include "CommandFactory.h"

namespace Pilot{
	/**
	 * Abstract Pilot builder ...
	 **/
	std::vector<AbstractCommand*>
	Build(std::vector<DataFactory::DataType> datas, std::vector<CommandFactory::CommandType> commands);

	/**
	 * Register all needed mediators for a given DataType
	 **/
	void
	RegisterMediators(std::vector<DataFactory::DataType> datas);
} // Pilot


#endif // PILOTE___H
