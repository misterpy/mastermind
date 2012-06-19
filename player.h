#ifndef _PLAYER_H_
#define _PLAYER_H_

class CPlayer
{
private:
	int code[4];
public:
	friend class CProcessing;
	int attempt[4];
	void set_code_generator();
	void set_code(int &ccounter,char &ccache);
	void set_attempt(int &ccounter2,int &choice,char &ccache);
};
#endif