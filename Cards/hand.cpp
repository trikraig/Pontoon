#include "hand.h"
#include "deck.hpp"
#include <iostream>

using namespace std;

Hand::Hand() //default constructor
{
}

Hand::Hand(int new_player_number) //allows player number to be passed as value in constructor
{
	player_number = new_player_number + 1;
}

void Hand::add(PlayingCard playing_card)
{
	cards_.push_back(playing_card);
	cards_in_hand++;
	
};

int Hand::value() // calculates total value of hand instance.
{
	int sumOfCards {0};

	for (PlayingCard card : cards_)
	{
		sumOfCards += card.getFaceValue();
	}

	return sumOfCards;

};
void Hand::display() // displays hand instance.
{
	if (isBanker == true)
	{
		std::cout << "Banker's hand." << endl;
	}

	else
	{
		std::cout << "Player's hand: " << player_number << endl;
	}

	for (PlayingCard card : cards_)
	{
		switch (card.getSuit())
		{

		case 1:
			std::cout << "Club ";
			break;
		case 2:
			std::cout << "Diamond ";
			break;
		case 3:
			std::cout << "Spade ";
			break;
		case 4:
			std::cout << "Heart ";
			break;

		default:
			break;
		}

		switch (card.getFaceValue())
		{

		case 1:
			std::cout << "Ace " << endl;
			break;

		case 11:
			std::cout << "Jack " << endl;
			break;
		case 12:
			std::cout << "Queen " << endl;
			break;
		case 13:
			std::cout << "King " << endl;
			break;

		default:
			std::cout << card.getFaceValue() << " " << endl;
			break;
		}
	}

	std::cout << "Total Value is: " << value() << endl << endl;

};

int Hand::get_cards_in_hand()
{
	return cards_in_hand;
}

int Hand::get_player_number()
{
	return player_number;
}

bool Hand::is_Banker()
{
	return isBanker;
}

void Hand::make_Banker()
{
	isBanker = true;
}



