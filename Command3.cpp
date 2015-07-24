#include "Command3.h"
#include "Command1.h"
#include "Data1.h"

#include <string>
#include <iostream>
#include <assert.h>

/**
 * A concrete Command using Data1 facade (mix of Mediator1 and Mediator2)
 **/

Command3::Command3(AbstractData *d, AbstractCommand * n):AbstractCommandBase<Command3>(d,n){
    this->SetNext(new Command1(DataFactory::Create(TraitDataId<Data1>::Id())));
}

Command3::~Command3(){

}

bool Command3::_Execute(){
    std::cout << "-- Execute 3" << std::endl;
	Data1 * d = dynamic_cast<Data1*>(_d);
	assert(d!=0);
	std::cout << "Hello " << d->Id() << std::endl;
	std::cout << "Toto  " << d->Toto() << std::endl;
	std::cout << "Bla   " << d->Bla() << std::endl;

	return true;
}