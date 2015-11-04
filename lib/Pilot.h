#ifndef PILOTE___H
#define PILOTE___H

#include <vector>

#include "Trait.hpp"
#include "CommandContainer.h"

class Pilot{
public:
	Pilot();
	~Pilot();

	/**
	 * Add a data/command couple to the sequence that will be run
	 **/
	void AddTask(DataType data, CommandType command, const std::string & commandName);

	/**
	 * Will ask DataFactory and CommandFactory to instanciate object based on types "datas" and "commands"
	 * Expect _datasType and _commandsType vectors of same length with each facade corresponding to the command with same index.
	 **/
	bool Build();

	/**
	 * Will ask DataFactory and CommandFactory to instanciate object based on argument
	 * Return the constructed command.
	 **/
	static
	AbstractCommand * BuildOne(DataType data, CommandType command, const std::string & commandName);

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

	/**
	 * Direct access to container,
	 * ==> try not to use this unless really necessary <==
	 **/
	static
	inline
	CommandContainer & GetCommandContainer(){return _containerContainer;}

private:

    std::vector<DataType>    _datasType;
	std::vector<CommandType> _commandsType;
	std::vector<std::string> _commandsName;

	static CommandContainer _containerContainer; // shared for all instance ... Allow quite strange coupling stuff

}; // Pilot


#endif // PILOTE___H
