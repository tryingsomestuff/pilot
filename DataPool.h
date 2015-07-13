#ifndef DATA__POOOL__H
#define DATA__POOOL__H

#include "MediatorFactory.h"

class AbstractMediator;

#include <map>
#include <iostream>


/**
 *  The DataPool singleton.
 *  You must register every Mediator in the DataPool.
 *  Use facade to mix up Mediator together and/or filter them !
 **/
class DataPool{ // singleton
	public:
		~DataPool();
		static DataPool *  Instance();
		// Delegate mediator to DataPool
		void               Register   (AbstractMediator * mediator);
		AbstractMediator * GetMediator(MediatorType type);
		bool               Contains   (MediatorType type);
	private:
		explicit DataPool(){};
		static DataPool * _pool;
		std::map<MediatorType,AbstractMediator * > _mediators;
};

#endif // DATA__POOOL__H
