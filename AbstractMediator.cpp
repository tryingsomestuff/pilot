#include "AbstractMediator.hpp"

AbstractMediator::AbstractMediator():_status(AbstractMediator::M_NOT_READY){
	
}

AbstractMediator::~AbstractMediator(){

}

AbstractMediator::M_Status AbstractMediator::Status()const{
	return _status;
}

bool
AbstractMediator::Init(){
	std::cout << "Initializing mediator " << _id << std::endl;
	_status = M_READY;
	return _Init();
}