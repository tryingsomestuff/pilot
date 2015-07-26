#include "Command3.h"
#include "Command1.h"
#include "Command4.h"
#include "Data1.h"
#include "Data4.h"
#include "Pilot.h"

#include <string>
#include <iostream>
#include <assert.h>

/**
 * A concrete Command using Data1 facade (mix of Mediator1 and Mediator2)
 **/

Command3::Command3(AbstractData *d, AbstractCommand * n):AbstractCommandBase<Command3>(d,n){
	// add a fully new command / data
    DataFactoryTools::Register<Data4>();
	CommandFactoryTools::Register<Command4>();
	AbstractCommand * c4 = Pilot::BuildOne(TraitDataId<Data4>::Id(),TraitCommandId<Command4>::Id());
	MediatorBuilder::Create(c4); // not needed here for Data4, just for fun ...

	this->SetNext(c4);

	// add an existing command to the next next...
    c4->SetNext(new Command1(DataFactory::Create(TraitDataId<Data1>::Id())));

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
