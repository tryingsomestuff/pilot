#ifndef DATA__3__H
#define DATA__3__H

#include "AbstractData.hpp"

/**
 *  A concrete facade to DataPool singleton container
 **/
class Data3 : public AbstractDataBase<Data3>{
	public:
		Data3();
        virtual ~Data3();

		double Toto();
		std::string Bla();
};

template<>
struct TraitDataId<Data3>{
	static DataType Id(){return "data3";}
};

#endif // DATA__1__H
