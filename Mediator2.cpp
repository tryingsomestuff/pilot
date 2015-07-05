#include "Mediator2.h"

/**
 *  Another concrete mediator example.
 **/
Mediator2::Mediator2():AbstractMediatorBase<Mediator2>(){
	toto=3.14;
	truc=14;
	blabla="youpi";
	b = true;
}

Mediator2::~Mediator2(){

}

AbstractMediator::M_Status Mediator2::Status(){
  return M_READY;
}

bool Mediator2::Init(){
  return true;
}
