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
	CPlayer player1;
	CPlayer player2;
	CPlayer computer;
	char run_outer, run_inner, cache;
	int choice, name_counter1, name_counter2;

	do
	{
		run_outer = 's';
		cout << text.welcome_text() << endl;
		cout << "\nYour choice: ";
		cin >> choice;
		if(choice == 1)
		{
			run_outer = 'r';
			cout << "You have chosen: (1)\n" << endl;
			cout << text.singleplayer() << endl;
			computer.set_code_generator();
			name_counter2=1;
			do
			{	
				run_inner = 's';
				try 
				{
					player1.set_attempt(name_counter2, choice, cache);
				}
				catch(CRangeException &err)
				{
					run_inner = 'r';
					cout << "\nError code: " << err.what() << endl;
				}
				if(run_inner == 's')
				{
				process.compare_computer_player(player1, computer, run_inner);
				cout << process.p1c_string(player1) << endl;
				cout << process.ca_string() << endl;
				}

			}while(run_inner == 'r');
		}
		else if(choice == 2)
		{	
			name_counter1=1;
			run_outer = 'r';
			cout << "You have chosen: (2)\n" << endl;
			cout << text.multiplayer() << endl;

			do
			{
				try 
					{
						player1.set_code(name_counter1, cache);
					}
			
				catch(CRangeException &err)
					{
						run_inner = 'r';
						cout << "\nError code: " << err.what() << endl;
					}
			}while(cache == 'r');


			do
			{
				try 
					{
						player2.set_code(name_counter1, cache);
					}
			
				catch(CRangeException &err)
					{
						run_inner = 'r';
						cout << "\nError code: " << err.what() << endl;
					}
			}while(cache == 'r');

			do
			{	
				name_counter2=1;
				run_inner = 's';


				do
				{
					try 
					{
						player1.set_attempt(name_counter2, choice, cache);
					}
					catch(CRangeException &err)
					{
						run_inner = 'r';
						cout << "\nError code: " << err.what() << endl;
					}
				}while(cache == 'r');
				

				cout << process.p1c_string(player1) << endl;
				process.compare_player1(player1, player2, run_inner);
				cout << process.ca_string() << endl;
				if( run_inner=='s' )
				{	
					break;
				}

				do
				{
					try 
					{
						player2.set_attempt(name_counter2, choice, cache);
					}
					catch(CRangeException &err)
					{
						run_inner = 'r';
						cout << "\nError code: " << err.what() << endl;
					}
				}while(cache == 'r');

				cout << process.p2c_string(player2) << endl;
				process.compare_player2(player1, player2, run_inner);
				cout << process.ca_string() << endl;
				if(run_inner=='s')
				{
					break;
				}
				
			}while(run_inner == 'r');
		}
		else if(choice == 3)
		{
			run_outer = 'r';
			cout << "You have chosen: (3)\n" << endl;
			cout << text.info_text() << endl;
		}
		else
		{
			cout << "Good bye!" << endl;
		}

	}while(run_outer == 'r');

}
