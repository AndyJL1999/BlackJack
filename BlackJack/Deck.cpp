#include "Deck.h"
#include "Card.h"

vector<int> Deck::cards;
vector<int> Deck::createDeck()
{
	//Initializing deck array
	static vector<int> deck = { TWO , THREE, FOUR , FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE,
	TWO , THREE, FOUR , FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE,
	TWO , THREE, FOUR , FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE, 
	TWO , THREE, FOUR , FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

	return deck;
}
void Deck::shuffle() //This function shuffles the cards array
{
	for (int i = 0; i < cards.size(); i++)
	{
		swap(cards[i], cards[rand() % cards.size()]);
	}
	cout << "\n\n\tDECK SHUFFLED!\n";
}
void Deck::showDeck() //This function displays the cards array
{
	for (int i = 0; i < cards.size(); i++)
	{
		if (i % 13 == 0)
			cout << endl;
		cout << cards[i] << ", ";
	}
	shuffle();
	for (int i = 0; i < cards.size(); i++)
	{
		if (i % 13 == 0)
			cout << endl;
		cout << cards[i] << ", ";
	}
}
int Deck::deal() //This function returns a random card from the cards array
{
	if (cards.size() <= 0)
	{
		throw string("Out of cards!\n");
	}
	int fDeck = cards.size();
	int randCard = cards[rand() % fDeck];
	vector<int>::iterator it = cards.begin();

	*it = randCard;
	cards.erase(it);

	return randCard;
}
