#include "AbstractMediator.hpp"
#include "Logger.hpp"

AbstractMediator::AbstractMediator():_status(AbstractMediator::M_NOT_READY){
	
}

AbstractMediator::~AbstractMediator(){

}

AbstractMediator::M_Status AbstractMediator::Status()const{
	return _status;
}

bool
AbstractMediator::Init(){
	Logger::Instance() << "Initializing mediator " << _id;
	_status = M_READY;
	return _Init();
}