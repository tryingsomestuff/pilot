#include "DataFactory.h"

// Must defined corresponding static members ...

/*
DataFactory * DataFactory::_instance = NULL;
*/

std::map<DataFactory::DataType,CreatorBase<AbstractData>*> 
DataFactory::_map = std::map<DataFactory::DataType,CreatorBase<AbstractData>*>();


