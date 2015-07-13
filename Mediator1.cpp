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

AbstractMediator::M_Status Mediator1::Status()const{
  return M_READY;
}

bool Mediator1::Init(){

  return true;
}
