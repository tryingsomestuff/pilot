#include "DataPool.h"
#include "Trait.hpp"
#include "AbstractMediator.hpp"

#include <stdlib.h>
#include <string>
#include <iostream>
#include <assert.h>

typedef std::map<std::string,AbstractMediator *>::iterator _m_it;

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
	if ( GetMediator(mediator->Name()) != NULL ){
		std::cout << "Mediator already present in DataPool" << std::endl;
		// HORRIBLE !!!
		// just pay the cost of instanciation and delete it right now !!!
		// Shall never append anyway...
		delete mediator;
		return;
	}
	std::cout << std::string("Registering mediator ") << mediator->Name() << std::endl;
	_mediators[mediator->Name()] = mediator;
}

AbstractMediator * DataPool::GetMediator(std::string name){
	if ( _mediators.find( name ) != _mediators.end() ){
		return _mediators[name];
	}
	else{
		return NULL;
	}
}

bool DataPool::Contains(std::string name){
    return GetMediator(name)!=NULL;
}

DataPool * DataPool::_pool = NULL;
