#ifndef PILOTE___H
#define PILOTE___H

#include <vector>

#include "Trait.hpp"

class Pilot{
public:
	Pilot();
	~Pilot();

	/**
	 * Add a data/command couple to the sequence that will be run
	 **/
	void AddTask(DataType datas, CommandType commands);

	/**
	 * Will ask DataFactory and CommandFactory to instanciate object based on types "datas" and "commands"
	 * Expect _datasType and _commandsType vectors of same length with each facade corresponding to the command with same index.
	 **/
	bool Build();

	/**
	 * Register all needed mediators for given DataTypes
	 * Meditors needed for each data type is known so that
	 * we can build up all the required meditors.
	 * After being constructed, mediators are Register to DataPool
	 * and then initialized.
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
