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

bool Mediator2::_Init(){
  return true;
}
