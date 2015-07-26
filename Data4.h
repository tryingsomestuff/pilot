#ifndef DATA__4__H
#define DATA__4__H

#include "AbstractData.hpp"

/**
 *  A concrete facade to DataPool singleton container
 **/
class Data4 : public AbstractDataBase<Data4>{
	public:
		Data4();
        virtual ~Data4();
};

template<>
struct TraitDataId<Data4>{
	static DataType Id(){return "data4";}
};

#endif // DATA__1__H
