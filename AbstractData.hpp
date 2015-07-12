#ifndef ABSTRACT__DATA__H
#define ABSTRACT__DATA__H

#include <iostream>
#include <set>

#include "Trait.hpp"
#include "MediatorFactory.h"

/**
 *  Abstract facade to DataPool singleton container
 *  Note that this facade shall also be a proxy (think late-init, buffered, access to distant data, ...)
 **/
class AbstractData: public Named<std::string>{
    public:
        AbstractData();
        virtual ~AbstractData();

		void                                      AddDepend       (MediatorFactory::DataType m );
		const std::set<MediatorFactory::DataType> GetMediatorTypes(                            )const;
    private:
		std::set<MediatorFactory::DataType> _mediatorTypes;
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
