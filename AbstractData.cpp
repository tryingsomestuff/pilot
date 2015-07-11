#include "AbstractData.hpp"

AbstractData::AbstractData(){

}

AbstractData::~AbstractData(){

}

void AbstractData::AddDepend(std::string m){
	_mediatorTypes.insert(m);
}

const std::set<std::string> AbstractData::GetMediatorTypes()const{
	return _mediatorTypes;
}