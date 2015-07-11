#ifndef COMMAND_FACTORY__H
#define COMMAND_FACTORY__H

class AbstractCommand;
class AbstractData;

#include "AbstractFactory.hpp"

/**
 * Factory of command
 **/
template <class DerivedType>
class CommandCreator : public Creator<DerivedType, AbstractCommand> {};

typedef AbstractFactory<AbstractCommand,std::string> CommandFactory;

/*
class CommandFactory{
	public:
		enum CommandType{
			CT_0 = 0, // forbidden
			CT_1 = 1,
			CT_2 = 2,
			CT_MAX = 2
		};
		static AbstractCommand * Create(AbstractData * d, CommandType type);
};
*/

#endif // COMMAND_FACTORY__H
