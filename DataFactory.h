#ifndef DATA__FACTORY__H
#define DATA__FACTORY__H

#include "AbstractFactory.hpp"
#include <iostream>
#include <string>

class AbstractData;

/**
 *  Creator of data facade
 **/
template <class DerivedType>
class DataCreator : public Creator<DerivedType, AbstractData> {};

class DataType{ // just an example ...
public:
	DataType();
	DataType(std::string s);
	~DataType();
	friend std::ostream& operator <<(std::ostream&, const DataType&);
	friend std::istream& operator >>(std::istream&, DataType&);
	bool operator == (const DataType & t)const;
	bool operator <  (const DataType & t)const;
	bool operator >  (const DataType & t)const;
private:
	std::string a;
};

/**
 *  Factory of data facade
 **/
typedef AbstractFactory<AbstractData,DataType> DataFactory;
// previous line defines DataFactory::DataType as std::string

// late include is MANDATORY
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
