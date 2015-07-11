#ifndef PILOTE___H
#define PILOTE___H

#include <vector>

#include "AbstractCommand.hpp" // NOT a forward decl because this is the main entry point header ...
#include "DataFactory.h"
#include "CommandFactory.h"
#include "Trait.hpp"

namespace Pilot{
	/**
	 * Abstract Pilot builder ...
	 **/
	std::vector<AbstractCommand*>
	Build(std::vector<DataFactory::DataType> datas, std::vector<CommandFactory::DataType> commands);

	/**
	 * Register all needed mediators for a given DataType
	 **/
	void
	RegisterMediators(std::vector<AbstractCommand *> datas);
} // Pilot


#endif // PILOTE___H
