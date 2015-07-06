#include "AbstractCommand.h"
#include "AbstractData.hpp"

#include "assert.h"

/**
 *  Abstract command, use an AbstractData (facade) to access specified data from DataPool
 *  _Execute must be defined in sub class to implement real stuff ...
 **/
AbstractCommand::AbstractCommand(AbstractData * d):_d(d){

}

AbstractCommand::~AbstractCommand(){

}

bool AbstractCommand::Execute(){
	assert(_d!=0);
	return _Execute();
}
