#include "DataFactory.h"
#include "AbstractData.h"

#include "Data1.h"

#include <iostream>

/**
 *  Factory of facade
 **/
AbstractData * DataFactory::Create(DataType type){
	switch(type){
		case DT_0:
			std::cout << "Error type not defined" << std::endl;
			break;
		case DT_1:
			std::cout << "Creating a Data1" << std::endl;
			return new Data1();
		case DT_2:
			std::cout << "Error non implemented" << std::endl;
			break;
		default:
			std::cout << "Error type unknown" << std::endl;
			break;
	}
	return NULL;
}
