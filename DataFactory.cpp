#include "DataFactory.h"

// Must defined corresponding static members ...

/*
DataFactory * DataFactory::_instance = NULL;
*/

DataType::DataType(){
	a="";
};

DataType::DataType(std::string s){
	a=s;
};

DataType::~DataType(){

};

bool DataType::operator == (const DataType & t)const{
	return (t.a == this->a);
}

bool DataType::operator < (const DataType & t)const{
	return (t.a > this->a);
}
bool DataType::operator > (const DataType & t)const{
	return (t.a < this->a);
}

std::ostream& operator <<(std::ostream& str, const DataType& obj){
	str.operator<<(obj.a.c_str());
	return str;
}

std::istream& operator >>(std::istream& str, DataType& obj){
	str >> obj.a;
	return str;
}


std::map<DataFactory::DataType,CreatorBase<AbstractData>*> 
DataFactory::_map = std::map<DataFactory::DataType,CreatorBase<AbstractData>*>();


