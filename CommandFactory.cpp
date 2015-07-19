#include "CommandFactory.h"

// Must defined corresponding static members ...

/*
template<>
CommandFactory * CommandFactory::_instance = NULL;
*/

template<>
std::map<CommandType,CreatorBase<AbstractCommand>*>
CommandFactory::_map = std::map<CommandType,CreatorBase<AbstractCommand>*>();
