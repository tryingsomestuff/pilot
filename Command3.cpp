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
	// add a fully new command / data couple
    DataFactoryTools::Register<Data4>();
	CommandFactoryTools::Register<Command4>();
	AbstractCommand * c4 = Pilot::BuildOne(TraitDataId<Data4>::Id(),TraitCommandId<Command4>::Id(),"My command 4");
	MediatorBuilder::Create(c4); // not needed here for Data4, just for fun ...
	this->SetNext(c4);

	// manually add an already registered command to the next next...
	// No need to register to factory
	// BUT need to add it in CommandContainer
	AbstractCommand * c1 = new Command1(DataFactory::Create(TraitDataId<Data1>::Id()));
    c4->SetNext(c1);
    Pilot::GetCommandContainer().Set("other command1",c1);

	// manually add an existing command to the next next next ...
	// No need to register to factory
	// No need to add it in CommandContainer
	AbstractCommand * c11 = Pilot::GetCommandContainer().Get("c2");
	if ( c11 ){
       c1->SetNext(c11);
	}
	else{
	    Logger::Instance() << "Error command not found";
	}

}

Command3::~Command3(){

}

bool Command3::_Execute(){
    Logger::Instance() << "-- Execute 3";
	Data1 * d = dynamic_cast<Data1*>(_d);
	assert(d!=0);
	Logger::Instance() << "Hello " << d->Id();
	Logger::Instance() << "Toto  " << d->Toto();
	Logger::Instance() << "Bla   " << d->Bla();

	return true;
}
