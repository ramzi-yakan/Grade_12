//Ramzi Yakan
//Card Game

// Note: Code might break after the completion of your first turn.

#include <iostream>
#include <stdlib.h>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// properties of a Card
struct Card
{
    string suit;            // card's suit
    int suitValue;          // dummy variable used for sorting purposes
    int Rank;               // card's ranking
    int value;              // card's value (for card values 2-10)
    string stringValue;     // card's value (for card values A, J, Q, K)
    bool cardPlayed;        // checks if a particular card has been played
};

// properties of a Player
struct Player
{
    string name;            // user's name
    int cardCount;          // number of cards in each player's hand
    int userPoints;         // number of points the user has recieved as a result of picking up hearts and/or the queen of spades
    int computer1Points;    // number of points Computer_1 has recieved as a result of picking up hearts and/or the queen of spades
    int computer2Points;    // number of points Computer_2 has recieved as a result of picking up hearts and/or the queen of spades
    int computer3Points;
    string winner;    // number of points Computer_3 has recieved as a result of picking up hearts and/or the queen of spades
};

// properties of a pile
struct Pile
{
    Card deck[52];          // array of the deck of 52 cards
    int position;           // position of a particular card in the deck
    int randomPositionComputer1;    // generates a random position number between 13 and 26
    int randomPositionComputer2;    // generates a random position number between 26 and 39
    int randomPositionComputer3;    // generates a random position number between 39 and 52
    string leadingSuit;     // leading suit of a trick
    int numberOfLeadingSuit;        // counts the number of cards a player has of the leading suit
};

Pile sortHand(Pile thePile)
{
    Card buffer;
    for (int i = 0; i < 13; i++)
    {
            if (thePile.deck[i].suit == "Clubs")
            {
                thePile.deck[i].suitValue = 1;
            }
            else if (thePile.deck[i].suit == "Spades")
            {
                thePile.deck[i].suitValue = 2;
            }
            else if (thePile.deck[i].suit == "Diamonds")
            {
                thePile.deck[i].suitValue = 3;
            }
            else
            {
                thePile.deck[i].suitValue = 4;
            }
            for (int j = i-1; j >= 0; j--)
            {
                if (thePile.deck[j+1].suitValue > thePile.deck[j].suitValue)
                {
                    buffer = thePile.deck[j+1];
                    thePile.deck[j+1] = thePile.deck[j];
                    thePile.deck[j] = buffer;
                }
                if (thePile.deck[j+1].suit == thePile.deck[j].suit)
                {
                    if (thePile.deck[j+1].Rank < thePile.deck[j].Rank)
                    {
                        buffer = thePile.deck[j+1];
                        thePile.deck[j+1] = thePile.deck[j];
                        thePile.deck[j] = buffer;
                    }
                }
            }
            thePile.deck[i].cardPlayed = false;
    }
    for (int i = 13; i < 26; i++)
    {
            for (int j = i-1; j >= 13; j--)
            {
                if (thePile.deck[j+1].Rank < thePile.deck[j].Rank)
                {
                    buffer = thePile.deck[j+1];
                    thePile.deck[j+1] = thePile.deck[j];
                    thePile.deck[j] = buffer;
                }
            }
            thePile.deck[i].cardPlayed = false;
    }
    for (int i = 26; i < 39; i++)
    {
            for (int j = i-1; j >= 26; j--)
            {
                if (thePile.deck[j+1].Rank < thePile.deck[j].Rank)
                {
                    buffer = thePile.deck[j+1];
                    thePile.deck[j+1] = thePile.deck[j];
                    thePile.deck[j] = buffer;
                }
            }
            thePile.deck[i].cardPlayed = false;
    }
    for (int i = 39; i < 52; i++)
    {
            for (int j = i-1; j >= 39; j--)
            {
                if (thePile.deck[j+1].Rank < thePile.deck[j].Rank)
                {
                    buffer = thePile.deck[j+1];
                    thePile.deck[j+1] = thePile.deck[j];
                    thePile.deck[j] = buffer;
                }
            }
            thePile.deck[i].cardPlayed = false;
    }
    return thePile;
}

// displays the user's hand of 13 cards, along with each card's important properties
Pile displayCard(Card theCard, Pile thePile)
{
    for(int i = 0; i < 13; i++)
    {
        if (thePile.deck[i].cardPlayed == false)
        {
            cout << "Card " << i+1 << endl;
            cout << "Value: ";
            if (thePile.deck[i].value == 1)
            {
                thePile.deck[i].stringValue = "A";
                cout << thePile.deck[i].stringValue << endl;
            }
            else if (thePile.deck[i].value == 11)
            {
                thePile.deck[i].stringValue = "J";
                cout << thePile.deck[i].stringValue << endl;
            }
            else if (thePile.deck[i].value == 12)
            {
                thePile.deck[i].stringValue = "Q";
                cout << thePile.deck[i].stringValue << endl;
            }
            else if (thePile.deck[i].value == 13)
            {
                thePile.deck[i].stringValue = "K";
                cout << thePile.deck[i].stringValue << endl;
            }
            else
            {
                cout << thePile.deck[i].value << endl;
            }
            cout << "Suit: ";
            cout << thePile.deck[i].suit << endl;
            cout << endl;
        }
    }
    return thePile;
}

// displays the amount of cards each player has remaining in their hand
Player displayDeck(Pile thePile, Player thePlayer)
{
    if (thePlayer.cardCount != 0)
    {
        cout << thePlayer.name << " ";
        cout << thePlayer.cardCount << " cards";
        cout << endl << endl << endl;
        cout << "Computer_1 ";
        cout << thePlayer.cardCount << " cards";
        cout << endl << endl << endl;
        cout << "Computer_2 ";
        cout << thePlayer.cardCount << " cards";
        cout << endl << endl << endl;
        cout << "Computer_3 ";
        cout << thePlayer.cardCount << " cards";
        cout << endl;
    }
    else
    {
        cout << "End of game.";         // game ends once all players are out of cards
    }
    return thePlayer;
}

// creates each card in the deck
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

Player checkWinnerOfTrick(Player thePlayer, Pile thePile)
{
    cout << endl;
    thePile.numberOfLeadingSuit = 0;
    if (thePlayer.winner != "Computer_1")
    {
        for (int i = 13; i < 26; i++)
        {
            if (thePile.deck[i].suit == thePile.leadingSuit)
            {
                if (thePile.deck[i].cardPlayed == false)
                {
                    thePile.numberOfLeadingSuit++;
                    if (thePile.numberOfLeadingSuit != 0)
                    {
                        break;
                    }
                }
            }
        }
        if (thePile.numberOfLeadingSuit != 0)
        {
            while ((thePile.deck[thePile.randomPositionComputer1].suit != thePile.leadingSuit) and (thePile.deck[thePile.randomPositionComputer1].cardPlayed == true))
            {
                thePile.randomPositionComputer1 = (rand() % 13) + 13;
            }
        }
        else
        {
            while (thePile.deck[thePile.randomPositionComputer1].cardPlayed == true)
            {
                thePile.randomPositionComputer1 = (rand() % 13) + 13;
            }
        }
    }
    thePile.numberOfLeadingSuit = 0;
    if (thePlayer.winner != "Computer_2")
    {
        for (int i = 26; i < 39; i++)
        {
            if (thePile.deck[i].suit == thePile.leadingSuit)
            {
                if (thePile.deck[i].cardPlayed == false)
                {
                    thePile.numberOfLeadingSuit++;
                    if (thePile.numberOfLeadingSuit != 0)
                    {
                        break;
                    }
                }
            }
        }
        if (thePile.numberOfLeadingSuit != 0)
        {
            while ((thePile.deck[thePile.randomPositionComputer2].suit != thePile.leadingSuit) and (thePile.deck[thePile.randomPositionComputer2].cardPlayed == true))
            {
                thePile.randomPositionComputer2 = (rand() % 13) + 26;
            }
        }
        else
        {
            while (thePile.deck[thePile.randomPositionComputer2].cardPlayed == true)
            {
                thePile.randomPositionComputer2 = (rand() % 13) + 26;
            }
        }
    }
    thePile.numberOfLeadingSuit = 0;
    if (thePlayer.winner != "Computer_3")
    {
        for (int i = 39; i < 52; i++)
        {
            if (thePile.deck[i].suit == thePile.leadingSuit)
            {
                if (thePile.deck[i].cardPlayed == false)
                {
                    thePile.numberOfLeadingSuit++;
                    if (thePile.numberOfLeadingSuit != 0)
                    {
                        break;
                    }
                }
            }
        }
        if (thePile.numberOfLeadingSuit != 0)
        {
            while ((thePile.deck[thePile.randomPositionComputer3].suit != thePile.leadingSuit) and (thePile.deck[thePile.randomPositionComputer3].cardPlayed == true))
            {
                thePile.randomPositionComputer3 = (rand() % 13) + 39;
            }
        }
        else
        {
            while (thePile.deck[thePile.randomPositionComputer3].cardPlayed == true)
            {
                thePile.randomPositionComputer3 = (rand() % 13) + 39;
            }
        }
    }
    thePile.deck[thePile.randomPositionComputer1].cardPlayed = true;
    thePile.deck[thePile.randomPositionComputer2].cardPlayed = true;
    thePile.deck[thePile.randomPositionComputer3].cardPlayed = true;
    if ((thePile.deck[thePile.position-1].Rank > thePile.deck[thePile.randomPositionComputer1].Rank) and (thePile.deck[thePile.position-1].Rank > thePile.deck[thePile.randomPositionComputer2].Rank) and (thePile.deck[thePile.position-1].Rank > thePile.deck[thePile.randomPositionComputer3].Rank))
    {
        thePlayer.winner = "Player";
        cout << "You take the pile." << endl;
        if ((thePile.deck[thePile.position-1].suit == "Hearts") or (thePile.deck[thePile.randomPositionComputer1].suit == "Hearts") or (thePile.deck[thePile.randomPositionComputer2].suit == "Hearts") or (thePile.deck[thePile.randomPositionComputer3].suit == "Hearts"))
        {
            if (thePile.deck[thePile.position-1].suit == "Hearts")
            {
                thePlayer.userPoints++;
            }
            if (thePile.deck[thePile.randomPositionComputer1].suit == "Hearts")
            {
                thePlayer.userPoints++;
            }
            if (thePile.deck[thePile.randomPositionComputer2].suit == "Hearts")
            {
                thePlayer.userPoints++;
            }
            if (thePile.deck[thePile.randomPositionComputer3].suit == "Hearts")
            {
                thePlayer.userPoints++;
            }
            cout << "Uh oh! You have picked up some hearts. You now have " << thePlayer.userPoints << " points." << endl;
        }
        if (((thePile.deck[thePile.position-1].value == 12) and (thePile.deck[thePile.position-1].suit == "Spades")) or ((thePile.deck[thePile.randomPositionComputer1].value == 12) and (thePile.deck[thePile.randomPositionComputer1].suit == "Spades")) or ((thePile.deck[thePile.randomPositionComputer2].value == 12) and (thePile.deck[thePile.randomPositionComputer2].suit == "Spades")) or ((thePile.deck[thePile.randomPositionComputer3].value == 12) and (thePile.deck[thePile.randomPositionComputer3].suit == "Spades")))
        {
            thePlayer.userPoints = thePlayer.userPoints + 13;
            cout << "Oh dear!!! You have picked up the queen of spades. You now have " << thePlayer.userPoints << " points." << endl;
        }
        if (thePlayer.userPoints == 26)
        {
            cout << "Congrats!!! You've just shot the moon and won the game!" <<endl;
        }
    }
    else if ((thePile.deck[thePile.randomPositionComputer1].Rank > thePile.deck[thePile.randomPositionComputer2].Rank) and (thePile.deck[thePile.randomPositionComputer1].Rank > thePile.deck[thePile.randomPositionComputer3].Rank) and (thePile.deck[thePile.randomPositionComputer1].Rank > thePile.deck[thePile.position-1].Rank))
    {
        thePlayer.winner = "Computer_1";
        cout << "Computer_1 takes the pile." << endl;
        if ((thePile.deck[thePile.position-1].suit == "Hearts") or (thePile.deck[thePile.randomPositionComputer1].suit == "Hearts") or (thePile.deck[thePile.randomPositionComputer2].suit == "Hearts") or (thePile.deck[thePile.randomPositionComputer3].suit == "Hearts"))
        {
            if (thePile.deck[thePile.position-1].suit == "Hearts")
            {
                thePlayer.computer1Points++;
            }
            if (thePile.deck[thePile.randomPositionComputer1].suit == "Hearts")
            {
                thePlayer.computer1Points++;
            }
            if (thePile.deck[thePile.randomPositionComputer2].suit == "Hearts")
            {
                thePlayer.computer1Points++;
            }
            if (thePile.deck[thePile.randomPositionComputer3].suit == "Hearts")
            {
                thePlayer.computer1Points++;
            }
            cout << "Yes! Computer_1 has picked up some hearts. They now have " << thePlayer.computer1Points << " points." << endl;
        }
        if (((thePile.deck[thePile.position-1].value == 12) and (thePile.deck[thePile.position-1].suit == "Spades")) or ((thePile.deck[thePile.randomPositionComputer1].value == 12) and (thePile.deck[thePile.randomPositionComputer1].suit == "Spades")) or ((thePile.deck[thePile.randomPositionComputer2].value == 12) and (thePile.deck[thePile.randomPositionComputer2].suit == "Spades")) or ((thePile.deck[thePile.randomPositionComputer3].value == 12) and (thePile.deck[thePile.randomPositionComputer3].suit == "Spades")))
        {
            thePlayer.computer1Points = thePlayer.computer1Points + 13;
            cout << "Amazing!!! Computer_1 has picked up the queen of spades. They now have " << thePlayer.computer1Points << " points." << endl;
        }
        if (thePlayer.computer1Points == 26)
        {
            cout << "*sigh* Computer_1 has just shot the moon and won the game!" <<endl;
        }
    }
    else if ((thePile.deck[thePile.randomPositionComputer2].Rank > thePile.deck[thePile.randomPositionComputer3].Rank) and (thePile.deck[thePile.randomPositionComputer2].Rank > thePile.deck[thePile.position-1].Rank) and (thePile.deck[thePile.randomPositionComputer2].Rank > thePile.deck[thePile.randomPositionComputer1].Rank))
    {
        thePlayer.winner = "Computer_2";
        cout << "Computer_2 takes the pile." << endl;
        if ((thePile.deck[thePile.position-1].suit == "Hearts") or (thePile.deck[thePile.randomPositionComputer1].suit == "Hearts") or (thePile.deck[thePile.randomPositionComputer2].suit == "Hearts") or (thePile.deck[thePile.randomPositionComputer3].suit == "Hearts"))
        {
            if (thePile.deck[thePile.position-1].suit == "Hearts")
            {
                thePlayer.computer2Points++;
            }
            if (thePile.deck[thePile.randomPositionComputer1].suit == "Hearts")
            {
                thePlayer.computer2Points++;
            }
            if (thePile.deck[thePile.randomPositionComputer2].suit == "Hearts")
            {
                thePlayer.computer2Points++;
            }
            if (thePile.deck[thePile.randomPositionComputer3].suit == "Hearts")
            {
                thePlayer.computer2Points++;
            }
            cout << "Yes! Computer_2 has picked up some hearts. They now have " << thePlayer.computer2Points << " points." << endl;
        }
        if (((thePile.deck[thePile.position-1].value == 12) and (thePile.deck[thePile.position-1].suit == "Spades")) or ((thePile.deck[thePile.randomPositionComputer1].value == 12) and (thePile.deck[thePile.randomPositionComputer1].suit == "Spades")) or ((thePile.deck[thePile.randomPositionComputer2].value == 12) and (thePile.deck[thePile.randomPositionComputer2].suit == "Spades")) or ((thePile.deck[thePile.randomPositionComputer3].value == 12) and (thePile.deck[thePile.randomPositionComputer3].suit == "Spades")))
        {
            thePlayer.computer2Points = thePlayer.computer2Points + 13;
            cout << "Amazing!!! Computer_2 has picked up the queen of spades. They now have " << thePlayer.computer2Points << " points." << endl;
        }
        if (thePlayer.computer2Points == 26)
        {
            cout << "*sigh* Computer_2 has just shot the moon and won the game!" <<endl;
        }
    }
    else
    {
        thePlayer.winner = "Computer_3";
        cout << "Computer_3 takes the pile." << endl;
        if ((thePile.deck[thePile.position-1].suit == "Hearts") or (thePile.deck[thePile.randomPositionComputer1].suit == "Hearts") or (thePile.deck[thePile.randomPositionComputer2].suit == "Hearts") or (thePile.deck[thePile.randomPositionComputer3].suit == "Hearts"))
        {
            if (thePile.deck[thePile.position-1].suit == "Hearts")
            {
                thePlayer.computer3Points++;
            }
            if (thePile.deck[thePile.randomPositionComputer1].suit == "Hearts")
            {
                thePlayer.computer3Points++;
            }
            if (thePile.deck[thePile.randomPositionComputer2].suit == "Hearts")
            {
                thePlayer.computer3Points++;
            }
            if (thePile.deck[thePile.randomPositionComputer3].suit == "Hearts")
            {
                thePlayer.computer3Points++;
            }
            cout << "Yes! Computer_3 has picked up some hearts. They now have " << thePlayer.computer3Points << " points." << endl;
        }
        if (((thePile.deck[thePile.position-1].value == 12) and (thePile.deck[thePile.position-1].suit == "Spades")) or ((thePile.deck[thePile.randomPositionComputer1].value == 12) and (thePile.deck[thePile.randomPositionComputer1].suit == "Spades")) or ((thePile.deck[thePile.randomPositionComputer2].value == 12) and (thePile.deck[thePile.randomPositionComputer2].suit == "Spades")) or ((thePile.deck[thePile.randomPositionComputer3].value == 12) and (thePile.deck[thePile.randomPositionComputer3].suit == "Spades")))
        {
            thePlayer.computer3Points = thePlayer.computer3Points + 13;
            cout << "Amazing!!! Computer_3 has picked up the queen of spades. They now have " << thePlayer.computer3Points << " points." << endl;
        }
        if (thePlayer.computer3Points == 26)
        {
            cout << "*sigh* Computer_3 has just shot the moon and won the game!" <<endl;
        }
    }
    cout << endl << endl << endl;
    return thePlayer;
}

Player takePlayerTurn (Card theCard, Player thePlayer, Pile thePile)
{
        thePile = displayCard(theCard, thePile);
        thePlayer = displayDeck(thePile, thePlayer);
        cout << endl << endl << endl;
        cout << "It's your turn. Indicate the card you wish to play." << endl;
        cout << "Leading Suit: " << thePile.leadingSuit << endl;
        thePile.position = 14;
        thePile.numberOfLeadingSuit = 0;
        for (int i = 0; i < 13; i++)
        {
            if (thePile.deck[i].cardPlayed == false)
            {
                if (thePile.deck[i].suit == thePile.leadingSuit)
                {
                    thePile.numberOfLeadingSuit++;
                    if (thePile.numberOfLeadingSuit != 0)
                    {
                        break;
                    }
                }
            }
        }
        if (thePile.numberOfLeadingSuit == 0)
        {
            while ((thePile.position < 1) or (thePile.position > 13) or (thePile.deck[thePile.position-1].cardPlayed == true))
            {
                cin >> thePile.position;
                if ((thePile.position < 1) or (thePile.position > 13) or (thePile.deck[thePile.position-1].cardPlayed == true))
                {
                    cout << "Not a valid position. Please enter a different position." << endl;
                }
            }
        }
        else
        {
            while ((thePile.position < 1) or (thePile.position > 13) or (thePile.deck[thePile.position-1].cardPlayed == true) or (thePile.deck[thePile.position-1].suit != thePile.leadingSuit))
            {
                cin >> thePile.position;
                if ((thePile.position < 1) or (thePile.position > 13) or (thePile.deck[thePile.position-1].cardPlayed == true) or (thePile.deck[thePile.position-1].suit != thePile.leadingSuit))
                {
                    cout << "Not a valid position. Please enter a different position." << endl;
                }
            }
        }
        if (thePlayer.winner == "Player")
        {
            thePile.leadingSuit = thePile.deck[thePile.position-1].suit;
        }
        thePlayer = checkWinnerOfTrick(thePlayer, thePile);

    return thePlayer;
}

// displays each player's final score, then displays a message based on who has the least amount of points
void endOfGameStats (Player thePlayer, string _game)
{
    cout << "Total Points:" << endl;
    cout << thePlayer.name << ": " << thePlayer.userPoints << endl;
    cout << "Computer_1: " << thePlayer.computer1Points << endl;
    cout << "Computer_2: " << thePlayer.computer2Points << endl;
    cout << "Computer_3: " << thePlayer.computer3Points << endl;
    cout << endl;
    if ((thePlayer.userPoints < thePlayer.computer1Points) and (thePlayer.userPoints < thePlayer.computer2Points) and (thePlayer.userPoints < thePlayer.computer3Points))
    {
        cout << "Congratulations!!! You have won the game!" << endl;
    }
    else if ((thePlayer.computer1Points < thePlayer.userPoints) and (thePlayer.computer1Points < thePlayer.computer2Points) and (thePlayer.computer1Points < thePlayer.computer3Points))
    {
        cout << "Unlucky!!! Computer_1 has won the game!" << endl;
    }
    else if ((thePlayer.computer2Points < thePlayer.userPoints) and (thePlayer.computer2Points < thePlayer.computer1Points) and (thePlayer.computer2Points < thePlayer.computer3Points))
    {
        cout << "Unlucky!!! Computer_2 has won the game!" << endl;
    }
    else if ((thePlayer.computer3Points < thePlayer.userPoints) and (thePlayer.computer3Points < thePlayer.computer1Points) and (thePlayer.computer1Points < thePlayer.computer2Points))
    {
        cout << "Unlucky!!! Computer_3 has won the game!" << endl;
    }
    else
    {
        cout << "It's a draw!" << endl;
    }
}

void whoGoesFirst (Card theCard, Pile thePile, Player thePlayer, string _game)
{
    while (thePlayer.cardCount > 0)
    {
        thePlayer.cardCount--;
        //cout << "uhgurthtrh " << thePlayer.cardCount << endl;
        if (thePlayer.cardCount == 13)
        {
            thePile.leadingSuit = "Clubs";
            for (int i = 0; i < 52; i++)
            {
                if ((thePile.deck[i].value == 2) and (thePile.deck[i].suit == "Clubs"))
                {
                    if ((i >= 0) and (i < 13))
                    {
                        thePile.deck[i].cardPlayed = true;
                        thePile.position = i;
                        cout << "You have the 2 of clubs. Your first turn was just completed for you." << endl;
                        thePlayer = checkWinnerOfTrick(thePlayer, thePile);
                        thePile.deck[thePile.position-1].cardPlayed = true;
                        cout << "test: " << thePile.deck[thePile.position-1].cardPlayed << endl;
                        //thePlayer.cardCount--;
                        //whoGoesFirst(theCard, thePile, thePlayer, _game);
                    }
                    else if ((i >= 13) and (i < 26))
                    {
                        cout << "Computer_1 has the 2 of clubs. Computer_1 starts." << endl;
                        thePlayer = takePlayerTurn (theCard, thePlayer, thePile);
                        thePile.deck[thePile.position-1].cardPlayed = true;
                        cout << "test: " << thePile.deck[thePile.position-1].cardPlayed << endl;
                        //thePlayer.cardCount--;
                        //whoGoesFirst(theCard, thePile, thePlayer, _game);
                    }
                    else if ((i >= 26) and (i < 39))
                    {
                        cout << "Computer_2 has the 2 of clubs. Computer_2 starts." << endl;
                        thePlayer = takePlayerTurn (theCard, thePlayer, thePile);
                        thePile.deck[thePile.position-1].cardPlayed = true;
                        cout << "test: " << thePile.deck[thePile.position-1].cardPlayed << endl;
                        //thePlayer.cardCount--;
                        //whoGoesFirst(theCard, thePile, thePlayer, _game);
                    }
                    else if ((i >= 39) and (i < 52))
                    {
                        cout << "Computer_3 has the 2 of clubs. Computer_3 starts." << endl;
                        thePlayer = takePlayerTurn (theCard, thePlayer, thePile);
                        thePile.deck[thePile.position-1].cardPlayed = true;
                        cout << "test: " << thePile.deck[thePile.position-1].cardPlayed << endl;
                        //thePlayer.cardCount--;
                        //whoGoesFirst(theCard, thePile, thePlayer, _game);
                    }
                }
            }
        }
        else if (thePlayer.cardCount > 0)
        {
            if (thePlayer.winner == "Player")
            {
                thePile.leadingSuit = "N/A";
                thePlayer = takePlayerTurn (theCard, thePlayer, thePile);
                thePile.deck[thePile.position-1].cardPlayed = true;
                cout << "test: " << thePile.deck[thePile.position-1].cardPlayed << endl;
            }
            else if (thePlayer.winner == "Computer_1")
            {
                thePile.randomPositionComputer1 = (rand() % 13) + 13;
                thePile.leadingSuit = thePile.deck[thePile.randomPositionComputer1].suit;
                thePlayer = takePlayerTurn (theCard, thePlayer, thePile);
                thePile.deck[thePile.position-1].cardPlayed = true;
                cout << "test: " << thePile.deck[thePile.position-1].cardPlayed << endl;
            }
            else if (thePlayer.winner == "Computer_2")
            {
                thePile.randomPositionComputer2 = (rand() % 13) + 26;
                thePile.leadingSuit = thePile.deck[thePile.randomPositionComputer2].suit;
                thePlayer = takePlayerTurn (theCard, thePlayer, thePile);
                thePile.deck[thePile.position-1].cardPlayed = true;
                cout << "test: " << thePile.deck[thePile.position-1].cardPlayed << endl;
            }
            else if (thePlayer.winner == "Computer_3")
            {
                thePile.randomPositionComputer3 = (rand() % 13) + 39;
                thePile.leadingSuit = thePile.deck[thePile.randomPositionComputer3].suit;
                thePlayer = takePlayerTurn (theCard, thePlayer, thePile);
                thePile.deck[thePile.position-1].cardPlayed = true;
                cout << "test: " << thePile.deck[thePile.position-1].cardPlayed << endl;
            }
            else
            {
                cout << "Program is broken." << endl;
            }
        }
        else
        {
            cout << endl;
            endOfGameStats(thePlayer, _game);
        }
    }
}

int main()
{
    srand(time(NULL));
    string game = "y";
    Card card;
    Player player;
    Pile pile;
    cout << "Please enter your name. (Please use underscores instead of spaces.)" << endl;
    cin >> player.name;
    cout << endl << endl;
    while (game == "y")
    {
        pile.position = 14;
        player.cardCount = 14;
        player.userPoints = 0;
        player.computer1Points = 0;
        player.computer2Points = 0;
        player.computer3Points = 0;
        pile = initializeDeck(pile);
        pile = shuffleDeck(pile);
        pile = sortHand(pile);
        cout << endl;
        whoGoesFirst(card, pile, player, game);
        cout << endl << endl << endl;
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
