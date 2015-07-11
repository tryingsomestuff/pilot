#include "AbstractCommand.hpp"
#include "AbstractData.hpp"

#include "assert.h"

/**
 *  Abstract command, use an AbstractData (facade) to access specified data from DataPool
 *  _Execute must be defined in sub class to implement real stuff ...
 **/
AbstractCommand::AbstractCommand():_d(0){

}

AbstractCommand::~AbstractCommand(){

}

bool AbstractCommand::Execute(){
	assert(_d!=0);
	return _Execute();
}