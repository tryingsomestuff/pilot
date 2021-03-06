#ifndef DATA__2__H
#define DATA__2__H

#include "AbstractData.hpp"

/**
 *  A concrete facade to DataPool singleton container
 **/
class Data2 : public AbstractDataBase<Data2>{
	public:
		Data2();
        virtual ~Data2();

		double Tata();
		std::string Bli();
};

template<>
struct TraitDataId<Data2>{
	static DataType Id(){return "data2";}
};

#endif // DATA__2__H