#include "DataFactory.h"
#include "AbstractData.hpp"

#include <iostream>
#include <string>

/**
 *  Factory of facade
 **/
// Must defined corresponding static members ...
/*
AbstractFactory<AbstractData,std::string> *
AbstractFactory<AbstractData,std::string>::_instance = NULL;
*/
std::map<std::string,CreatorBase<AbstractData>*> 
AbstractFactory<AbstractData,std::string>::_map = std::map<std::string,CreatorBase<AbstractData>*>();


