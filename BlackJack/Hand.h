#pragma once
#ifndef HAND_H
#define HAND_H
#include "Card.h"
#include "Deck.h"
class Hand : virtual public Card, Deck
{
public:
	void addCard()
	{
		displayCard(deal());
	}
};
#endif
