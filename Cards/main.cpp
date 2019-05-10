#include <iostream>
using namespace std;

#include "deck.hpp"
#include "hand.h"
#include "Game.h"

int main()
{
	char again = 'y';
	while (again == 'y')
	{
		cout << "Welcome to Pontoon" << endl;
		Game newgame;
		newgame.play();
		cout << "Do you want to play again? (y/n): " << endl;
		cin >> again;
	}

	cout << "Okay, bye." << endl;

	return 0;
}
