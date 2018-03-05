//Wintana Yosief
//Card Game


#include <iostream>
#include <stdlib.h>


using namespace std;

// properties of a Card
struct Card
{

    string suit;    // card's suit
    int Rank;    // card's ranking
    int value;      // card's numeric value
};

// properties of a Player
struct Player
{

    Card hand[52];      // player's hand
    string name;       // player's name
    int cardCount;    // number of cards in hand

};

// properties of a pile
struct Pile
{
    Card playedCards[52];  // array of already played/discarded cards
    int position;         // position in array

};

// display one card
void displayCard(Card theCard)
{
    // displays the properties of a Card

    cout << "Value:" << " ";
    cout << theCard.value << " " << endl;
    cout << "Suit:" << " ";
    cout << theCard.suit << " " << endl;
    cout << "Rank:" << " " << endl;
    cout << theCard.Rank << " " << endl;
    cout << endl;
}

// displays the deck
void displayDeck(Pile thePile)
{
    // loops from position 0 to position 51
    for(int i=0; i<52; i++)
    {
        // calls display card function 52 times to display entire deck
       displayCard(thePile.playedCards[i]);
    }
}

// Creates each card in deck
void initializeDeck(Pile thePile)
{
        // loops from position 0 to position 9
        // initializes all card's of Diamond suit

        for(int j=0; j<10; j++)
        {
              // initializes card's value
             thePile.playedCards[j].value = j+1;

             // initializes card's suit
             thePile.playedCards[j].suit = "Diamond";

        }
             // initializes the cards with a specific ranking

             thePile.playedCards[0].value = 1;
             thePile.playedCards[0].Rank = 13;
             thePile.playedCards[0].suit = "Diamond";
             thePile.playedCards[10].value = 11;
             thePile.playedCards[10].Rank = 10;
             thePile.playedCards[10].suit = "Diamond";
             thePile.playedCards[11].value = 12;
             thePile.playedCards[11].Rank = 11;
             thePile.playedCards[11].suit = "Diamond";
             thePile.playedCards[12].value = 13;
             thePile.playedCards[12].Rank = 12;
             thePile.playedCards[12].suit = "Diamond";


         // loops from position 13 to position 22
         // initializes  cards of suit Spades

        for(int j=13; j<23; j++)
        {
            // initializes the card's value
            thePile.playedCards[j].value = j-12;

            // initializes the card's suit
            thePile.playedCards[j].suit = "Spades";
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

       for(int j=26; j<37; j++)
       {
           // initializes the card value
           thePile.playedCards[j].value = j-25;

           // initializes the card suit
           thePile.playedCards[j].suit = "Hearts";
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

        for(int j=39; j<49; j++)
        {
            // initializes card value
            thePile.playedCards[j].value = j-38;

            // initializes card suit
            thePile.playedCards[j].suit = "Cloves";
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

}

// shuffles a deck of cards
void shuffleDeck(Pile thePile)
{
    // loops from position 51 to 1
    for(int i=51; i>0; i--)
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

}

// deletes a card
Card clearCard(Card theCard)
{
    // erases all properties of that card
    theCard.value = 0;
    theCard.suit = "";
    theCard.Rank = 0;

    return theCard;
}

// initializes the pile
void initializePile(Pile thePile)
{
    // loops from position 0 to 51
    for(int i=0; i<52; i++)
    {
        // pile starts empty at start of game
        clearCard(thePile.playedCards[i]);
    }

    // first available position is furthermost, 51
    thePile.position = 51;
}

// moves a card from hand to pile
void moveCard(Card theCard, Pile thePile)
{
    // card from hand goes to pile array
    thePile.playedCards[thePile.position] = theCard;

    // update position to next empty slot
    thePile.position--;
}

// displays a Player
void displayPlayer(Player thePlayer)
{
    // displays the properties of a Player

    cout << thePlayer.name << " ";
    cout << thePlayer.cardCount << " ";

    // displays user's hand
    for(int i=0; i<thePlayer.cardCount; i++)
    {
        // checks if card is played
        if(thePlayer.hand[i].value != 0)
        {
            // displays available not played cards
            displayCard(thePlayer.hand[i]);
        }

    }
}

int main()
{
    Card card;
    Player player;
    Pile pile;
    initializePile(pile);
    initializeDeck(pile);
    shuffleDeck(pile);
    displayDeck(pile);
    moveCard(card, pile);
    displayPlayer(player);
    return 0;
}

