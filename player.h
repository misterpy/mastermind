#ifndef PLAYER_H_
#define PLAYER_H_

/* CPlayer Klasse:
 * Die einzelnen Spieler (Computer, Player 1 & 2) sind vom Typ CPlayer.
 * Diese Klasse beinhaltet den Zufallscodegenerator des Computers und den Code und Attempt aller Spieler.
 */

class CPlayer
{
private:
	int code[4];														//Array, das den vom Spieler eingegeben Code oder generierten Computer-Code enthaelt
	int attempt[4];														//Array, das die Eingabe des Spielers und damit den Versuch den Code zu brechen enthaelt
public:
	friend class CProcessing;											//CProcessing-Klasse wird als friend von CPlayer definiert, so dass CProcessing Zugriff auf private von CPlayer hat
	void set_code_generator();											//Funktion zur Generierung des Zufallscodes des Computers (Singleplayer)
	void set_code(int &ccounter, char &ccache);							//Funktion zur Eingabe und Speicherung des Codes in der code-Variable (Multiplayer)
																		//ccounter uebergibt den Spielernamen (1 oder 2), ccache enthaelt den Spielzustand
	void set_attempt(int &ccounter2, int &choice, char &ccache);		//Funktion zur Eingabe und Speicherung des Attempts der Spieler
																		//ccounter2 uebergibt den Spielernamen (1 oder 2), choice enthaelt Spielmodus, ccache enthaelt den Spielzustand
};
#endif
