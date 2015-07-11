#ifndef ABSTRACT__DATA__H
#define ABSTRACT__DATA__H

#include <iostream>
#include <set>

#include "Trait.hpp"

/**
 *  Abstract facade to DataPool singleton container
 *  Note that this facade shall also be a proxy (think late-init, buffered, access to distant data, ...)
 **/
class AbstractData: public Named{
    public:
        AbstractData();
        virtual ~AbstractData();
};

/**
 *  Automatically define Name from Trait
 *  This allows Trait specialization to be done anywhere as soon
 *  as the header is accessible here ...
 **/
template< class T >
class AbstractDataBase : public AbstractData{
   public:
       AbstractDataBase():AbstractData(){
          _name = TraitDataName<T>::Name();
       }
};

#endif // ABSTRACT__DATA__H
