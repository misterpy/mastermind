#ifndef RANGEEXCEPTION_H_
#define RANGEEXCEPTION_H_

/* CRangeException Klasse:
 * Eine Exception-Klasse die eine Fehlermeldung ausgibt, wenn ein 'throw' auftritt!
 */

class CRangeException
{
public:
	string what(){return "Wrong input, please enter only 4 digits between 1-5 and just one at a time!\n\n";}
};

#endif
