#ifndef _CCOMPUTER_H
#define _CCOMPUTER_H

class CCode
{
private: 
	int computer_hidden[4];
	int player1_hidden[4];
	int player2_hidden[4];

public:
	CCode();
	int player1_current[4];
	int player2_current[4];
	int compare_array[4];
	
	void set_computer_hidden();
	void set_player1_hidden();
	void set_player2_hidden();
	void set_player1_current();
	void set_player2_current();
	void compare_computer_player(char &r);
	void compare_player1(char &r);
	void compare_player2(char &r);

	string result();
	string p1c_string();
	string p2c_string();
	string ca_string();

};

#endif