#ifndef COMMAND__3__H
#define COMMAND__3__H

#include "AbstractCommand.hpp"

class Data1;

/**
 * A concrete Command using Data1 facade (mix of Mediator1 and Mediator2)
 * In this example we demonstrate a task that build the next one on the fly
 **/
class Command3 : public AbstractCommandBase<Command3>{
	public:
		explicit Command3(AbstractData *d=0, AbstractCommand * n=0);
		virtual ~Command3();
		virtual bool _Execute();
};


template<>
struct TraitCommandId<Command3>{
    static CommandType Id(){return "command3";}
};

#endif // COMMAND__1__H
