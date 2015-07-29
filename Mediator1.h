#ifndef MEDIATOR__1___H
#define MEDIATOR__1___H

#include "AbstractMediator.hpp"

/**
 *  A concrete mediator example.
 **/
class Mediator1 : public AbstractMediatorBase<Mediator1>{
	public:
		Mediator1();
		~Mediator1();
    protected:
		virtual bool _Init();
	//private:
	public:
		int toto;
		int tutu;
		std::string bla;
		bool eheh;
};

template<>
struct TraitMediatorId<Mediator1>{
	static MediatorType Id(){return 1;}
};

#endif // MEDIATOR__1___H
