#include "Game.h"
#include "Deck.h"
#include <iomanip>
double cash;//Global declaration

void Game::play()
{
    srand(time(0));//random number generator - used in Deck.cpp
    //initialization
    char choice = ' ';
    double bet = 0;

    cout << "Money: $" << cash << endl;//Displays money after every round
    cout << "How much will you be betting? $";
    cin >> bet;
    while (bet > cash || cin.fail())
    {
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Please enter numbers only no characters! Try again. - $";
            cin >> bet;
        }
        else
        {
            cout << "You cannot bet more than your total money. Try again. - $";
            cin >> bet;
        }
    }

    Player player(cash, bet);//player object
    player.showBet();//display the bet
    cout << endl;

    Player dealer;//computer object

    Deck deck;
    deck.createDeck();
    deck.showDeck();//Displays deck and shuffles it
    cout << endl << endl;

    cout << "\tPlayer\t\t\t\t" << "Computer\n";
    cout << "__________________________________________________________________________\n";

    player.addCard();//Gives player a card
    player.showScore();
    cout << "\t|" << setw(20);
    dealer.addCard();//Gives computer a card
    dealer.showScore();
    cout << endl;

    cout << "\nDo you want to hit or stand? (h/s) ";
    cin >> choice;
    while (choice != 'h' && choice != 's')//while loop to ensure player only presses 'h' or 's'
    {
        cout << "Press 'h' to hit and 's' to stand no other choices. ";
        cin >> choice;
    }
    while (choice == 'h')//while loop that takes players decision to hit
    {
        player.addCard();
        player.showScore();

        if (player.win())// if statement to determine if player wins
        {
            cout << "\n****BlackJack! You Win!****\n";
            cash += (bet*2);//adding to money
            break;//end loop
        }
        else if (player.lose())//determines if player loses
        {
            cout << "\n\n****Bust! You Lose!****\n";
            cash -= bet;//subtracting from money
            break;
        }

        cout << "\nDo you want to hit or stand? (h/s) ";
        cin >> choice;

        while (choice != 'h' && choice != 's')
        {
            cout << "Press 'h' to hit and 's' to stand no other choices. ";
            cin >> choice;
        }

    } 

    if (choice == 's')//if player decides to stand the computer hits
    {
        cout << setw(55);
        cout << "__________________________________________________________________________\n";
        cout << "\t\t\tComputer is drawing\n\n";

        cout << "\tPlayer\t\t\t\t" << "Computer\n";
        cout << "__________________________________________________________________________\n";
  
        player.showScore();
        cout << "\t\t|" << setw(30);
        dealer.showScore();
        cout << endl;

        while (dealer.getScore() < 18)
        {
            cout << setw(25);
            cout << "|" << setw(20);
            dealer.addCard();
            cout << " ";
            dealer.showScore();
            cout << endl;

            if (dealer.getScore() == 21 || dealer.getScore() > player.getScore() && dealer.getScore() < 21)//If coomputer score equal 21 they win && if computer score is greater than the player's but less than 21
            {
                cout << "\n\t\t*********Computer Wins!********\n";
                cash -= bet;
                break;
            }
            else if (dealer.getScore() > 21)//if computer goes over 21 they bust and player wins
            {
                cout << "\n\t\t*****Computer Bust! Player Wins!*****\n";
                cash += (bet*2);
                break;
            }
            else if (dealer.getScore() >= 18 && dealer.getScore() < player.getScore())//if computer is over 18 but under 21 and the player still has higher score
            {
                cout << "\n\t\t**********Player Wins!***********\n";
                cash += (bet * 2);
                break;
            }
            else if (dealer.getScore() == player.getScore() && dealer.getScore() > 18)//if dealer and player have the same score its a tie
            {
                cout << "\n\t\t*****TIE!*****\n";
                break;
            }

        }

    }

    cout << endl;

    if (cash == 0)//If player runs out of money the game is over
    {
        cout << "Out of Money! GAME OVER!\n";
        exit(0);
    }
}
void Game::moneyUI()
{
    cout << "\t\t\tWelcome to Blackjack!\n\n";
    cout << "Rules: The player will have the chance to bet only once before given the cards.\n" <<
        "The player can choose to take as many cards as they want as long as the player is under 21.\n" <<
        "The computer can take as many cards as they want unless the computer is over 18.\n" <<
        "Whomever has the closest to 21 wins.\n" <<
        "If one of them is over 21, the other wins.\n" <<
        "If they both have the same amount, then it is a tie.\n" <<
        "All face cards count as 10 and the Ace counts as 11 only. \n\n";

    cout << "How much money do you have? $";
    cin >> cash;
    while (cash > 5000 || cin.fail())
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Please enter numbers only no characters! Try again. - $";
            cin >> cash;
        }
        else
        {
            cout << "The cap is $5000. Try again. - $";
            cin >> cash;
        }
    }
}