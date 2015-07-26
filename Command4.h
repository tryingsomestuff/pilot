#ifndef COMMAND__4__H
#define COMMAND__4__H

#include "AbstractCommand.hpp"

class Data4;

/**
 * A concrete Command using Data4 facade
 * In this example we demonstrate a task that build the next one on the fly
 **/
class Command4 : public AbstractCommandBase<Command4>{
	public:
		explicit Command4(AbstractData *d=0, AbstractCommand * n=0);
		virtual ~Command4();
		virtual bool _Execute();
};


template<>
struct TraitCommandId<Command4>{
    static CommandType Id(){return "command4";}
};

#endif // COMMAND__1__H
