#include "deck.hpp"
#include "hand.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int Deck::cards_remaining()
{
	return current_deck.size();
}

void Deck::build() // empties the deck vector array and inserts new cards
{
	current_deck.clear();

	for (int suit = 1; suit < 5; suit++)
	{
		for (int value = 1; value < 13; value++)
		{
			PlayingCard newCard(suit, value);
			current_deck.push_back(newCard);
		}
	}
};

void Deck::display() //outputs the deck of cards
{
	  
	for (int i = 0; i < current_deck.size(); i++)
	{
		PlayingCard value = current_deck[i];

		switch (value.getSuit())
		{

		case 1:
			cout << "Club ";
			break;
		case 2:
			cout << "Diamond ";
			break;
		case 3:
			cout << "Spade ";
			break;
		case 4:
			cout << "Heart ";
			break;
		
		default:
			break;
		}

		switch (value.getFaceValue())
		{

		case 1:
			cout << "Ace " << endl;
			break;

		case 11:
			cout << "Jack " << endl;
			break;
		case 12:
			cout << "Queen " << endl;
			break;
		case 13:
			cout << "King " << endl;
			break;

		default:
			cout << value.getFaceValue() << " " << endl;
			break;
		}

		
		
	}

	

}

void Deck::shuffle() //atempts to randomise the cards in the vector array.

{
		srand(time(NULL));

	for (int i = 0; i < current_deck.size(); i++) 
	{ 
		int randomIndex = rand() % current_deck.size();
		PlayingCard temp1;
		PlayingCard temp2;

		temp1 = current_deck[i];
		temp2 = current_deck[randomIndex];

		current_deck[i] = temp2;
		current_deck[randomIndex] = temp1;
		
	}

}

PlayingCard Deck::deal() //Returns and removes one card from the current deck in play.
{
	PlayingCard dealtCard = current_deck.back();
	current_deck.pop_back();

	return dealtCard;

}


