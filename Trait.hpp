#ifndef TRAIT____H
#define TRAIT____H

#include <string>

#include "MediatorFactory.h"
#include "DataFactory.h"
#include "CommandFactory.h"

/**
 *  Trait for mediator Name.
 *  MUST be defined for each mediator type.
 *  Using Trait was required but we need something
 *  to get a uniq identifier for each mediator type.
 *  We assume here a total orthogonality between mediator
 *  so that there is no need to register the same mediator twice
 *  with two different identifiers.
 *  (Do so may be done simply with inheritance anyway , as
 *  AbstractMediator::Name is virtual ...)
 **/
template<class T>
struct TraitMediatorId{
	static MediatorFactory::DataType Id(){return -1;} // nothing means bad ...
};
// DEFINE SPECIALIZATION FOR EACH CHILD OF ABSTRACTMEDIATOR

/**
 *  Trait for Data Name.
 *  Same comment as for mediator
 **/
template<class T>
struct TraitDataId{
	static DataFactory::DataType Id(){return "";} // nothing means bad ...
};
// DEFINE SPECIALIZATION FOR EACH CHILD OF ABSTRACTDATA

/**
 *  Trait for Command Name.
 *  Same comment as for mediator
 **/
template<class T>
struct TraitCommandId{
	static CommandFactory::DataType Id(){return "";} // nothing means bad ...
};
// DEFINE SPECIALIZATION FOR EACH CHILD OF ABSTRACTDATA

#endif // TRAIT____H
