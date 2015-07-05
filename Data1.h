#ifndef DATA__1__H
#define DATA__1__H

#include <iostream>

#include "AbstractData.h"

/**
 *  A concrete facade to DataPool singleton container
 **/
class Data1 : public AbstractData{
	public:
		Data1();
		virtual ~Data1();
		virtual std::string Name();

		double Toto();
		std::string Bla();
};

#endif // DATA__1__H
