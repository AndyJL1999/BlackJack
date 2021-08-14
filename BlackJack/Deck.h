#pragma once
#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <stdio.h>
#include <ctime>
#include "Card.h"
using namespace std;

class Deck : virtual public Card
{
protected:
	int* cards;//array declaration
public:
	void setCards()
	{
		cards = createDeck();
	}
	int *createDeck();
	void shuffle();
	void showDeck();
	int deal();
};
#endif
