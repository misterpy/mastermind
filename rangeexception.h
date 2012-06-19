#ifndef _RANGEEXCEPTION_H_
#define _RANGEEXCEPTION_H_

class CRangeException
{
public:
	string what() {return "Wrong input, please enter only 4 digits between 1-5 and one at a time!\n\n";}
};

#endif
