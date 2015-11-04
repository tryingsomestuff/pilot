#include "AbstractData.hpp"

AbstractData::AbstractData(){

}

AbstractData::~AbstractData(){

}

void AbstractData::AddDepend(MediatorType m){
	_mediatorTypes.insert(m);
}

const std::set<MediatorType> AbstractData::GetMediatorTypes()const{
	return _mediatorTypes;
}