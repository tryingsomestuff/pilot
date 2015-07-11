#include "AbstractCommand.hpp"
#include "AbstractData.hpp"

#include "assert.h"

AbstractCommand::AbstractCommand():_d(0){

}

AbstractCommand::~AbstractCommand(){

}

bool AbstractCommand::Execute(){
	// data is required for _Execute to work !
	assert(_d!=0);
	return _Execute();
}

void AbstractCommand::SetData(AbstractData * d){
	_d=d;
}

AbstractData * AbstractCommand::GetData(){
	return _d;
}

const AbstractData * AbstractCommand::GetData()const{
	return _d;
}