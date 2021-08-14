#pragma once
#ifndef GAME_H
#define GAME_H
#include "Deck.h"
#include "Player.h"

class Game : virtual public Deck
{
private:
	Deck deck;

public:
	void play();
	void moneyUI();
	Game()
	{
		deck.setCards();
	}

};

#endif
