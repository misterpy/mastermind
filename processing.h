#ifndef PROCESSING_H_
#define PROCESSING_H_

class CPlayer;

class CProcessing
{
private:
	int compare_array[4];
public:
	void compare_computer_player(CPlayer p1, CPlayer pc, char &state);
	void compare_player1(CPlayer p1, CPlayer p2, char &state);
	void compare_player2(CPlayer p1, CPlayer p2, char &state);
	string result();
	string p1c_string(CPlayer p1);
	string p2c_string(CPlayer p2);
	string ca_string();
};
#endif
