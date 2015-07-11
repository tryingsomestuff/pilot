#ifndef DATA__FACTORY__H
#define DATA__FACTORY__H

#include "AbstractFactory.hpp"

class AbstractData;

/**
 *  Factory of facade
 **/
template <class DerivedType>
class DataCreator : public Creator<DerivedType, AbstractData> {};

typedef AbstractFactory<AbstractData,std::string> DataFactory;

#endif // DATA__FACTORY__H
