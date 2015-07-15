#include "Data2.h"

#include "Trait.hpp"
#include "DataPool.h"
#include "AbstractData.hpp"

#include "Mediator1.h"
#include "Mediator2.h"

#include <assert.h>

/**
 *  A concrete facade to DataPool singleton container
 **/
Data2::Data2():AbstractDataBase<Data2>(){

}

Data2::~Data2(){

}

double Data2::Tata(){
	return 1.414;
}

std::string Data2::Bli(){
	return "plop";
}
