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
// previous line defines DataFactory::DataType as std::string

#include "Trait.hpp"

/**
 *  Shortcut for specific register
 **/
namespace DataFactoryTools{
template <class DerivedType>
void Register(){
   DataFactory::Register(TraitDataId<DerivedType>::Id(),new DataCreator<DerivedType>);
}
} // DataFactoryTools

#endif // DATA__FACTORY__H
