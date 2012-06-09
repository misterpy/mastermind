#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
using namespace std;
#include "text.h"
#include "code.h"
#include "gui.h"

void CGui::application()
{
	CText t1;
	CCode input;
	char run,run2;
	int wahl;

	cout << t1.welcome_text() << endl;

	do
	{
		run = 's';
		cout << "\nYour choice: ";
		cin >> wahl;
		if(wahl == 1)
		{
			run = 'r';
			cout << "You have choosen: (1)\n" << endl;
			cout << t1.player_computer() << endl;
			input.set_computer_hidden();
			do
			{	
				run2 = 's';
				input.set_player1_current();
				input.compare_computer_player(run2);
				cout << input.p1c_string() << endl;
				cout << input.ca_string() << endl;

			}while(run2 == 'r');
		}
		else if(wahl == 2)
		{
			run = 'r';
			cout << "You have choosen: (2)\n" << endl;
			cout << t1.player_player() << endl;
			input.set_player1_hidden();
			input.set_player2_hidden();

			do
			{	
				run2 = 's';
				input.set_player1_current();
				cout << input.p1c_string() << endl;
				input.compare_player1(run2);
				cout << input.ca_string() << endl;
				if( run2=='s' )
				{
					break;
				}

				input.set_player2_current();
				cout << input.p2c_string() << endl;
				input.compare_player2(run2);
				cout << input.ca_string() << endl;
				if( run2=='s' )
				{
					break;
				}
				
			}while(run2 == 'r');
		}
		else if(wahl == 3)
		{
			run = 'r';
			cout << "You have choosen: (3)\n" << endl;
			cout << t1.info_text() << endl;
		}
		else
		{
			cout << "Good bye!" << endl;
		}

	}while(run == 'r');

}