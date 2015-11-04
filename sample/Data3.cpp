#include "Data3.h"

#include "Trait.hpp"
#include "DataPool.hpp"
#include "AbstractData.hpp"

#include "Mediator1.h"
#include "Mediator2.h"

#include <assert.h>

/**
 *  A concrete facade to DataPool singleton container
 **/
Data3::Data3():AbstractDataBase<Data3>(){
	// add denpendancy on required mediators
	AddDepend(TraitMediatorId<Mediator1>::Id());
	AddDepend(TraitMediatorId<Mediator2>::Id());
}

Data3::~Data3(){

}

double Data3::Toto(){
	Mediator2 * med = SafeMediatorAccess<Mediator2>();
	assert(med!=0);
	return med->toto;
}

std::string Data3::Bla() {
	Mediator1 * med = SafeMediatorAccess<Mediator1>();
	assert(med!=0);
	return med->bla;
}
