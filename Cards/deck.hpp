#pragma once

#include "playing_card.hpp"
#include <vector>


class Deck
{
private:
	
	int next_card_to_deal{ 0 };
	std::vector <PlayingCard> current_deck;
	

public: 

	int cards_remaining();
	void build();
	void shuffle();
	void display();
	PlayingCard deal();
};


