#ifndef DATA__FACTORY__H
#define DATA__FACTORY__H

#include "AbstractFactory.hpp"

class AbstractData;

/**
 *  Creator of data facade
 **/
template <class DerivedType>
class DataCreator : public Creator<DerivedType, AbstractData> {};

/**
 *  Factory of data facade
 **/
typedef AbstractFactory<AbstractData,std::string> DataFactory;

#endif // DATA__FACTORY__H
