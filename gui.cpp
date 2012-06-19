#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
using namespace std;
#include "text.h"
#include "processing.h"
#include "player.h"
#include "gui.h"
#include "rangeexception.h"


void CGui::application()
{
	CText text;
	CProcessing process;
	CPlayer player1;
	CPlayer player2;
	CPlayer computer;
	char run,run2, cache;
	int choice, counter, counter2;

	do
	{
		run = 's';
		cout << text.welcome_text() << endl;
		cout << "\nYour choice: ";
		cin >> choice;
		if(choice == 1)
		{
			run = 'r';
			cout << "You have chosen: (1)\n" << endl;
			cout << text.singleplayer() << endl;
			computer.set_code_generator();
			counter2=1;
			do
			{	
				run2 = 's';
				try 
				{
					player1.set_attempt(counter2, choice,cache);
				}
				catch(CRangeException &err)
				{
					run2 = 'r';
					cout << "\nError code: " << err.what() << endl;
				}
				if(run2 == 's')
				{
				process.compare_computer_player(player1, computer ,run2);
				cout << process.p1c_string(player1) << endl;
				cout << process.ca_string() << endl;
				}

			}while(run2 == 'r');
		}
		else if(choice == 2)
		{	
			counter=1;
			run = 'r';
			cout << "You have chosen: (2)\n" << endl;
			cout << text.multiplayer() << endl;

			do
			{
				try 
					{
						player1.set_code(counter,cache);
					}
			
				catch(CRangeException &err)
					{
						run2 = 'r';
						cout << "\nError code: " << err.what() << endl;
					}
			}while(cache == 'r');


			do
			{
				try 
					{
						player2.set_code(counter,cache);
					}
			
				catch(CRangeException &err)
					{
						run2 = 'r';
						cout << "\nError code: " << err.what() << endl;
					}
			}while(cache == 'r');

			do
			{	
				counter2=1;
				run2 = 's';


				do
				{
					try 
					{
						player1.set_attempt(counter2, choice,cache);
					}
					catch(CRangeException &err)
					{
						run2 = 'r';
						cout << "\nError code: " << err.what() << endl;
					}
				}while(cache == 'r');
				

				cout << process.p1c_string(player1) << endl;
				process.compare_player1(player1, player2 ,run2);
				cout << process.ca_string() << endl;
				if( run2=='s' )
				{	
					break;
				}

				do
				{
					try 
					{
						player2.set_attempt(counter2, choice,cache);
					}
					catch(CRangeException &err)
					{
						run2 = 'r';
						cout << "\nError code: " << err.what() << endl;
					}
				}while(cache == 'r');

				cout << process.p2c_string(player2) << endl;
				process.compare_player2(player1, player2,run2);
				cout << process.ca_string() << endl;
				if( run2=='s' )
				{
					break;
				}
				
			}while(run2 == 'r');
		}
		else if(choice == 3)
		{
			run = 'r';
			cout << "You have chosen: (3)\n" << endl;
			cout << text.info_text() << endl;
		}
		else
		{
			cout << "Good bye!" << endl;
		}

	}while(run == 'r');

}
