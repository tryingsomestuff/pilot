#ifndef ABSTRACT__DATA__H
#define ABSTRACT__DATA__H

#include <iostream>
#include <set>

#include "Trait.hpp"
#include "Named.hpp"
#include "MediatorFactory.h"
#include "DataFactory.h"

/**
 *  Abstract facade to DataPool singleton container
 *  Note that this facade shall also be a proxy (think late-init, buffered, access to distant data, ...)
 **/
class AbstractData: public Named<DataType>{
    public:
        AbstractData();
        virtual ~AbstractData();

		void                         AddDepend       (MediatorType m );
		const std::set<MediatorType> GetMediatorTypes(                )const;
    private:
		std::set<MediatorType> _mediatorTypes;
};

/**
 *  Automatically define Name from Trait
 *  This allows Trait specialization to be done anywhere as soon
 *  as the header is accessible there ...
 **/
template< class T >
class AbstractDataBase : public AbstractData{
   public:
       AbstractDataBase():AbstractData(){
          _id = TraitDataId<T>::Id();
       }
};

#endif // ABSTRACT__DATA__H
