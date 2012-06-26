#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
using namespace std;
#include "processing.h"
#include "player.h"

void CProcessing::compare_computer_player(CPlayer p1, CPlayer pc, char &state)		//***** Vergleich des Codes (Computer) mit Attempt (Player 1) *****
{

	for(int n=0; n<4 ;n++)															//Schleife zur Abarbeitung des Arrays
	{
		if(pc.code[n] == p1.attempt[n])												//Wenn Attempt == Code:
		{
			compare_array[n]=1;														// 	TRUE -> der Stelle (n) im Vergleichs-Array wird 1 zugewiesen
		}
		else
		{
			compare_array[n]=2;														// 	FALSE -> der Stelle (n) im Vergleichs-Array wird 2 zugewiesen
		}
	}
	if((compare_array[0] == 1) && (compare_array[1] == 1) && (compare_array[2] == 1) && (compare_array[3] == 1))	//Wenn alle Stellen im Vergleichsarray == 1 sind:
	{
		cout << "\n! ! ! Cracked ! ! !\n" << endl;																	//	TRUE -> Der Code wurde gecracked
		state='s';																									//	Spielzustand wird auf 's' -> STOP gesetzt
	}
	else																											//	FALSE -> Fehlversuch
	{
		state='r';																									//	Spielzustand wird auf 'r' -> RUN gesetzt
	}
}

void CProcessing::compare_player1(CPlayer p1, CPlayer p2, char &state)				//***** Vergleich des Codes (Player 2) mit Attempt (Player 1) *****
{
	for(int n=0; n<4; n++)															//Schleife zur Abarbeitung des Arrays
	{
		if(p1.attempt[n] == p2.code[n])												//Wenn Attempt (Player 1)  == Code (Player 2):
		{
			compare_array[n]=1;														// 	TRUE -> der Stelle (n) im Vergleichs-Array wird 1 zugewiesen
		}
		else
		{
			compare_array[n]=2;														// 	FALSE -> der Stelle (n) im Vergleichs-Array wird 2 zugewiesen
		}
	}

	if((compare_array[0] == 1) && (compare_array[1] == 1) && (compare_array[2] == 1) && (compare_array[3] == 1))	//Wenn alle Stellen im Vergleichsarray == 1 sind:
	{
		cout << "Player 1 wins!\n" << endl;																			//	TRUE -> Player 1 hat Code erfolgreich gecracked und gewinnt
		state='s';
	}
	else																											//	FALSE -> Fehlversuch
	{
		state='r';																									//	Spielzustand wird auf 'r' -> RUN gesetzt
	}
}

void CProcessing::compare_player2(CPlayer p1, CPlayer p2, char &state)				//***** Vergleich des Codes (Player 1) mit Attempt (Player 2) *****
{
	for(int n=0; n<4; n++)															//Schleife zur Abarbeitung des Arrays
	{
		if(p2.attempt[n] == p1.code[n])												//Wenn Attempt (Player 2)  == Code (Player 1):
		{
			compare_array[n]=1;														// 	TRUE -> der Stelle (n) im Vergleichs-Array wird 1 zugewiesen
		}
		else
		{
			compare_array[n]=2;														// 	FALSE -> der Stelle (n) im Vergleichs-Array wird 2 zugewiesen
		}
	}

	if((compare_array[0] == 1) && (compare_array[1] == 1) && (compare_array[2] == 1) && (compare_array[3] == 1))	//Wenn alle Stellen im Vergleichsarray == 1 sind:
	{
		cout << "Player 2 wins!\n" << endl;																			//	TRUE -> Player 1 hat Code erfolgreich gecracked und gewinnt
		state='s';
	}
	else																											//	FALSE -> Fehlversuch
	{
		state='r';																									//	Spielzustand wird auf 'r' -> RUN gesetzt
	}
}

string CProcessing::pattempt_string(CPlayer player)									//***** Laden der Attempts von Player 1 & 2 in eine stringstream Variable *****
{
	stringstream stream;
	stream << "Input: " << player.attempt[0] << " | " << player.attempt[1] << " | " << player.attempt[2] << " | " << player.attempt[3] << endl;
	return stream.str();
}

string CProcessing::result_string()													//***** Laden des Vergleichs-Array mit dem Spielstand in eine stringstream Variable *****
{
	stringstream stream;
	stream << "Result: " << compare_array[0] << " | " << compare_array[1] << " | " << compare_array[2] << " | " << compare_array[3] << endl;
	return stream.str();
}
