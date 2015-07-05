#include "AbstractMediator.hpp"

/**
 *  Abstract mediator container. Encapsulate any type of data.
 *  All data container must inherit from this one.
 *  Note that in some case mediators will probably contains
 *  some functional stuff also, and AbstractCommand::_Execute
 *  will eventually use those ...
 **/
AbstractMediator::AbstractMediator(){

}

AbstractMediator::~AbstractMediator(){

}

std::string AbstractMediator::Name(){
  return _name;
}
