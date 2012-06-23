#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
using namespace std;
#include "processing.h"
#include "player.h"

void CProcessing::compare_computer_player(CPlayer p1, CPlayer pc, char &state)
{

	for(int n=0; n<4 ;n++)
	{
		if(pc.code[n] == p1.attempt[n])
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
		state='s';
	}
	else
	{
		state='r';
	}
}

void CProcessing::compare_player1(CPlayer p1, CPlayer p2, char &state)
{
	for(int n=0; n<4; n++)
	{
		if(p1.attempt[n] == p2.code[n])
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
		cout << "Player 1 wins!\n" << endl;
		state='s';
	}
	else
	{
		state='r';
	}
}

void CProcessing::compare_player2(CPlayer p1, CPlayer p2, char &state)
{
	for(int n=0; n<4; n++)
	{
		if(p2.attempt[n] == p1.code[n])
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
		cout << "Player 2 wins!\n" << endl;
		state='s';
	}
	else
	{
		state='r';
	}
}

string CProcessing::p1c_string(CPlayer p1)
{
	stringstream stream;
	stream << "Input: " << p1.attempt[0] << " | " << p1.attempt[1] << " | " << p1.attempt[2] << " | " << p1.attempt[3] << endl;
	return stream.str();
}

string CProcessing::p2c_string(CPlayer p2)
{
	stringstream stream;
	stream << "Input: " << p2.attempt[0] << " | " << p2.attempt[1] << " | " << p2.attempt[2] << " | " << p2.attempt[3] << endl;
	return stream.str();
}

string CProcessing::ca_string()
{
	stringstream stream;
	stream << "Result: " << compare_array[0] << " | " << compare_array[1] << " | " << compare_array[2] << " | " << compare_array[3] << endl;
	return stream.str();
}
