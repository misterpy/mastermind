#ifndef PROCESSING_H_
#define PROCESSING_H_

class CPlayer;	//CPlayer muss hier deklariert werden um fuer CProcessing sichtbar zu sein

/* CProcessing Klasse:
 * Diese Klasse beinhaltet den Kern des Programmes in dem die einzelnen Versuche ausgewertet werden.
 * Die Variable 'state' in den Compare-Funktionen enthaelt und uebergibt den Spielzustand und signalisiert das Ende des Spiels.
 */

class CProcessing
{
private:
	int compare_array[4];													//Variable beinhaltet ob einzelne Ziffern gecracked wurden und dadurch den aktuellen 'Spielstand'

public:
	void compare_computer_player(CPlayer p1, CPlayer pc, char &state);		//Funktion vergleicht den Attempt des Players mit dem Code des Computers (Singleplayer)
	void compare_player1(CPlayer p1, CPlayer p2, char &state);				//Funktion vergleicht den Attempt von Player 1 mit dem Code von Player 2 (Multiplayer)
	void compare_player2(CPlayer p1, CPlayer p2, char &state);				//Funktion vergleicht den Attempt von Player 2 mit dem Code von Player 1 (Multiplayer)
	string pattempt_string(CPlayer p1);										//Funktion die den Attempt der Player 1 & 2 ausgibt
	string result_string();													//Funktion die den Spielstand ausgibt
};
#endif
