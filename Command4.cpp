#include "Command4.h"
#include "Data1.h"

#include <string>
#include <iostream>
#include <assert.h>

/**
 * A concrete Command using Data1 facade (mix of Mediator1 and Mediator2)
 **/

Command4::Command4(AbstractData *d, AbstractCommand * n):AbstractCommandBase<Command4>(d,n){
}

Command4::~Command4(){

}

bool Command4::_Execute(){
    std::cout << "-- Execute 4" << std::endl;
	return true;
}
