#include "Command2.h"
#include "Data2.h"

#include <stdlib.h>
#include <string>
#include <iostream>
#include <assert.h>

/**
 * A concrete Command using Data2 facade (
 **/

Command2::Command2():AbstractCommandBase(){

}

Command2::~Command2(){

}

bool Command2::_Execute(){
	Data2 * d = dynamic_cast<Data2*>(_d);
	assert(d!=0);
	std::cout << "Hello " << d->Id() << std::endl;
	std::cout << "Tata  " << d->Tata() << std::endl;
	std::cout << "Bli   " << d->Bli() << std::endl;

	return true;
}
