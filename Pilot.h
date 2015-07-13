#ifndef PILOTE___H
#define PILOTE___H

#include <vector>

#include "Trait.hpp"

class Pilot{
public:
	Pilot();
	~Pilot();

	/**
	 * Tell the pilot the sequence of datas/commands that will be run
	 **/
	void AddTask(DataType datas, CommandType commands);

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

    std::vector<DataType>    _datasType;
	std::vector<CommandType> _commandsType;

	std::vector<AbstractCommand*> _commands;

}; // Pilot


#endif // PILOTE___H
