#include "Data1.h"

#include "Trait.hpp"
#include "DataPool.h"
#include "AbstractData.hpp"

#include "Mediator1.h"
#include "Mediator2.h"

#include <assert.h>

/**
 *  A concrete facade to DataPool singleton container
 **/
Data1::Data1():AbstractDataBase(){
	// add denpendancy on required mediators
	AddDepend(TraitMediatorName<Mediator1>::Name());
	AddDepend(TraitMediatorName<Mediator2>::Name());
}

Data1::~Data1(){

}

double Data1::Toto(){
	Mediator2 * med = dynamic_cast<Mediator2*>(DataPool::Instance()->GetMediator(TraitMediatorName<Mediator2>::Name()));
	assert(med!=0);
	return med->toto;
}

std::string Data1::Bla() {
	Mediator1 * med = dynamic_cast<Mediator1*>(DataPool::Instance()->GetMediator(TraitMediatorName<Mediator1>::Name()));
	assert(med!=0);
	return med->bla;
}
