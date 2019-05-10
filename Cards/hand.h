#pragma once
#include <vector>
#include "playing_card.hpp"

class Hand
{
private: 

	std::vector <PlayingCard> cards_;
	int cards_in_hand = 0;
	int player_number;
	bool isBanker = false;
	
	

public: 

	Hand();
	Hand(int new_player_number);
	void add(PlayingCard playing_card);
	int value();
	void display();
	int get_cards_in_hand();
	int get_player_number();
	void make_Banker();
	bool is_Banker();
	
	
	


};
