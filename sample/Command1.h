#ifndef COMMAND__1__H
#define COMMAND__1__H

#include "AbstractCommand.hpp"

class Data1;

/**
 * A concrete Command using Data1 facade (mix of Mediator1 and Mediator2)
 **/
class Command1 : public AbstractCommandBase<Command1>{
	public:
		explicit Command1(AbstractData *d=0, AbstractCommand * n=0);
		virtual ~Command1();
		virtual bool _Execute();
};


template<>
struct TraitCommandId<Command1>{
    static CommandType Id(){return "command1";}
};

#endif // COMMAND__1__H
