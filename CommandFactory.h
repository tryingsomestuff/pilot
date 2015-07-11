#ifndef COMMAND_FACTORY__H
#define COMMAND_FACTORY__H

class AbstractCommand;
class AbstractData;

#include "AbstractFactory.hpp"

/**
 * Command creator
 **/
template <class DerivedType>
class CommandCreator : public Creator<DerivedType, AbstractCommand> {};

/**
 * Factory of command
 **/
typedef AbstractFactory<AbstractCommand,std::string> CommandFactory;

#endif // COMMAND_FACTORY__H
