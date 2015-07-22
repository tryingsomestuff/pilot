#include "Command1.h"
#include "Data1.h"

#include <string>
#include <iostream>
#include <assert.h>

/**
 * A concrete Command using Data1 facade (mix of Mediator1 and Mediator2)
 **/

Command1::Command1(AbstractData *d, AbstractCommand * n):AbstractCommandBase<Command1>(d,n){

}

Command1::~Command1(){

}

bool Command1::_Execute(){
    std::cout << "-- Execute 1" << std::endl;
	Data1 * d = dynamic_cast<Data1*>(_d);
	assert(d!=0);
	std::cout << "Hello " << d->Id() << std::endl;
	std::cout << "Toto  " << d->Toto() << std::endl;
	std::cout << "Bla   " << d->Bla() << std::endl;

	return true;
}
