#pragma once
#include "hand.h"
#include "deck.hpp"
#define TOTAL_HANDS 8

class Game
{
private: 

	int chosen_player_number;
	int player_count;
	Deck deck;
	Hand hands[TOTAL_HANDS];
	int current_winning_hand;
	int current_winning_hand_value;
	bool game_is_won = false;
	

public: 
	Game();
	void play();
	void deal(Hand &hand, Deck &deck);
	void hand_count(Hand &hand, Deck &deck);
	void check_winner(Hand &hand);
	int get_current_winning_hand();
	int get_current_winning_hand_value();
}
;