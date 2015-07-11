#include "DataFactory.h"

class AbstractData;

// Must defined corresponding static members ...
/*
AbstractFactory<AbstractData,std::string> *
AbstractFactory<AbstractData,std::string>::_instance = NULL;
*/
std::map<std::string,CreatorBase<AbstractData>*> 
AbstractFactory<AbstractData,std::string>::_map = std::map<std::string,CreatorBase<AbstractData>*>();


