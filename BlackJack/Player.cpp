#include "Player.h"

bool Player::win()//win condition for player
{
	int score = getScore();
	if (score == 21)
	{
		return true;
	}
	else
		return false;
}
bool Player::lose()//lose condition for player
{
	int score = getScore();
	if (score > 21)
	{
		return true;
	}
	else
		return false;
}
