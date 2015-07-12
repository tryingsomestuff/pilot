#ifndef __NAMED__H
#define __NAMED__H

template <class T>
class Named{
public:
	inline T Id()const {return _id;};
protected:
	T _id;
};

#endif // __NAMED__H