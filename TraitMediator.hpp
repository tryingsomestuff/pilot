#ifndef TRAIT__MEDIATOR__H
#define TRAIT__MEDIATOR__H

#include <iostream>

/**
 *  Trait for mediator Name.
 *  MUST be defined for each mediator type.
 *  Using Trait is not required but we need something
 *  to get a uniq identifier for each mediator type.
 *  We assume here a total orthogonality between mediator
 *  so that there is no need to register the same mediator twice
 *  with two different identifiers.
 *  (Do so may be done simply with inheritance anyway , as
 *  AbstractMediator::Name is virtual ...)
 **/
template<class T>
struct TraitMediatorName{
	static std::string Name(){return "";}; // nothing means bad ...
};

class Mediator1; // forward decl
template<>
struct TraitMediatorName<Mediator1>{
	static std::string Name(){return "med1";};
};

class Mediator2; // forward decl
template<>
struct TraitMediatorName<Mediator2>{
	static std::string Name(){return "med2";};
};

#endif // TRAIT__MEDIATOR__H
