#pragma once
#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
using namespace std;

class Card
{
protected:
	enum RANK { TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7,
		EIGHT = 8, NINE = 9, TEN = 10, JACK = 10, QUEEN = 11, KING = 12, ACE = 13};
	int scoreTotal = 0;
public:
	void setScore(int score)
	{
		scoreTotal = score;
	}
	int getScore()
	{
		return scoreTotal;
	}
	void showScore();
	void displayCard(int card);
};
#endif
