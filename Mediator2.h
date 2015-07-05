#ifndef MEDIATOR__2___H
#define MEDIATOR__2___

#include "AbstractMediator.hpp"

#include <iostream>

/**
 *  Another concrete mediator example.
 **/
class Mediator2 : public AbstractMediatorBase<Mediator2>{
	public:
		Mediator2();
		~Mediator2();
		virtual M_Status Status();
		virtual bool Init();
	//private:
	public:
		double toto;
		float truc;
		std::string blabla;
		bool b;
};

#endif // MEDIATOR__2___H
