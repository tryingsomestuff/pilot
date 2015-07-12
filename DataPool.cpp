#include "DataPool.h"
#include "Trait.hpp"
#include "AbstractMediator.hpp"
#include "MediatorFactory.h"

#include <stdlib.h>
#include <string>
#include <iostream>
#include <assert.h>

typedef std::map<MediatorFactory::DataType,AbstractMediator *>::iterator _m_it;

DataPool::~DataPool(){
	_m_it it = _mediators.begin();
	for ( ; it != _mediators.end(); ++it){
		delete it->second;
		it->second = NULL;
	}
}

DataPool * DataPool::Instance(){
	if( ! _pool ){
		_pool = new DataPool();
	}
	return _pool;
}

// Delegate mediator to DataPool
void DataPool::Register(AbstractMediator * mediator){
	assert(mediator!=0);
	if ( GetMediator(mediator->Id()) != NULL ){
		std::cout << "Mediator already present in DataPool" << std::endl;
		// HORRIBLE !!!
		// just pay the cost of instanciation and delete it right now !!!
		// Shall never append anyway...
		delete mediator;
		return;
	}
	std::cout << "Registering mediator " << mediator->Id() << std::endl;
	_mediators[mediator->Id()] = mediator;
}

AbstractMediator * DataPool::GetMediator(MediatorFactory::DataType type){
	if ( _mediators.find( type ) != _mediators.end() ){
		return _mediators[type];
	}
	else{
		return NULL;
	}
}

bool DataPool::Contains(MediatorFactory::DataType type){
    return GetMediator(type)!=NULL;
}

DataPool * DataPool::_pool = NULL;
