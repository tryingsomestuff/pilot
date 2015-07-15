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

class UserDataType{ // just an example ...
public:
	UserDataType();
	UserDataType(const std::string & s);
	UserDataType(const char * s);
	~UserDataType();
	friend std::ostream& operator <<(std::ostream&, const UserDataType&);
	friend std::istream& operator >>(std::istream&, UserDataType&);
	bool operator == (const UserDataType & t)const;
	bool operator <  (const UserDataType & t)const;
	bool operator >  (const UserDataType & t)const;
private:
	std::string a;
};

/**
 *  Factory of data facade
 **/
typedef AbstractFactory<AbstractData,UserDataType> DataFactory;
// previous line defines DataFactory::KeyType as DataType
typedef DataFactory::KeyType DataType;

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
