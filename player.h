#ifndef PLAYER_H_
#define PLAYER_H_

class CPlayer
{
private:
	int code[4];
	int attempt[4];
public:
	friend class CProcessing;
	void set_code_generator();
	void set_code(int &ccounter, char &ccache);
	void set_attempt(int &ccounter2, int &choice, char &ccache);
};
#endif
