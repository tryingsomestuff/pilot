#include "DataFactory.h"

// Must defined corresponding static members ...

/*
template<>
DataFactory * DataFactory::_instance = NULL;
*/

template<>
std::map<DataType,CreatorBase<AbstractData>*>
DataFactory::_map = std::map<DataType,CreatorBase<AbstractData>*>();


UserDataType::UserDataType(){
	a="";
};

UserDataType::UserDataType(const std::string & s){
	a=s;
};

UserDataType::UserDataType(const char * s){
	a=s;
};

UserDataType::~UserDataType(){

};

bool UserDataType::operator == (const UserDataType & t)const{
	return (t.a == this->a);
}

bool UserDataType::operator < (const UserDataType & t)const{
	return (t.a > this->a);
}
bool UserDataType::operator > (const UserDataType & t)const{
	return (t.a < this->a);
}

std::ostream& operator <<(std::ostream& str, const UserDataType& obj){
	str << obj.a;
	return str;
}

std::istream& operator >>(std::istream& str, UserDataType& obj){
	str >> obj.a;
	return str;
}

