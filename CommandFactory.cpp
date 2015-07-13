#include "CommandFactory.h"

// Must defined corresponding static members ...

/*
CommandFactory * CommandFactory::_instance = NULL;
*/

std::map<CommandType,CreatorBase<AbstractCommand>*> 
CommandFactory::_map = std::map<CommandType,CreatorBase<AbstractCommand>*>();
