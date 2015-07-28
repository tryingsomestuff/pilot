#ifndef MEDIATOR__2___H
#define MEDIATOR__2___

#include "AbstractMediator.hpp"

/**
 *  Another concrete mediator example.
 **/
class Mediator2 : public AbstractMediatorBase<Mediator2>{
	public:
		Mediator2();
		~Mediator2();
		virtual M_Status Status()const;
		virtual bool Init();
	//private:
	public:
		double toto;
		float truc;
		std::string blabla;
		bool b;
};

template<>
struct TraitMediatorId<Mediator2>{
    static MediatorType Id(){return 2;}
};

#endif // MEDIATOR__2___H
