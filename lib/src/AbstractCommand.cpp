#include "AbstractCommand.hpp"
#include "AbstractData.hpp"

#include "assert.h"

AbstractCommand::AbstractCommand(AbstractData *d, AbstractCommand * n):_d(d),_n(n){

}

AbstractCommand::~AbstractCommand(){
	if ( _d ){
		delete _d;
		_d=0;
	}
}

void AbstractCommand::SetData(AbstractData * d){
	_d=d;
}

AbstractData * AbstractCommand::GetData(){
	return _d;
}

const AbstractData * AbstractCommand::GetData()const{
	if (! _d){
		Logger::Instance() << "WARNING :: Data pointer is not set yet, use SetData";
		return NULL;
	}
	return _d;
}

void AbstractCommand::SetNext(AbstractCommand * c){
	_n = c;
}


MultipleIterateCondition::MultipleIterateCondition(Mode m):_m(m){
    
};

MultipleIterateCondition::~MultipleIterateCondition(){
   	std::list<IterateCondition*>::iterator it = _conditions.begin();        
   	for(; it != _conditions.end(); ++it){
   	    delete *it;
   	}
   	_conditions.clear();
};

bool MultipleIterateCondition::Iterate(){
    std::list<IterateCondition*>::iterator it = _conditions.begin();
    for(; it != _conditions.end(); ++it){
        if ( _m == M_OR ){
           if( ! (*it)->Iterate() ){
              return false;
           }
        }
        else /*( _m == M_AND )*/{
           if( (*it)->Iterate() ){ 
               return true;
           }
        }
    }
    if ( _m == M_OR ){
       return true;
    }
    else /*( _m == M_AND )*/{
       return false;
    }
};

void  MultipleIterateCondition::AddCondition ( IterateCondition * cond){
    _conditions.push_back(cond);
} 