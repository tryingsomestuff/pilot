#ifndef MEDIATOR__FACTORY__H
#define MEDIATOR__FACTORY__H

#include <vector>

#include "AbstractFactory.hpp"
#include "AbstractMediator.hpp"
class AbstractCommand;

/**
 *  Factory of mediator
 **/
template <class DerivedType>
class MediatorCreator : public Creator<DerivedType, AbstractMediator> {};

typedef AbstractFactory<AbstractMediator,std::string> MediatorFactory;


class MediatorBuilder{
	public:
		static std::vector<AbstractMediator *> Create(const AbstractCommand * command);
};

#endif // MEDIATOR__FACTORY__H
