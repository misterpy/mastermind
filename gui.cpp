#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
using namespace std;
#include "text.h"
#include "processing.h"
#include "gui.h"
#include "player.h"
#include "rangeexception.h"

void CGui::application()
{
	CText text;
	CProcessing process;
	CPlayer player1, player2, computer;

	char run_outer, run_inner, cache;							//Laufzeitvariablen die in Schleifen benutzt werden um den derzeitigen Spielzustand festzuhalten
	int choice, name_counter1, name_counter2;					//choice -> Spielmodus; name_counter -> Darstellung des aktuellen Spielernamens (1 oder 2)

	do															//*!*!*!* Schleife zur Wahl des Spielmodus (Abbruch mit '4') *!*!*!*
	{
		run_outer = 's';										//Laufvariable der äußeren Schleife wird mit 's' initialisiert
		cout << text.welcome_text() << endl;					//Ausgabe des Willkommens-Textes
		cout << "\nYour choice: ";
		cin >> choice;

		if(choice == 1)											//Wenn Modus 1 (Singleplayer) gewaehlt wurde
		{
			run_outer = 'r';									//Laufvariable der äußeren Schleife wird auf 'r' gesetzt
			cout << "You have chosen: (1)\n" << endl;
			cout << text.singleplayer() << endl;				//Kurze Information zum Spielmodus werden ausgegeben
			computer.set_code_generator();						//Computer ruft Codegenerator-Funktion auf
			name_counter2=1;									//Namensvariable wird auf 1 (Player 1) gesetzt

			do																		//*!*!*!* Schleife die das Spiel im Singleplayer-Modus ausführt (solange run_inner == r)*!*!*!*
			{	
				run_inner = 's';													//innere Laufvariable wird auf 's' gesetzt
				try 																//Try-Block
				{
					player1.set_attempt(name_counter2, choice, cache);				//set Attempt von Spieler 1
				}
				catch(CRangeException &err)											//wenn Fehlermeldung CRangeException gewurfen wurde, wird diese hier gefangen
				{
					run_inner = 'r';												//innere Laufvariable wird auf 'r' gesetzt
					cout << "\nError code: " << err.what() << endl;					//Fehlermeldung wird ausgegeben
				}
				if(run_inner == 's')												//Wenn Laufvariable 's' ist und somit kein Fehler aufgetreten ist (Attempt-Array hat gueltige Werte)
				{
					process.compare_computer_player(player1, computer, run_inner);	//Code wird ausgewertet und verglichen
					cout << process.pattempt_string(player1) << endl;				//Ausgabe des Attempts von Player 1
					cout << process.result_string() << endl;						//Ausgabe des Compare-Arrays (Spielstand)
				}

			}while(run_inner == 'r');
		}

		else if(choice == 2)												//Wenn Modus 2 (Multiplayer) gewaehlt wurde
		{	
			name_counter1=1;												//Namenszaehler wird auf 1 (Player 1) gesetzt
			run_outer = 'r';												//Laufvariable der äußeren Schleife wird auf 'r' gesetzt
			cout << "You have chosen: (2)\n" << endl;
			cout << text.multiplayer() << endl;								//Kurze Information zum Spielmodus werden ausgegeben

			do																//*!*!*!* Schleife die den Code fuer Player 1 setzt *!*!*!*
			{
				try 														//try-Block:
					{
						player1.set_code(name_counter1, cache);				//set Code fuer Player 1
					}
			
				catch(CRangeException &err)									//wenn Fehlermeldung CRangeException gewurfen wurde, wird diese hier gefangen
					{
						run_inner = 'r';									//innere Laufvariable wird auf 'r' gesetzt
						cout << "\nError code: " << err.what() << endl;		//Fehlermeldung wird ausgegeben
					}
			}while(cache == 'r');											//wenn set_code erfolgreich war, wird cache auf 's' gesetzt und Schleife abgebrochen

			do																//*!*!*!* Schleife die den Code fuer Player 2 setzt *!*!*!*
			{
				try 														//try-Block:
					{
						player2.set_code(name_counter1, cache);				//set Code fuer Player 2
					}
			
				catch(CRangeException &err)									//wenn Fehlermeldung CRangeException gewurfen wurde, wird diese hier gefangen
					{
						run_inner = 'r';									//innere Laufvariable wird auf 'r' gesetzt
						cout << "\nError code: " << err.what() << endl;		//Fehlermeldung wird ausgegeben
					}
			}while(cache == 'r');											//wenn set_code erfolgreich war, wird cache auf 's' gesetzt und Schleife abgebrochen

			do
			{	
				name_counter2=1;											//Namensvariable wird mit 1 initialisiert
				run_inner = 's';											//innere Laufvariable wird auf 's' gesetzt

				do															//*!*!*!* Schleife die den Attempt fuer Player 1 setzt *!*!*!*
				{
					try 													//try-Block:
					{
						player1.set_attempt(name_counter2, choice, cache);	//set Attempt fuer Player 1
					}
					catch(CRangeException &err)								//wenn Fehlermeldung CRangeException gewurfen wurde, wird diese hier gefangen
					{
						run_inner = 'r';									//innere Laufvariable wird auf 'r' gesetzt
						cout << "\nError code: " << err.what() << endl;		//Fehlermeldung wird ausgegeben
					}
				}while(cache == 'r');										//wenn set_code erfolgreich war, wird cache auf 's' gesetzt und Schleife abgebrochen
				
				cout << process.pattempt_string(player1) << endl;			//Attempt von Player 1 wird ausgegeben
				process.compare_player1(player1, player2, run_inner);		//Attempt von Player 1 wird mit Code von Player 2 verglichen
				cout << process.result_string() << endl;					//Ausgabe des Compare-Arrays (Spielstand)

				if(run_inner == 's')										//Wenn Spielstand durch compare Funktion auf stop gesetzt wurde (Player 1 hat gewonnen)
				{	
					break;													//Schleife wird abgebrochen -> zurueck ins Menue
				}

				do															//*!*!*!* Schleife die den Attempt fuer Player 2 setzt *!*!*!*
				{
					try 													//try-Block:
					{
						player2.set_attempt(name_counter2, choice, cache);	//set Attempt fuer Player 2
					}
					catch(CRangeException &err)								//wenn Fehlermeldung CRangeException gewurfen wurde, wird diese hier gefangen
					{
						run_inner = 'r';									//innere Laufvariable wird auf 'r' gesetzt
						cout << "\nError code: " << err.what() << endl;		//Fehlermeldung wird ausgegeben
					}
				}while(cache == 'r');										//wenn set_code erfolgreich war, wird cache auf 's' gesetzt und Schleife abgebrochen

				cout << process.pattempt_string(player2) << endl;			//Attempt von Player 2 wird ausgegeben
				process.compare_player1(player1, player2, run_inner);		//Attempt von Player 1 wird mit Code von Player 2 verglichen
				cout << process.result_string() << endl;					//Ausgabe des Compare-Arrays (Spielstand)

				if(run_inner == 's')										//Wenn Spielstand durch compare Funktion auf stop gesetzt wurde (Player 1 hat gewonnen)
				{
					break;													//Schleife wird abgebrochen -> zurueck ins Menue
				}
				
			}while(run_inner == 'r');
		}
		else if(choice == 3)												//Wenn im Menue 3 gewaehlt wird (Info):
		{
			run_outer = 'r';
			cout << "You have chosen: (3)\n" << endl;
			cout << text.info_text() << endl;								//Info-Text wird ausgegeben
		}
		else if(choice == 4)												//Wenn im Menue 4 gewaehlt wird (Exit):
		{
			cout << "Good bye!" << endl;
			break;															//Programm wird abgebrochen
		}
		else																//Bei Fehleingabe
		{
			run_outer = 'r';
			cout << "\tPlease try again with 1,2,3 or 4!\n\n" << endl;		//Hinweis auf Fehleingabe -> Menue
		}

	}while(run_outer == 'r');

}
