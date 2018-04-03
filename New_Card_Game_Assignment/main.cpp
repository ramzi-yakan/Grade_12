//Card Game

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
    string suit;    // card's suit
    int Rank;    // card's ranking
    int value;   // card's numeric value
    int suitValue;
    string stringValue;
    bool cardPlayed;
};

// properties of a Player
struct Player
{
    string name;        // player's name
    int cardCount;    // number of cards in hand
    int userHearts;
    int computer1Hearts;
    int computer2Hearts;
    int computer3Hearts;
    int userPoints;
    int computer1Points;
    int computer2Points;
    int computer3Points;
};

// properties of a pile
struct Pile
{
    Card playedCards[52];  // array of already played/discarded cards
    int position;         // position in array
};

Pile sortHand(Pile thePile)
{
    Card buffer;
    int i = 0;
    while (i < 13)
    {
            if (thePile.playedCards[i].suit == "Hearts")
            {
                thePile.playedCards[i].suitValue = 3;
            }
            else if (thePile.playedCards[i].suit == "Diamonds")
            {
                thePile.playedCards[i].suitValue = 4;
            }
            else if (thePile.playedCards[i].suit == "Cloves")
            {
                thePile.playedCards[i].suitValue = 5;
            }
            else
            {
                thePile.playedCards[i].suitValue = 6;
            }
            for (int j = i-1; j >= 0; j--)
            {
                if (thePile.playedCards[j+1].suitValue > thePile.playedCards[j].suitValue)
                {
                    buffer = thePile.playedCards[j+1];
                    thePile.playedCards[j+1] = thePile.playedCards[j];
                    thePile.playedCards[j] = buffer;
                }
                if (thePile.playedCards[j+1].suit == thePile.playedCards[j].suit)
                {
                    if (thePile.playedCards[j+1].Rank < thePile.playedCards[j].Rank)
                    {
                        buffer = thePile.playedCards[j+1];
                        thePile.playedCards[j+1] = thePile.playedCards[j];
                        thePile.playedCards[j] = buffer;
                    }
                }
            }
            i++;
    }
    while (i < 26)
    {
            for (int j = i-1; j >= 13; j--)
            {
                if (thePile.playedCards[j+1].Rank < thePile.playedCards[j].Rank)
                {
                    buffer = thePile.playedCards[j+1];
                    thePile.playedCards[j+1] = thePile.playedCards[j];
                    thePile.playedCards[j] = buffer;
                }
            }
            i++;
    }
    while (i < 39)
    {
            for (int j = i-1; j >= 26; j--)
            {
                if (thePile.playedCards[j+1].Rank < thePile.playedCards[j].Rank)
                {
                    buffer = thePile.playedCards[j+1];
                    thePile.playedCards[j+1] = thePile.playedCards[j];
                    thePile.playedCards[j] = buffer;
                }
            }
            i++;
    }
    while (i < 52)
    {
            for (int j = i-1; j >= 39; j--)
            {
                if (thePile.playedCards[j+1].Rank < thePile.playedCards[j].Rank)
                {
                    buffer = thePile.playedCards[j+1];
                    thePile.playedCards[j+1] = thePile.playedCards[j];
                    thePile.playedCards[j] = buffer;
                }
            }
            i++;
    }
    return thePile;
}

// display one card
void displayCard(Card theCard)
{
    // displays the properties of a Card
    cout << "Value: ";
    if (theCard.value == 1)
    {
        theCard.stringValue = "A";
        cout << theCard.stringValue << endl;
    }
    else if (theCard.value == 11)
    {
        theCard.stringValue = "J";
        cout << theCard.stringValue << endl;
    }
    else if (theCard.value == 12)
    {
        theCard.stringValue = "Q";
        cout << theCard.stringValue << endl;
    }
    else if (theCard.value == 13)
    {
        theCard.stringValue = "K";
        cout << theCard.stringValue << endl;
    }
    else
    {
        cout << theCard.value << endl;
    }
    cout << "Suit: ";
    cout << theCard.suit << endl;
    cout << endl;
}

void moveCard(Pile thePile, Player thePlayer)
{
    Card buffer;
    for(int i = 0; i < thePlayer.cardCount+1; i++)
    {
        if (i < thePile.position-1)
        {
            cout << "Card " << i+1 << endl;
            displayCard(thePile.playedCards[i]);
        }
        else if (i > thePile.position-1)
        {
            cout << "Card " << i << endl;
            displayCard(thePile.playedCards[i]);
        }
        else
        {
            buffer = thePile.playedCards[i];
            thePile.playedCards[i] = thePile.playedCards[thePlayer.cardCount+1];
            thePile.playedCards[thePlayer.cardCount+2] = buffer;
        }
    }
}

// displays the deck
Player displayDeck(Pile thePile, Player thePlayer)
{
    moveCard(thePile, thePlayer);
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
        cout << "End of game.";
    }
    return thePlayer;
}

// Creates each card in deck
Pile initializeDeck(Pile thePile)
{
        // loops from position 0 to position 9
        // initializes all card's of Diamond suit

        for(int i=1; i<10; i++)
        {
              // initializes card's value
             thePile.playedCards[i].value = i+1;

             // initializes card's suit
             thePile.playedCards[i].suit = "Diamonds";
             thePile.playedCards[i].Rank = i;

        }
             // initializes the cards with a specific ranking

             thePile.playedCards[0].value = 1;
             thePile.playedCards[0].Rank = 13;
             thePile.playedCards[0].suit = "Diamonds";
             thePile.playedCards[10].value = 11;
             thePile.playedCards[10].Rank = 10;
             thePile.playedCards[10].suit = "Diamonds";
             thePile.playedCards[11].value = 12;
             thePile.playedCards[11].Rank = 11;
             thePile.playedCards[11].suit = "Diamonds";
             thePile.playedCards[12].value = 13;
             thePile.playedCards[12].Rank = 12;
             thePile.playedCards[12].suit = "Diamonds";


         // loops from position 13 to position 22
         // initializes  cards of suit Spades

        for(int i=14; i<23; i++)
        {
            // initializes the card's value
            thePile.playedCards[i].value = i-12;

            // initializes the card's suit
            thePile.playedCards[i].suit = "Spades";
            thePile.playedCards[i].Rank = i-13;

        }
           //initializes the cards with specific ranking

            thePile.playedCards[13].value = 1;
            thePile.playedCards[13].Rank = 13;
            thePile.playedCards[13].suit = "Spades";
            thePile.playedCards[23].value = 11;
            thePile.playedCards[23].Rank = 10;
            thePile.playedCards[23].suit = "Spades";
            thePile.playedCards[24].value = 12;
            thePile.playedCards[24].Rank = 11;
            thePile.playedCards[24].suit = "Spades";
            thePile.playedCards[25].value = 13;
            thePile.playedCards[25].Rank = 12;
            thePile.playedCards[25].suit = "Spades";


       // loops from position 26 to position 36

       for(int i=27; i<36; i++)
       {
           // initializes the card value
           thePile.playedCards[i].value = i-25;

           // initializes the card suit
           thePile.playedCards[i].suit = "Hearts";
           thePile.playedCards[i].Rank = i-26;

       }

       // initializes cards with specific rankings

           thePile.playedCards[26].value = 1;
           thePile.playedCards[26].Rank = 13;
           thePile.playedCards[26].suit = "Hearts";
           thePile.playedCards[36].value = 11;
           thePile.playedCards[36].Rank = 10;
           thePile.playedCards[36].suit = "Hearts";
           thePile.playedCards[37].value = 12;
           thePile.playedCards[37].Rank = 11;
           thePile.playedCards[37].suit = "Hearts";
           thePile.playedCards[38].value = 13;
           thePile.playedCards[38].Rank = 12;
           thePile.playedCards[38].suit = "Hearts";
        // loops from position 39 to position 48

        for(int i=40; i<49; i++)
        {
            // initializes card value
            thePile.playedCards[i].value = i-38;

            // initializes card suit
            thePile.playedCards[i].suit = "Cloves";
            thePile.playedCards[i].Rank = i-39;
        }

         // initializes cards with specific rankings

            thePile.playedCards[39].value = 1;
            thePile.playedCards[39].Rank = 13;
            thePile.playedCards[39].suit = "Cloves";
            thePile.playedCards[49].value = 11;
            thePile.playedCards[49].Rank = 10;
            thePile.playedCards[49].suit = "Cloves";
            thePile.playedCards[50].value = 12;
            thePile.playedCards[50].Rank = 11;
            thePile.playedCards[50].suit = "Cloves";
            thePile.playedCards[51].value = 13;
            thePile.playedCards[51].Rank = 12;
            thePile.playedCards[51].suit = "Cloves";
            return thePile;

}

// shuffles a deck of cards
Pile shuffleDeck(Pile thePile)
{
    srand(time(NULL));
    // loops from position 51 to 1
    for(int i = 51; i > 0; i--)
    {
        // finds a random position number between 0 and ith
        int r = rand() % i;

        // assigns position i as max position
        Card atMax = thePile.playedCards[i];

        // assigns position r as random position
        Card atRandom = thePile.playedCards[r];

        // swaps max position and random position
        thePile.playedCards[r] = atMax;
        thePile.playedCards[i] = atRandom;
    }
    return thePile;
}

// deletes a card
Card clearCard(Card theCard)
{
    // erases all properties of that card
    theCard.value = 0;
    theCard.suit = " ";
    theCard.Rank = 0;

    return theCard;
}

// initializes the pile
Pile initializePile(Pile thePile)
{
    // loops from position 0 to 51
    for(int i=0; i<52; i++)
    {
        // pile starts empty at start of game
        clearCard(thePile.playedCards[i]);
    }
    return thePile;
}

Player takeComputersTurn(Player thePlayer, Pile thePile)
{
    cout << endl;
    if ((thePile.playedCards[13-thePlayer.cardCount].Rank > thePile.playedCards[13+(13-thePlayer.cardCount)].Rank) and (thePile.playedCards[13-thePlayer.cardCount].Rank > thePile.playedCards[26+(13-thePlayer.cardCount)].Rank) and (thePile.playedCards[13-thePlayer.cardCount].Rank > thePile.playedCards[39+(13-thePlayer.cardCount)].Rank))
    {
        cout << "You take the pile." << endl;
        if ((thePile.playedCards[13-thePlayer.cardCount].suit == "Hearts") or (thePile.playedCards[13+(13-thePlayer.cardCount)].suit == "Hearts") or (thePile.playedCards[26+(13-thePlayer.cardCount)].suit == "Hearts") or (thePile.playedCards[39+(13-thePlayer.cardCount)].suit == "Hearts"))
        {
            if (thePile.playedCards[13-thePlayer.cardCount].suit == "Hearts")
            {
                thePlayer.userHearts++;
                thePlayer.userPoints++;
            }
            if (thePile.playedCards[13+(13-thePlayer.cardCount)].suit == "Hearts")
            {
                thePlayer.userHearts++;
                thePlayer.userPoints++;
            }
            if (thePile.playedCards[26+(13-thePlayer.cardCount)].suit == "Hearts")
            {
                thePlayer.userHearts++;
                thePlayer.userPoints++;
            }
            if (thePile.playedCards[39+(13-thePlayer.cardCount)].suit == "Hearts")
            {
                thePlayer.userHearts++;
                thePlayer.userPoints++;
            }
            cout << "Uh oh! You have picked up some hearts. You now have " << thePlayer.userPoints << " points." << endl;
            cout << "You now have " << thePlayer.userHearts << " hearts." << endl;
        }
        if (thePlayer.userHearts == 13)
        {
            cout << "Congrats!!! You've just shot the moon and won the game!" <<endl;
        }
        if (((thePile.playedCards[13-thePlayer.cardCount].value == 12) and (thePile.playedCards[13-thePlayer.cardCount].suit == "Spades")) or ((thePile.playedCards[13+(13-thePlayer.cardCount)].value == 12) and (thePile.playedCards[13+(13-thePlayer.cardCount)].suit == "Spades")) or ((thePile.playedCards[26+(13-thePlayer.cardCount)].value == 12) and (thePile.playedCards[26+(13-thePlayer.cardCount)].suit == "Spades")) or ((thePile.playedCards[39+(13-thePlayer.cardCount)].value == 12) and (thePile.playedCards[39+(13-thePlayer.cardCount)].suit == "Spades")))
        {
            thePlayer.userPoints = thePlayer.userPoints + 13;
            cout << "Oh dear!!! You have picked up the queen of spades. You now have " << thePlayer.userPoints << " points." << endl;
        }
    }
    else if ((thePile.playedCards[13+(13-thePlayer.cardCount)].Rank > thePile.playedCards[26+(13-thePlayer.cardCount)].Rank) and (thePile.playedCards[13+(13-thePlayer.cardCount)].Rank > thePile.playedCards[39+(13-thePlayer.cardCount)].Rank) and (thePile.playedCards[13+(13-thePlayer.cardCount)].Rank > thePile.playedCards[13-thePlayer.cardCount].Rank))
    {
        cout << "Computer_1 takes the pile." << endl;
        if ((thePile.playedCards[13-thePlayer.cardCount].suit == "Hearts") or (thePile.playedCards[13+(13-thePlayer.cardCount)].suit == "Hearts") or (thePile.playedCards[26+(13-thePlayer.cardCount)].suit == "Hearts") or (thePile.playedCards[39+(13-thePlayer.cardCount)].suit == "Hearts"))
        {
            if (thePile.playedCards[13-thePlayer.cardCount].suit == "Hearts")
            {
                thePlayer.computer1Hearts++;
                thePlayer.computer1Points++;
            }
            if (thePile.playedCards[13+(13-thePlayer.cardCount)].suit == "Hearts")
            {
                thePlayer.computer1Hearts++;
                thePlayer.computer1Points++;
            }
            if (thePile.playedCards[26+(13-thePlayer.cardCount)].suit == "Hearts")
            {
                thePlayer.computer1Hearts++;
                thePlayer.computer1Points++;
            }
            if (thePile.playedCards[39+(13-thePlayer.cardCount)].suit == "Hearts")
            {
                thePlayer.computer1Hearts++;
                thePlayer.computer1Points++;
            }
            cout << "Yes! Computer_1 has picked up some hearts. They now have " << thePlayer.computer1Points << " points." << endl;
        }
        if (thePlayer.computer1Hearts == 13)
        {
            cout << "*sigh* Computer_1 has just shot the moon and won the game!" <<endl;
        }
        if (((thePile.playedCards[13-thePlayer.cardCount].value == 12) and (thePile.playedCards[13-thePlayer.cardCount].suit == "Spades")) or ((thePile.playedCards[13+(13-thePlayer.cardCount)].value == 12) and (thePile.playedCards[13+(13-thePlayer.cardCount)].suit == "Spades")) or ((thePile.playedCards[26+(13-thePlayer.cardCount)].value == 12) and (thePile.playedCards[26+(13-thePlayer.cardCount)].suit == "Spades")) or ((thePile.playedCards[39+(13-thePlayer.cardCount)].value == 12) and (thePile.playedCards[39+(13-thePlayer.cardCount)].suit == "Spades")))
        {
            thePlayer.computer1Points = thePlayer.computer1Points + 13;
            cout << "Amazing!!! Computer_1 has picked up the queen of spades. They now have " << thePlayer.computer1Points << " points." << endl;
        }
    }
    else if ((thePile.playedCards[26+(13-thePlayer.cardCount)].Rank > thePile.playedCards[39+(13-thePlayer.cardCount)].Rank) and (thePile.playedCards[26+(13-thePlayer.cardCount)].Rank > thePile.playedCards[13-thePlayer.cardCount].Rank) and (thePile.playedCards[26+(13-thePlayer.cardCount)].Rank > thePile.playedCards[13+(13-thePlayer.cardCount)].Rank))
    {
        cout << "Computer_2 takes the pile." << endl;
        if ((thePile.playedCards[13-thePlayer.cardCount].suit == "Hearts") or (thePile.playedCards[13+(13-thePlayer.cardCount)].suit == "Hearts") or (thePile.playedCards[26+(13-thePlayer.cardCount)].suit == "Hearts") or (thePile.playedCards[39+(13-thePlayer.cardCount)].suit == "Hearts"))
        {
            if (thePile.playedCards[13-thePlayer.cardCount].suit == "Hearts")
            {
                thePlayer.computer2Hearts++;
                thePlayer.computer2Points++;
            }
            if (thePile.playedCards[13+(13-thePlayer.cardCount)].suit == "Hearts")
            {
                thePlayer.computer2Hearts++;
                thePlayer.computer2Points++;
            }
            if (thePile.playedCards[26+(13-thePlayer.cardCount)].suit == "Hearts")
            {
                thePlayer.computer2Hearts++;
                thePlayer.computer2Points++;
            }
            if (thePile.playedCards[39+(13-thePlayer.cardCount)].suit == "Hearts")
            {
                thePlayer.computer2Hearts++;
                thePlayer.computer2Points++;
            }
            cout << "Yes! Computer_2 has picked up some hearts. They now have " << thePlayer.computer2Points << " points." << endl;
        }
        if (thePlayer.computer2Hearts == 13)
        {
            cout << "*sigh* Computer_2 has just shot the moon and won the game!" <<endl;
        }
        if (((thePile.playedCards[13-thePlayer.cardCount].value == 12) and (thePile.playedCards[13-thePlayer.cardCount].suit == "Spades")) or ((thePile.playedCards[13+(13-thePlayer.cardCount)].value == 12) and (thePile.playedCards[13+(13-thePlayer.cardCount)].suit == "Spades")) or ((thePile.playedCards[26+(13-thePlayer.cardCount)].value == 12) and (thePile.playedCards[26+(13-thePlayer.cardCount)].suit == "Spades")) or ((thePile.playedCards[39+(13-thePlayer.cardCount)].value == 12) and (thePile.playedCards[39+(13-thePlayer.cardCount)].suit == "Spades")))
        {
            thePlayer.computer2Points = thePlayer.computer2Points + 13;
            cout << "Amazing!!! Computer_2 has picked up the queen of spades. They now have " << thePlayer.computer2Points << " points." << endl;
        }
    }
    else
    {
        cout << "Computer_3 takes the pile." << endl;
        if ((thePile.playedCards[13-thePlayer.cardCount].suit == "Hearts") or (thePile.playedCards[13+(13-thePlayer.cardCount)].suit == "Hearts") or (thePile.playedCards[26+(13-thePlayer.cardCount)].suit == "Hearts") or (thePile.playedCards[39+(13-thePlayer.cardCount)].suit == "Hearts"))
        {
            if (thePile.playedCards[13-thePlayer.cardCount].suit == "Hearts")
            {
                thePlayer.computer3Hearts++;
                thePlayer.computer3Points++;
            }
            if (thePile.playedCards[13+(13-thePlayer.cardCount)].suit == "Hearts")
            {
                thePlayer.computer3Hearts++;
                thePlayer.computer3Points++;
            }
            if (thePile.playedCards[26+(13-thePlayer.cardCount)].suit == "Hearts")
            {
                thePlayer.computer3Hearts++;
                thePlayer.computer3Points++;
            }
            if (thePile.playedCards[39+(13-thePlayer.cardCount)].suit == "Hearts")
            {
                thePlayer.computer3Hearts++;
                thePlayer.computer3Points++;
            }
            cout << "Yes! Computer_3 has picked up some hearts. They now have " << thePlayer.computer3Points << " points." << endl;
        }
        if (thePlayer.computer3Hearts == 13)
        {
            cout << "*sigh* Computer_3 has just shot the moon and won the game!" <<endl;
        }
        if (((thePile.playedCards[13-thePlayer.cardCount].value == 12) and (thePile.playedCards[13-thePlayer.cardCount].suit == "Spades")) or ((thePile.playedCards[13+(13-thePlayer.cardCount)].value == 12) and (thePile.playedCards[13+(13-thePlayer.cardCount)].suit == "Spades")) or ((thePile.playedCards[26+(13-thePlayer.cardCount)].value == 12) and (thePile.playedCards[26+(13-thePlayer.cardCount)].suit == "Spades")) or ((thePile.playedCards[39+(13-thePlayer.cardCount)].value == 12) and (thePile.playedCards[39+(13-thePlayer.cardCount)].suit == "Spades")))
        {
            thePlayer.computer3Points = thePlayer.computer3Points + 13;
            cout << "Amazing!!! Computer_3 has picked up the queen of spades. They now have " << thePlayer.computer3Points << " points." << endl;
        }
    }
    cout << endl << endl << endl;
    return thePlayer;
}

Player takePlayerTurn (Player thePlayer, Pile thePile)
{
    while (thePlayer.cardCount > 0)
    {
        cout << endl << endl << endl;
        cout << "It's your turn. Indicate the card you wish to play." << endl;
        thePile.position = 0;
        while ((thePile.position < 1) or (thePile.position > thePlayer.cardCount))
        {
            cin >> thePile.position;
            if ((thePile.position < 1) or (thePile.position > thePlayer.cardCount))
            {
                cout << "Not a valid position. Please enter a different position." << endl;
            }
        }
        thePlayer = takeComputersTurn(thePlayer, thePile);
        thePlayer.cardCount--;
        thePile.playedCards[thePile.position].cardPlayed = true;
        thePlayer = displayDeck(thePile, thePlayer);
    }
    return thePlayer;
}

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
        cout << "Unlucky!!! Computer_1 has won the game!" << endl;
    }
    else
    {
        cout << "Huh... it's a draw!" << endl;
    }
}

int main()
{
    string game = "y";
    Card card;
    Player player;
    Pile pile;
    cout << "Please enter your name." << endl;
    cin >> player.name;
    cout << endl << endl;
    while (game == "y")
    {
        card.cardPlayed = false;
        pile.position = 14;
        player.cardCount = 13;
        player.userHearts = 0;
        player.computer1Hearts = 0;
        player.computer2Hearts = 0;
        player.computer3Hearts = 0;
        player.userPoints = 0;
        player.computer1Points = 0;
        player.computer2Points = 0;
        player.computer3Points = 0;
        pile = initializePile(pile);
        pile = initializeDeck(pile);
        pile = shuffleDeck(pile);
        pile = sortHand(pile);
        player = displayDeck(pile, player);
        cout << endl;
        player = takePlayerTurn(player, pile);
        cout << endl;
        endOfGameStats(player, game);
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

