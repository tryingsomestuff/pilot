#ifndef COMMAND__2__H
#define COMMAND__2__H

#include "AbstractCommand.hpp"

class Data2;

/**
 * A concrete Command using Data1 facade (use 0 mediator)
 **/
class Command2 : public AbstractCommandBase<Command2>{
	public:
		explicit Command2();
		virtual ~Command2();
		virtual bool _Execute();
};


template<>
struct TraitCommandId<Command2>{
    static CommandType Id(){return "command2";}
};

#endif // COMMAND__1__H
