#include "AbstractData.hpp"

/**
 *  Abstract facade to DataPool singleton container
 *  Note that this facade shall also be a proxy (think late-init, buffered, access to distant data, ...)
 **/
AbstractData::AbstractData(){

}

AbstractData::~AbstractData(){

}

std::string AbstractData::Name(){
  return _name;
}

