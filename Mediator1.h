#ifndef MEDIATOR__1___H
#define MEDIATOR__1___H

#include "AbstractMediator.hpp"

#include <iostream>

/**
 *  A concrete mediator example.
 **/
class Mediator1 : public AbstractMediatorBase<Mediator1>{
	public:
		Mediator1();
		~Mediator1();
		virtual M_Status Status();
		virtual bool Init();
	//private:
	public:
		int toto;
		int tutu;
		std::string bla;
		bool eheh;
};

#endif // MEDIATOR__1___H
