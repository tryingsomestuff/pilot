#ifndef ABSTRACTCONTAINER___H
#define ABSTRACTCONTAINER___H

#include <map>
#include <vector>
#include "Logger.hpp"

template< class T >
class AbstractContainer{
public:
    AbstractContainer(){}
	
	virtual ~AbstractContainer(){
	   for(typename std::map<std::string,T*>::iterator it = _c.begin() ; it != _c.end() ; ++it){
	      Logger::Instance() << "Deleting " << it->first;
	      delete it->second;
	   }
	}
	
	bool Set(const std::string & s, T * t){
       if( _c.find(s) == _c.end() ){
           _c[s] = t;
		   return true;
       }	   
	   else{
	       Logger::Instance() << "Error : key already present in container";
		   return false;
	   }
	}
	
	T * Get(const std::string & s){
       if( _c.find(s) != _c.end() ){
           return _c[s];
       }	   
	   else{
	       Logger::Instance() << "Error : key not present in container";
		   return NULL;
	   }
	}
	
	bool AddToMainStream(const std::string & s){
       if( _c.find(s) == _c.end() ){
	      Logger::Instance() << "Error : trying to add to main stream an unknow command";
		  return false;
       }		
	   _l.push_back(Get(s));
	   return true;
	}
	
	const std::vector<T*> GetMainStream(){
	   return _l;
	}
	
	///@todo pretty iterator
	
private:
    std::map<std::string,T*> _c;
	std::vector<T*>          _l;
};

#endif // ABSTRACTCONTAINER___H
