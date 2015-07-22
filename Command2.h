#ifndef COMMAND__2__H
#define COMMAND__2__H

#include "AbstractCommand.hpp"

class Data2;

/**
 * A concrete Command using Data1 facade (use 0 mediator)
 * In this example we demonstrate a simple iterate task.
 * See CTOR for definition of the IterateCondition
 **/
class Command2 : public AbstractCommandIterate<Command2>{
	public:
		explicit Command2(AbstractData *d=0, AbstractCommand * n=0);
		virtual ~Command2();
		virtual bool _Execute();
};


template<>
struct TraitCommandId<Command2>{
    static CommandType Id(){return "command2";}
};

#endif // COMMAND__1__H
