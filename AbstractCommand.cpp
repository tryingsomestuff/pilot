#include "AbstractCommand.hpp"
#include "AbstractData.hpp"

#include "assert.h"

AbstractCommand::AbstractCommand():_d(0),_n(0){

}

AbstractCommand::~AbstractCommand(){
	if ( _d ){
		delete _d;
		_d=0;
	}
}

void AbstractCommand::SetData(AbstractData * d){
	_d=d;
}

AbstractData * AbstractCommand::GetData(){
	return _d;
}

const AbstractData * AbstractCommand::GetData()const{
	if (! _d){
		std::cout << "WARNING :: Data pointer is not set yet, use SetData" << std::endl;
		return NULL;
	}
	return _d;
}

void AbstractCommand::SetNext(AbstractCommand * c){
	_n = c;
}
