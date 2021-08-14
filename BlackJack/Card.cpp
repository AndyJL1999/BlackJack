#include "Card.h"

void Card::displayCard(int card)
{

	if (card == ACE)
	{
		cout << "Drew an ACE = 11";
		scoreTotal += 11;
	}
	else if (card == KING)
	{
		cout << "Drew a KING = 10";
		scoreTotal += 10;
	}
	else if (card == QUEEN)
	{
		cout << "Drew a QUEEN = 10";
		scoreTotal += 10;
	}
	else if (card == JACK)
	{
		cout << "Drew a JACK = 10";
		scoreTotal += 10;
	}
	else if (card == TEN)
	{
		cout << "Drew a 10";
		scoreTotal += TEN;
	}
	else if (card == NINE)
	{
		cout << "Drew a 9";
		scoreTotal += NINE;
	}
	else if (card == EIGHT)
	{
		cout << "Drew an 8";
		scoreTotal += EIGHT;
	}
	else if (card == SEVEN)
	{
		cout << "Drew a 7";
		scoreTotal += SEVEN;
	}
	else if (card == SIX)
	{
		cout << "Drew a 6";
		scoreTotal += SIX;
	}
	else if (card == FIVE)
	{
		cout << "Drew a 5";
		scoreTotal += FIVE;
	}
	else if (card == FOUR)
	{
		cout << "Drew a 4";
		scoreTotal += FOUR;
	}
	else if (card == THREE)
	{
		cout << "Drew a 3";
		scoreTotal += THREE;
	}
	else if (card == TWO)
	{
		cout << "Drew a 2";
		scoreTotal += TWO;
	}
}
void Card::showScore()
{
	cout << "  Score: " << getScore();
}
