#ifndef DATA__1__H
#define DATA__1__H

#include <iostream>

#include "AbstractData.hpp"

/**
 *  A concrete facade to DataPool singleton container
 **/
class Data1 : public AbstractDataBase<Data1>{
	public:
		Data1();
        virtual ~Data1();

		double Toto();
		std::string Bla();
};

template<>
struct TraitDataId<Data1>{
	static DataType Id(){return "data1";}
};

#endif // DATA__1__H
