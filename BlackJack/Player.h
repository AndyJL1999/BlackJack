#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "Hand.h"
using namespace std;

class Player : virtual public Hand
{
private:
	double money;
	double bet;
public:
	Player()
	{
		money = 0.0;
		bet = 0.0;
	}
	Player(double money, double bet)
	{
		this->money = money;
		this->bet = bet;
	}
	void setMoney(double money)
	{
		this->money = money;
	}
	double getMoney()
	{
		return money;
	}
	void showBet()
	{
		cout << "\n\tYour bet: $" << bet;
	}
	bool win();
	bool lose();
};
#endif 
