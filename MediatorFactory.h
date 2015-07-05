#ifndef MEDIATOR__FACTORY__H
#define MEDIATOR__FACTORY__H

#include <vector>

#include "DataFactory.h"

class AbstractMediator;

/**
 *  Factory of mediator
 **/
class MediatorFactory{
	public:
		static std::vector<AbstractMediator *> Create(DataFactory::DataType type);
};

#endif // MEDIATOR__FACTORY__H
