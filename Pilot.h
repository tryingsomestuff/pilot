#ifndef PILOTE___H
#define PILOTE___H

#include <vector>

#include "AbstractCommand.hpp" // NOT a forward decl because this is the main entry point header ...
#include "DataFactory.h"
#include "CommandFactory.h"
#include "Trait.hpp"

class Pilot{
public:
	Pilot();
	~Pilot();

	/**
	 * Tell the pilot the sequence of datas/commands that will be run
	 **/
	void AddTask(DataFactory::DataType datas, CommandFactory::DataType commands);

	/**
	 * Abstract Pilot builder ...
	 * Will ask DataFactory and CommandFactory to instanciate object based on types "datas" and "commands"
	 * Expect vetor of same length with each facade corresponding to the command with same index.
	 **/
	bool Build();

	/**
	 * Register all needed mediators for given DataTypes
	 * Meditors needed for each data type is know so that
	 * we can build up all the required meditors.
	 **/
	void RegisterMediators();

	/**
	 * Execute all commands in there registering order
	 * well ... FIFO ...
	 **/
	void Execute();

	/**
	 * Read a pilot command file
	 **/
	void Read(std::string fileName);

	/**
	 * ALL IN ONE 
	 * Execute all commands in there registering order
	 * well ... FIFO ...
	 **/
	void Execute(std::string filename);


private:

    std::vector<DataFactory::DataType>    _datasType;
	std::vector<CommandFactory::DataType> _commandsType;

	std::vector<AbstractCommand*> _commands;

}; // Pilot


#endif // PILOTE___H
