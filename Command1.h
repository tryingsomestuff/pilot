#ifndef COMMAND__1__H
#define COMMAND__1__H

#include "AbstractCommand.hpp"

#include <string>

class Data1;

/**
 * A concrete Command using Data1 facade (mix of Mediator1 and Mediator2)
 **/
class Command1 : public AbstractCommandBase<Command1>{
	public:
		explicit Command1();
		virtual ~Command1();
		virtual bool _Execute();
};


template<>
struct TraitCommandName<Command1>{
    static std::string Name(){return "command1";}
};

#endif // COMMAND__1__H
