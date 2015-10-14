#ifndef LOGGER___H
#define LOGGER___H

#include <iostream>

class Logger{
public:

	static
	Logger & Instance(){
		if ( ! _instance )
			_instance = new Logger();

		return *_instance;
	}

	template < class T >
    Logger & operator << (const T & t){
	   std::cout << t << std::endl;
	   return *this;
    }

private:
	static Logger * _instance;
};


#endif // LOGGER___H