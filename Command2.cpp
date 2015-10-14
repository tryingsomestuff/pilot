#include "Command2.h"
#include "Data2.h"

#include <string>
#include <iostream>
#include <assert.h>

/**
 * A concrete Command using Data2 facade (
 **/

class TestIterateCondition : public IterateCondition{
public:
	TestIterateCondition(int maxi):IterateCondition(),_count(0),_max(maxi){}
	virtual bool Iterate(){
		if( _count++ < _max ){
			Logger::Instance() << "Iterate : " << _count;
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
    Logger::Instance() << "-- Execute 2";
	Data2 * d = dynamic_cast<Data2*>(_d);
	assert(d!=0);
	Logger::Instance() << "Hello " << d->Id();
	Logger::Instance() << "Tata  " << d->Tata();
	Logger::Instance() << "Bli   " << d->Bli();

	return true;
}
