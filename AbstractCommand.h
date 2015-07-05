#ifndef ABSTRACT___COMMAND__H
#define ABSTRACT___COMMAND__H

class AbstractData;

/**
 *  Abstract command, use an AbstractData (facade) to access specified data from DataPool
 *  _Execute must be defined in sub class to implement real stuff ...
 **/
class AbstractCommand{
	public:
		explicit AbstractCommand(AbstractData * d);
		virtual ~AbstractCommand();
		bool Execute();
	protected:
		virtual bool _Execute() = 0;
		AbstractData * _d;
};

#endif // ABSTRACT___COMMAND__H
