#pragma once

class PlayingCard
{
private: int face_value;
		 int suit;
		/* friend inline ostream& operator<<(ostream& os, const PlayingCard& var);*/


public: 
	PlayingCard();
	PlayingCard(int newSuit, int newValue);
	int getFaceValue();
	int getSuit();
};

//inline ostream& operator<<(ostream& os, const PlayingCard& var);
