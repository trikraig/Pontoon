#include "playing_card.hpp"

PlayingCard::PlayingCard()
{
}


PlayingCard::PlayingCard(int newSuit, int newValue)
{
	suit = newSuit;
	face_value = newValue;

}

int PlayingCard::getFaceValue()
{
	return face_value;
}

int PlayingCard::getSuit()
{
	return suit;
}
