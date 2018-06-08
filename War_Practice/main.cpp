#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

// properties of a Card
class Card
{
    string suit;            // card's suit
    int suitValue;          // dummy variable used for sorting purposes
    int Rank;               // card's ranking
    int value;              // card's value (for card values 2-10)
    string stringValue;     // card's value (for card values A, J, Q, K)
};

// properties of a Player
class Player
{
    string name;            // user's name
    int cardCount;          // number of cards in each player's hand
};

// properties of a pile
class Pile
{
    Card deck[52];          // array of the deck of 52 cards
};

Pile initializeDeck(Pile thePile)
{
    // initializes all cards of suit Clubs
    for(int i=1; i<10; i++)
    {
        // initializes card's value
        thePile.deck[i].value = i+1;

        // initializes card's suit
        thePile.deck[i].suit = "Clubs";

        // initializes card's rank
        thePile.deck[i].Rank = i;
    }
    // some properties need to be implemented manually
    thePile.deck[0].value = 1;
    thePile.deck[0].Rank = 13;
    thePile.deck[0].suit = "Clubs";
    thePile.deck[10].value = 11;
    thePile.deck[10].Rank = 10;
    thePile.deck[10].suit = "Clubs";
    thePile.deck[11].value = 12;
    thePile.deck[11].Rank = 11;
    thePile.deck[11].suit = "Clubs";
    thePile.deck[12].value = 13;
    thePile.deck[12].Rank = 12;
    thePile.deck[12].suit = "Clubs";

    // initializes  cards of suit Spades
    for(int i=14; i<23; i++)
    {
        thePile.deck[i].value = i-12;
        thePile.deck[i].suit = "Spades";
        thePile.deck[i].Rank = i-13;
    }
    thePile.deck[13].value = 1;
    thePile.deck[13].Rank = 13;
    thePile.deck[13].suit = "Spades";
    thePile.deck[23].value = 11;
    thePile.deck[23].Rank = 10;
    thePile.deck[23].suit = "Spades";
    thePile.deck[24].value = 12;
    thePile.deck[24].Rank = 11;
    thePile.deck[24].suit = "Spades";
    thePile.deck[25].value = 13;
    thePile.deck[25].Rank = 12;
    thePile.deck[25].suit = "Spades";

    // initializes  cards of suit Diamonds
    for(int i=27; i<36; i++)
    {
        thePile.deck[i].value = i-25;
        thePile.deck[i].suit = "Diamonds";
        thePile.deck[i].Rank = i-26;
    }
    thePile.deck[26].value = 1;
    thePile.deck[26].Rank = 13;
    thePile.deck[26].suit = "Diamonds";
    thePile.deck[36].value = 11;
    thePile.deck[36].Rank = 10;
    thePile.deck[36].suit = "Diamonds";
    thePile.deck[37].value = 12;
    thePile.deck[37].Rank = 11;
    thePile.deck[37].suit = "Diamonds";
    thePile.deck[38].value = 13;
    thePile.deck[38].Rank = 12;
    thePile.deck[38].suit = "Diamonds";

    // initializes  cards of suit Hearts
    for(int i=40; i<49; i++)
    {
        thePile.deck[i].value = i-38;
        thePile.deck[i].suit = "Hearts";
        thePile.deck[i].Rank = i-39;
    }
    thePile.deck[39].value = 1;
    thePile.deck[39].Rank = 13;
    thePile.deck[39].suit = "Hearts";
    thePile.deck[49].value = 11;
    thePile.deck[49].Rank = 10;
    thePile.deck[49].suit = "Hearts";
    thePile.deck[50].value = 12;
    thePile.deck[50].Rank = 11;
    thePile.deck[50].suit = "Hearts";
    thePile.deck[51].value = 13;
    thePile.deck[51].Rank = 12;
    thePile.deck[51].suit = "Hearts";
    return thePile;
}

// shuffles the deck of cards
Pile shuffleDeck(Pile thePile)
{
    // loops from deck position 51 to 1
    for(int i = 51; i > 0; i--)
    {
        // generates a random position number between 0 and i
        int r = rand() % i;

        // assigns position i as max position
        Card atMax = thePile.deck[i];

        // assigns position r as the random position
        Card atRandom = thePile.deck[r];

        // swaps max position and random position
        thePile.deck[r] = atMax;
        thePile.deck[i] = atRandom;
    }
    return thePile;
}

void getName(Player _player)
{
    cout << "Please enter your name. (Please use underscores instead of spaces.)" << endl;
    getline(cin,_player.name);
    cout << "Hi there, " << _player.name << "!" << endl;
}

int main()
{
    srand(time(NULL));
    string game = "y";
    Card card;
    Player player;
    Pile pile;
    getName(player);
    while (game == "y")
    {
        pile = initializeDeck(pile);
        pile = shuffleDeck(pile);
        game = "?";
        while ((game != "y") and (game != "n"))
        {
            cout << "Play again? (y/n)" <<endl;
            cin >> game;
            if ((game != "y") and (game != "n"))
            {
                cout << "Please give a valid answer." << endl << endl;
            }
        }
        cout << endl << endl << endl << endl;
        if (game == "n")
        {
            break;
        }
    }
    return 0;
}
