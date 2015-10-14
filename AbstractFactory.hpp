#ifndef __ABSTRACT_FACTORY__H
#define __ABSTRACT_FACTORY__H

#include <map>
#include <iostream>

/**
* An abstract base creator class
* Create() is implemented for each Derived type in template Creator
**/
template <class T>
class CreatorBase{
public:
    virtual ~CreatorBase(){}
    virtual T* Create() = 0;
};

/**
* Templated Creator
* Must specify both base type and derived type
**/
template <class DerivedType, class BaseType>
class Creator : public CreatorBase<BaseType>{
public:
    BaseType* Create(){
        return new DerivedType;
    }
};

/**
* An abstract factory
* Used to register new KeyT/Creator pair
* Contains a map of corresponding creators
* The main constrain is that Create() function do not take any argument
* Please note that KeyT (KeyType) MUST :
*      - have operator<<(ostream)
*      - have operator>>(istream)
*      - have operator== implemented
*      - have operator< implemented
*      - have operator> implemented
*      - have required CTORS so that Trait specialization works fine ...
* May be converted to singleton to avoid memory leak
**/
template <class T, class KeyT>
class AbstractFactory{
public:
	typedef KeyT KeyType;

	/// check if typeID is already present
	static bool Contains(KeyT id){
		if ( _map.find(id) != _map.end() ){
			return true;
		}
		else{
			return false;
		}
	}

	/// add creator to registered type
    static void Register(KeyT id, CreatorBase<T>* Fn){
		if( Contains(id) ){
			Logger::Instance() << "WARNING :: A creator with the same name is already registered " << id;
			Logger::Instance() << "This is either a double registration or a name collision. ";
		}
		else{
           _map[id] = Fn;
		}
    }

	/// create an object with the corresponding creator
	static T* Create(KeyT id){
		if( Contains(id) ){
           return _map[id]->Create();
		}
		else{
		   Logger::Instance() << "WARNING :: trying to use a Creator that is not registered : " << id;
		   return NULL;
		}
    }

    ~AbstractFactory(){
        typename std::map<KeyT, CreatorBase<T>*>::iterator i = _map.begin();
        while (i != _map.end()){
            delete (*i).second;
            ++i;
        }
    }

	/*
	static AbstractFactory<T, KeyT> * Instance(){
		if ( ! _instance )
			_instance = new AbstractFactory<T,KeyT>();
		return _instance;
	}
	*/
private:
	//AbstractFactory(){};
	//static AbstractFactory<T, KeyT> * _instance;
    static std::map<KeyT, CreatorBase<T>*> _map;
};

#endif // __ABSTRACT_FACTORY__H
