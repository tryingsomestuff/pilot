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
// previous line defines CommandFactory::KeyType as std::string
typedef CommandFactory::KeyType CommandType;

// late include is MANDATORY
#include "Trait.hpp"

/**
 *  Shortcut for specific register
 **/
namespace CommandFactoryTools{
template <class DerivedType>
void Register(){
   CommandFactory::Register(TraitCommandId<DerivedType>::Id(),new CommandCreator<DerivedType>);
}
} // CommandFactoryTools

#endif // COMMAND_FACTORY__H
