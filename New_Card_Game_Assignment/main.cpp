//Wintana Yosief
//Card Game


#include <iostream>
#include <stdlib.h>


using namespace std;

// properties of a Card
struct Card
{

    string suit;    // card's suit
    string Rank;    // card's ranking (Queen, Jack, King, Ace)
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

void displayDeck(Card[]);
void displayCard(Card);
Card clearCard(Card);
void shuffleDeck(Card[]);
void initializeDeck(Card[]);
void initializePile(Pile);
void moveCard(Card,Pile);
void displayPlayer(Player);

// displays the deck
void displayDeck(Card deck[])
{
    // loops from position 0 to position 51
    for(int i=0; i<52; i++)
    {
        // calls display card function 52 times to display entire deck
       displayCard(deck[i]);
    }
}

// Creates each card in deck
void initializeDeck(Card deck[])
{
        // loops from position 0 to position 9
        // initializes all card's of Diamond suit

        for(int j=0; j<10; j++)
        {
              // initializes card's value
             deck[j].value = j+1;

             // initializes card's suit
             deck[j].suit = "Diamond";

        }
             // initializes the cards with a specific ranking

             deck[0].value = 1;
             deck[0].Rank = "Ace";
             deck[0].suit = "Diamond";
             deck[10].value = 10;
             deck[10].Rank = "Jack";
             deck[10].suit = "Diamond";
             deck[11].value = 10;
             deck[11].Rank = "Queen";
             deck[11].suit = "Diamond";
             deck[12].value = 10;
             deck[12].Rank = "King";
             deck[12].suit = "Diamond";


         // loops from position 13 to position 22
         // initializes  cards of suit Spades

        for(int j=13; j<23; j++)
        {
            // initializes the card's value
            deck[j].value = j-12;

            // initializes the card's suit
            deck[j].suit = "Spades";
        }
           //initializes the cards with specific ranking

           deck[13].value = 1;
           deck[13].suit = "Spades";
           deck[13].Rank = "Ace";
           deck[23].value = 10;
           deck[23].suit = "Spades";
           deck[23].Rank = "Jack";
           deck[24].value = 10;
           deck[24].suit = "Spades";
           deck[24].Rank = "Queen";
           deck[25].value = 10;
           deck[25].suit = "Spades";
           deck[25].Rank = "King";


       // loops from position 26 to position 36

       for(int j=26; j<37; j++)
       {
           // initializes the card value
           deck[j].value = j-25;

           // initializes the card suit
           deck[j].suit = "Hearts";
       }

       // initializes cards with specific rankings

       deck[26].value = 1;
       deck[26].suit = "Hearts";
       deck[26].Rank = "Ace";
       deck[36].value = 10;
       deck[36].suit = "Hearts";
       deck[36].Rank = "Jack";
       deck[37].value = 10;
       deck[37].suit = "Hearts";
       deck[37].Rank = "Queen";
       deck[38].value = 10;
       deck[38].suit = "Hearts";
       deck[38].Rank = "King";

        // loops from position 39 to position 48

        for(int j=39; j<49; j++)
        {
            // initializes card value
            deck[j].value = j-38;

            // initializes card suit
            deck[j].suit = "Cloves";
        }

         // initializes cards with specific rankings

        deck[39].value = 1;
        deck[39].suit = "Cloves";
        deck[39].Rank = "Ace";
        deck[49].value = 10;
        deck[49].suit = "Cloves";
        deck[49].Rank = "Jack";
        deck[50].value = 10;
        deck[50].suit = "Cloves";
        deck[50].Rank = "Queen";
        deck[51].value = 10;
        deck[51].suit = "Cloves";
        deck[51].Rank = "King";

}

// shuffles a deck of cards
void shuffleDeck(Card deck[])
{
    // loops from position 51 to 1
    for(int i=51; i>0; i--)
    {
        // finds a random position number between 0 and ith
        int r = rand() % i;

        // assigns position i as max position
        Card atMax = deck[i];

        // assigns position r as random position
        Card atRandom = deck[r];

        // swaps max position and random position
        deck[r] = atMax;
        deck[i] = atRandom;
    }

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

// deletes a card
Card clearCard(Card theCard)
{
    // erases all properties of that card
    theCard.value = 0;
    theCard.suit = "";
    theCard.Rank = "";

    return theCard;
}

// moves a card from hand to pile
void moveCard(Card theCard, Pile thePile)
{
    // card from hand goes to pile array
    thePile.playedCards[thePile.position] = theCard;

    // update position to next empty slot
    thePile.position--;
}

// display one card
void displayCard(Card theCard)
{
    // displays the properties of a Card

    cout << "Value:" << " ";
    cout << theCard.value << " " << endl;
    cout << "Suit:" << " ";
    cout << theCard.suit << " " << endl;
    cout << theCard.Rank << " " << endl;
    cout << endl;
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
    initializeDeck(card);
    initializePile(pile);
    shuffleDeck(card);
    displayDeck(card);
    moveCard(card, pile);
    displayPlayer(player);
    return 0;
}

