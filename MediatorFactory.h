#ifndef MEDIATOR__FACTORY__H
#define MEDIATOR__FACTORY__H

#include <vector>

#include "AbstractFactory.hpp"
#include "AbstractMediator.hpp"
class AbstractCommand;

/**
 *  Creator of Mediator
 **/
template <class DerivedType>
class MediatorCreator : public Creator<DerivedType, AbstractMediator> {};

/**
 *  Factory of mediator
 **/
typedef AbstractFactory<AbstractMediator,int> MediatorFactory;
// previous line defines MediatorFactory::DataType as std::string

/**
 *  Shortcut for specific register
 **/
namespace MediatorFactoryTools{
template <class DerivedType>
void Register(){
   MediatorFactory::Register(TraitMediatorId<DerivedType>::Id(),new MediatorCreator<DerivedType>);
}
} // DataFactoryTools


/**
 *  Allows to build necessary mediators for a spcecific Command
 **/
class MediatorBuilder{
	public:
		static std::vector<AbstractMediator *> Create(const AbstractCommand * command);
};

#endif // MEDIATOR__FACTORY__H
