#include "Mediator1.h"

/**
 *  A concrete mediator example.
 **/
Mediator1::Mediator1():AbstractMediatorBase<Mediator1>(){
	toto=0;
	tutu=1;
	bla = "coucou";
	eheh = false;
}

Mediator1::~Mediator1(){

}

bool Mediator1::_Init(){

  return true;
}
