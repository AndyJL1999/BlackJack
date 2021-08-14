// BlackJack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "Game.h"
using namespace std;
int main()
{
    char choice;
    Game UI;
    UI.moneyUI();
    do
    {
        system("cls");
        Game CasinoTime;

        CasinoTime.play();
        cout << "Do you want to play again? (y/n)\n";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    
    cout << "\nGood Bye!\n";
    return 0;
}
