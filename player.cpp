#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <limits>
using namespace std;
#include "processing.h"
#include "player.h"
#include "rangeexception.h"

void CPlayer::set_code_generator()																	//***** Generierung des Zufallscodes für Computer *****
{
	srand (time(NULL));																				//die srand-Funktion wird mit der aktuellen Zeit initialisiert
	for(int i=0; i<4; i++)																			//Schleife zur Abarbeitung des Arrays
	{
		code[i] = rand() % 6 + 1;																	//dem Array wird an jeder Stelle ein Zufallswert zwischen 1-5 zugewiesen
	}
}

void CPlayer::set_code(int &ccounter, char &ccache)													//***** Eingabe und Speicherung des vom Player gesetzten Codes *****
{
	ccache='r';																						//Zustandscache wird auf run gesetzt
	cout << "Player " << ccounter << " INITIAL code(press ENTER after each number): \n";			//Aufforderung Code einzugeben (ccounter enthaelt den Spielernamen, also 1 oder 2)

	for(int i=0; i<4 ; i++)																			//Schleife zur Abarbeitung des Arrays
	{
		cin >> code[i];

		if (cin.fail() )																			//Wenn Eingabe kein int-Wert ist:
			{
				cout << "Oops, please don't enter chars, try again with a digit between 1-5\n";		//	TRUE -> Fehlermeldung wird ausgegeben
				cin.clear();																		//	cin-Buffer wird bereinigt
				cin.ignore (numeric_limits<streamsize>::max(), '\n' );								//	verbleibende 'nicht-int' Zeichen im Buffer werden verworfen
				--i;																				//Zaehler muss vermindert werden, da sonst nicht alle 4 Ziffern vorhanden sind
			}
		else if (code[i]<=0 || code[i]>5)															//Wenn Eingabe nicht zwischen 1 und 5 ist:
				throw CRangeException();															//	Die CRangeException wird geworfen

	}


	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	ccounter++;																						//ccounter wird erhoeht um als naechstes Code von Player 2 abzufragen
	ccache='s';																						//Zustandscache wird hier auf Stop gesetzt, da die set_code Funktion erfolgreich war
}

void CPlayer::set_attempt(int &ccounter2, int &choice, char &ccache)								//***** Eingabe und Speicherung der Attempts von Player 1 & 2 *****
{
	ccache='r';																						//Zustandscache wird auf run gesetzt
	cout << "Player " << ccounter2 << " attempt (press ENTER after each number): \n";				//Aufforderung Attempt einzugeben (ccounter enthaelt den Spielernamen, also 1 oder 2)

	for(int i = 0; i < 4 ; i++)																		//Schleife zur Abarbeitung des Arrays
	{
		cin >> attempt[i];

		if (cin.fail() )																			//Wenn Eingabe kein int-Wert ist:
			{
				cout << "Oops, please don't enter chars, try again with a digit between 1-5\n";		//	TRUE -> Fehlermeldung wird ausgegeben
				cin.clear();																		//	cin-Buffer wird bereinigt
				cin.ignore (numeric_limits<streamsize>::max(), '\n' );								//	verbleibende 'nicht-int' Zeichen im Buffer werden verworfen
				--i;																				//Zaehler muss vermindert werden, da sonst nicht alle 4 Ziffern vorhanden sind
			}
		else if (attempt[i]<=0 || attempt[i]>5)														//Wenn Eingabe nicht zwischen 1 und 5 ist:
				throw CRangeException();															//	Die CRangeException wird geworfen

	}

	ccache='s';																						//Zustandscache wird hier auf Stop gesetzt, da die set_code Funktion erfolgreich war
	if(choice!=1)																					//Wenn choice (Spielmodus) NICHT auf Singleplayer-Modus (1) gesetzt wurde
		ccounter2++;																				//-> erhoehe ccounter um damit im naechsten Attempt den richtigen Spielernamen anzuzeigen
}
