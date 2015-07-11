#include "CommandFactory.h"

// Must defined corresponding static members ...

/*
AbstractFactory<AbstractCommand,std::string> *
AbstractFactory<AbstractCommand,std::string>::_instance = NULL;
*/

std::map<std::string,CreatorBase<AbstractCommand>*> 
AbstractFactory<AbstractCommand,std::string>::_map = std::map<std::string,CreatorBase<AbstractCommand>*>();
