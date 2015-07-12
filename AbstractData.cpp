#include "AbstractData.hpp"

AbstractData::AbstractData(){

}

AbstractData::~AbstractData(){

}

void AbstractData::AddDepend(MediatorFactory::DataType m){
	_mediatorTypes.insert(m);
}

const std::set<MediatorFactory::DataType> AbstractData::GetMediatorTypes()const{
	return _mediatorTypes;
}