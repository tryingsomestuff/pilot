#ifndef ABSTRACT__DATA__H
#define ABSTRACT__DATA__H

#include <iostream>

/**
 *  Abstract facade to DataPool singleton container
 *  Note that this facade shall also be a proxy (think late-init, buffered, access to distant data, ...)
 **/
class AbstractData{
	public:
		AbstractData();
		virtual ~AbstractData();
		virtual std::string Name() = 0;
};

#endif // ABSTRACT__DATA__H
