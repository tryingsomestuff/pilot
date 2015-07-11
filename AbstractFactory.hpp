#ifndef __ABSTRACT_FACTORY__H
#define __ABSTRACT_FACTORY__H

#include <map>

/**
* An abstract base creator class
* Create() must be implemented for each Derived type
**/
template <class T>
class CreatorBase{
public:
    virtual ~CreatorBase(){}
    virtual T* Create() = 0;
};

/**
* Templated Creator
* Must specify both base type and derived type ...
**/
template <class DerivedType, class BaseType>
class Creator : public CreatorBase<BaseType>{
public:
    BaseType* Create(){
        return new DerivedType;
    }
};

/**
* An abstract factory singleton
* Used to register new KeyT/Creator pair
* Contains a map of corresponding creators
**/
template <class T, class KeyT>
class AbstractFactory{
public:
	typedef KeyT DataType;

    static void Register(KeyT Id, CreatorBase<T>* Fn){
		///@todo checks
        _map[Id] = Fn;
    }
	static T* Create(KeyT Id){
		///@todo chacks
        return _map[Id]->Create();
    }
    ~AbstractFactory(){
        std::map<KeyT, CreatorBase<T>*>::iterator i = _map.begin();
        while (i != _map.end()){
            delete (*i).second;
            ++i;
        }
    }
	static AbstractFactory<T, KeyT> * Instance(){
		if ( ! _instance )
			_instance = new AbstractFactory<T,KeyT>();
		return _instance;
	}
private:
	AbstractFactory(){};
	static AbstractFactory<T, KeyT> * _instance;
    static std::map<KeyT, CreatorBase<T>*> _map;
};

#endif // __ABSTRACT_FACTORY__H