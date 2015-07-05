#ifndef DATA__FACTORY__H
#define DATA__FACTORY__H

class AbstractData;

/**
 *  Factory of facade
 **/
class DataFactory{
	public:
		enum DataType{
			DT_0 = 0, // forbidden
			DT_1 = 1,
			DT_2 = 2,
			DT_MAX = 2
		};
		static AbstractData * Create(DataType type);
};

#endif // DATA__FACTORY__H
