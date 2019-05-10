#include "Game.h"
#include <iostream>
#include <time.h>

using namespace std;

Game::Game(){};

void Game::play()
{
	Deck deckInPlay;
	deckInPlay.build();
	deckInPlay.shuffle();

	do // Player Number Validation 
	{
		cout << "Please enter the total number of players between 2 and 8." << endl;
		cin >> player_count;
	}

	while (!(player_count > 1 && player_count < 9));

	srand(time(NULL));

	chosen_player_number = rand() % player_count + 1;

	cout << "The Player: " << chosen_player_number + 1 << " is going to be the Banker for this game." << endl;
	cout << "Ace is going have a face value of 1 for this game. " << endl << endl;

	//deckInPlay.display();
	
	for (int i = 0; i < player_count; i++) // Adds new players to array.
	{
		Hand newHand(i);
		hands[i] = newHand;
		
	}

	hands[chosen_player_number].make_Banker(); // Make the designated player the Banker. via bool value



	for (int i = 0; i < player_count; i++) // Initial Deal of First Card
	{
		deal(hands[i], deckInPlay);
		hands[i].display();
	}

	for (int i = 0; i < player_count; i++) // Deal of Second Card
	{
		deal(hands[i], deckInPlay);
		hands[i].display();
		check_winner(hands[i]);
	}

	if (game_is_won == true)
	{
		return;
	}

	do
	{
		cout << "We will now proceed player to player with the choices Twist or Stick." << endl << "Twist is to be a dealt a new card and Stick is to hold \nYou can only Stick if total card value of hand is 15 or greater." << endl;

		for (int i = 0; i < player_count; i++)
		{
			char entry;

			hands[i].display();

			cout << "Player: " << hands[i].get_player_number() << ". Enter 't' for Twist or 's' for Stick" << endl;
			cin >> entry;

			if (hands[i].value() >= 15 && entry == 's')
			{
				cout << "Player: " << hands[i].get_player_number() << " chooses to stick. " << endl;
				hands[i].display();
			}

			else if (entry == 't')
			{
				cout << "Player: " << hands[i].get_player_number() << " is dealt a card." << endl;
				deal(hands[i], deckInPlay);
				hands[i].display();
				check_winner(hands[i]);
			
			}
		}
	}

	while (game_is_won == false);

	cout << "Current Cards Remaining: " << deckInPlay.cards_remaining() << endl;

	

	

};

void Game::deal(Hand &hand, Deck &deck_)
{
	/*if (hand.get_cards_in_hand() < 6)
	{
		do
		{*/
	hand.add(deck_.deal());
		/*}

		while (hand.get_cards_in_hand() < 6);
	}*/
}

void Game::hand_count(Hand &hand, Deck &deck)
{

	if (hand.get_cards_in_hand() < 6)
	{
		deal(hand, deck);
	}

	hand.display();

}

void Game::check_winner(Hand & hand)
{
	if (hand.value() == 21 && hand.is_Banker() == true)
	{
		cout << "The Banker is the Winner - Pontoon" << endl;
		game_is_won = true;
	}

	else if (hand.value() == 21)
	{
		cout << "Player: " << hand.get_player_number() << " is the Winner - Pontoon" << endl;
		game_is_won = true;
	}

	else if (hand.value() > 21)
	{
		cout << "Player: " << hand.get_player_number() << " has gone bust.";
		game_is_won = true;

	}
}

int Game::get_current_winning_hand()
{
	return current_winning_hand;
}

int Game::get_current_winning_hand_value()
{
	return current_winning_hand_value;
}



