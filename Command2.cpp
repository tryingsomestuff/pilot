#include "Command2.h"
#include "Data2.h"

#include <string>
#include <iostream>
#include <assert.h>

/**
 * A concrete Command using Data2 facade (
 **/

class TestIterateCondition : public AbstractCommandIterate<Command2>::IterateCondition{
public:
	TestIterateCondition(int maxi):AbstractCommandIterate<Command2>::IterateCondition(),_count(0),_max(maxi){}
	virtual bool Iterate(){
		if( _count++ < _max ){
			std::cout << "Iterate : " << _count << std::endl;
			return true;
		}
		return false;
	}
protected:
	int _count;
	int _max;
};

Command2::Command2(AbstractData *d, AbstractCommand * n):AbstractCommandIterate<Command2>(d,n){
    // build and set the IterateCondition
	SetCondition(new TestIterateCondition(4));
}

Command2::~Command2(){

}

bool Command2::_Execute(){
    std::cout << "-- Execute 2" << std::endl;
	Data2 * d = dynamic_cast<Data2*>(_d);
	assert(d!=0);
	std::cout << "Hello " << d->Id() << std::endl;
	std::cout << "Tata  " << d->Tata() << std::endl;
	std::cout << "Bli   " << d->Bli() << std::endl;

	return true;
}
