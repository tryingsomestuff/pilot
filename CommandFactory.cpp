#include "CommandFactory.h"

#include "Data1.h"
#include "Command1.h"

/**
 * Factory of command
 **/
AbstractCommand * CommandFactory::Create(AbstractData * d, CommandType type){
  switch(type){
	  case CT_0:
		  std::cout << "Error type not defined" << std::endl;
		  break;
	  case CT_1:
		  {
			  Data1* dd = dynamic_cast<Data1*>(d);
			  if (dd){
				  std::cout << "Creating a Command1" << std::endl;
				  return new Command1(dd);
			  }
			  std::cout << "Error bad data type for Command1" << std::endl;
		  }
		  break;
	  case CT_2:
		  std::cout << "Error non implemented" << std::endl;
		  break;
	  default:
		  std::cout << "Error type unknown" << std::endl;
		  break;
  }
  return NULL;
}
