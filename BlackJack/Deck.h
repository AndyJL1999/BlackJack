#pragma once
#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <vector>
#include "Card.h"
using namespace std;

class Deck : virtual public Card
{
protected:
	static vector<int> cards;//vector declaration
public:
    void setCards()
	{
		cards = createDeck();
	}
	void addCard()
	{
		displayCard(deal());
	}
	vector<int> createDeck();
	void shuffle();
	void showDeck();
	int deal();
};
#endif
