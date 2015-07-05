#ifndef COMMAND__1__H
#define COMMAND__1__H

#include "AbstractCommand.h"

class Data1;

/**
 * A concrete Command using Data1 facade (mix of Mediator1 and Mediator2)
 **/
class Command1 : public AbstractCommand{
	public:
		explicit Command1(Data1 * d);
		virtual ~Command1();
		virtual bool _Execute();
};

#endif // COMMAND__1__H
