#include "CommandFactory.h"

// Must defined corresponding static members ...

/*
CommandFactory * CommandFactory::_instance = NULL;
*/

std::map<CommandFactory::DataType,CreatorBase<AbstractCommand>*> 
CommandFactory::_map = std::map<CommandFactory::DataType,CreatorBase<AbstractCommand>*>();
