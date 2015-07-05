#ifndef DATA__POOOL__H
#define DATA__POOOL__H

class AbstractMediator;

#include <map>
#include <iostream>

/**
 *  The DataPool singleton.
 *  Register every Mediator in the DataPool.
 *  Use facade to mix Mediator together and filter them !
 **/
class DataPool{ // singleton
	public:
		~DataPool();
		static DataPool * Instance();
		// Delegate mediator to DataPool
		void Register(AbstractMediator * mediator);
		AbstractMediator * GetMediator(std::string name);
		bool Contains(std::string name);
	private:
		explicit DataPool(){};
		static DataPool * _pool;
		std::map<std::string,AbstractMediator * > _mediators;
        typedef std::map<std::string,AbstractMediator *>::iterator _m_it;
};

#endif // DATA__POOOL__H
