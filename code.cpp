#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
using namespace std;
#include "code.h"

CCode::CCode()
{
	//player1_hidden[4] = player2_hidden[4] = computer_hidden[4] = 0;
}

void CCode::set_player1_current()
{
	cout << "Player 1 code(press ENTER after each number): \n";

	for(int index1 = 0; index1 < 4 ; index1++)
	{
		cin >> player1_current[index1];
	}
}

void CCode::set_player2_current()
{
	cout << "Player 2 code(press ENTER after each number): \n";

	for(int index2 = 0; index2 < 4 ; index2++)
	{
		cin >> player2_current[index2];
	}
}

void CCode::set_player1_hidden()
{
	cout << "Player 1 INITIAL code(press ENTER after each number): \n";

	for(int position = 0; position < 4 ; position++)
	{
		cin >> player1_hidden[position];
	}
}

void CCode::set_player2_hidden()
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPlayer 2 INITIAL code(press ENTER after each number): \n";

	for(int position = 0; position < 4 ; position++)
	{
		cin >> player2_hidden[position];
	}

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
}

void CCode::set_computer_hidden()
{
	srand ( time(NULL) );
	for(int index=0; index<4; index++)
	{
		computer_hidden[index] = rand() % 5 + 1;
	}
}

void CCode::compare_computer_player(char &r)
{
	for(int n=0; n<4 ;n++)
	{
		if(computer_hidden[n] == player1_current[n])
		{
			compare_array[n]=1;
		}
		else
		{
			compare_array[n]=2;
		}
	}

	if((compare_array[0] == 1) && (compare_array[1] == 1) && (compare_array[2] == 1) && (compare_array[3] == 1))
	{
		cout << "\n! ! ! Cracked ! ! !\n" << endl;
		r='s';
	}
	else
	{
		r='r';
	}
}

void CCode::compare_player1(char &r)
{
	for(int n=0; n<4 ;n++)
	{
		if(player1_current[n] == player2_hidden[n])
		{
			compare_array[n]=1;
		}
		else
		{
			compare_array[n]=2;
		}
	}

	if((compare_array[0] == 1) && (compare_array[1] == 1) && (compare_array[2] == 1) && (compare_array[3] == 1))
	{
		cout << "Player 1 wins!" << endl;
		r='s';
	}
	else
	{
		r='r';
	}
}

void CCode::compare_player2(char &r)
{
for(int n=0; n<4 ;n++)
	{
		if(player2_current[n] == player1_hidden[n])
		{
			compare_array[n]=1;
		}
		else
		{
			compare_array[n]=2;
		}
	}

	if((compare_array[0] == 1) && (compare_array[1] == 1) && (compare_array[2] == 1) && (compare_array[3] == 1))
	{
		cout << "Player 2 wins!" << endl;
		r='s';
	}
	else
	{
		r='r';
	}
}

string CCode::p1c_string()
{
	stringstream stream;
	stream << "Input: " << player1_current[0] << " | " << player1_current[1] << " | " << player1_current[2] << " | " << player1_current[3] << endl;
	return stream.str();
}

string CCode::p2c_string()
{
	stringstream stream;
	stream << "Input: " << player2_current[0] << " | " << player2_current[1] << " | " << player2_current[2] << " | " << player2_current[3] << endl;
	return stream.str();
}

string CCode::ca_string()
{
	stringstream stream;
	stream << "Result: " << compare_array[0] << " | " << compare_array[1] << " | " << compare_array[2] << " | " << compare_array[3] << endl;
	return stream.str();
}
