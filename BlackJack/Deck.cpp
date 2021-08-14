#include "Deck.h"
#include "Card.h"

int* Deck::createDeck()
{
	//Initializing deck array
	static int deck[52] = { TWO , THREE, FOUR , FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE,
	TWO , THREE, FOUR , FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE,
	TWO , THREE, FOUR , FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE, 
	TWO , THREE, FOUR , FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

	return deck;
}
void Deck::shuffle() //This function shuffles the cards array
{
	setCards();
	for (int i = 0; i < 52; i++)
	{
		swap(cards[i], cards[rand() % 52]);
	}
	cout << "\n\n\tDECK SHUFFLED!\n";
}
void Deck::showDeck() //This function displays the cards array
{
	setCards();
	for (int i = 0; i < 52; i++)
	{
		if (i % 13 == 0)
			cout << endl;
		cout << cards[i] << ", ";
	}
	shuffle();
	for (int i = 0; i < 52; i++)
	{
		if (i % 13 == 0)
			cout << endl;
		cout << cards[i] << ", ";
	}
}
int Deck::deal() //This function returns a random card from the cards array
{
	setCards();
	int fDeck = 52;
	int randCard = cards[rand() % fDeck];

	return randCard;
}
