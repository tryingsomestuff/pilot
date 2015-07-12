#include "AbstractCommand.hpp"
#include "AbstractData.hpp"

#include "assert.h"

AbstractCommand::AbstractCommand():_d(0){

}

AbstractCommand::~AbstractCommand(){
	if ( _d ){
		delete _d;
		_d=0;
	}
}

bool AbstractCommand::Execute(){
	// data is required for _Execute to work !
	if (! _d){
		std::cout << "Data pointer is requiered before executing a commands, use SetData" << std::endl;
		return false;
	}
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