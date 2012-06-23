#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <limits>
using namespace std;
#include "processing.h"
#include "player.h"
#include "rangeexception.h"



void CPlayer::set_code_generator()
{
	srand (time(NULL));
	for(int i=0; i<4; i++)
	{
		code[i] = rand() % 6 + 1;
	}
}

void CPlayer::set_code(int &ccounter, char &ccache)
{
	ccache='r';
	cout << "Player " << ccounter << " INITIAL code(press ENTER after each number): \n";

	for(int i = 0; i < 4 ; i++)
	{
		cin >> code[i];

		if (cin.fail() )
			{
				cout << "Oops, please don't enter chars, try again with a digit between 1-5\n";
				cin.clear();
				cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n' );
				--i;
			}
		else if (code[i]<=0 || code[i]>5)
				throw CRangeException();

	}


	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	ccounter++;
	ccache='s';
}

void CPlayer::set_attempt(int &ccounter2, int &choice, char &ccache)
{
	ccache='r';
	cout << "Player " << ccounter2 << " code(press ENTER after each number): \n";

	for(int i = 0; i < 4 ; i++)
	{
		cin >> attempt[i];

		if (cin.fail() )
			{
				cout << "Oops, please don't enter chars, try again with a digit between 1-5\n";
				cin.clear();
				cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n' );
				--i;
			}
		else if (attempt[i]<=0 || attempt[i]>5)
				throw CRangeException();


	}

	ccache='s';
	if(choice!=1)
		ccounter2++;
}
