#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

struct card
{
    int cardValue;
    int cardSuit;
    int cardRank;
    bool cardInDealersPile;
    bool cardUsed;
    string cardGraphics[9][9];
};

struct pile
{
    card cardDeck[52];
};

struct player
{
    card cardHand[52];
    int numberOfCards;
};


void initializeDeck (card singleCard, pile deckOfCards, string cardDesign[9][9])
{
    while (singleCard.cardSuit <= 6)
    {
        while (singleCard.cardValue <= 13)
        {
            for(int i = 0; i < 9; i++)
            {
                for(int j = 0; j < 9; j++)
                {
                    cardDesign[i][j] = (char)255;
                }
            }
            for(int i = 0; i < 9; i++)
            {
                cardDesign[0][i] = (char)205;
                cardDesign[8][i] = (char)205;
                cardDesign[i][0] = (char)186;
                cardDesign[i][8] = (char)186;
            }
            cardDesign[0][0] = (char)201;
            cardDesign[0][8] = (char)187;
            cardDesign[8][0] = (char)200;
            cardDesign[8][8] = (char)188;
            if (singleCard.cardValue == 1)
            {
                cardDesign[1][1] = (char)65;
                cardDesign[7][7] = (char)65;
                cardDesign[4][4] = (char)singleCard.cardSuit;
                singleCard.cardValue++;
            }
            else if (singleCard.cardValue == 2)
            {
                cardDesign[1][1] = (char)50;
                cardDesign[7][7] = (char)50;
                cardDesign[2][4] = (char)singleCard.cardSuit;
                cardDesign[6][4] = (char)singleCard.cardSuit;
                singleCard.cardValue++;
            }
            else if (singleCard.cardValue == 3)
            {
                cardDesign[1][1] = (char)51;
                cardDesign[7][7] = (char)51;
                cardDesign[2][4] = (char)singleCard.cardSuit;
                cardDesign[4][4] = (char)singleCard.cardSuit;
                cardDesign[6][4] = (char)singleCard.cardSuit;
                singleCard.cardValue++;
            }
            else if (singleCard.cardValue == 4)
            {
                cardDesign[1][1] = (char)52;
                cardDesign[7][7] = (char)52;
                cardDesign[2][2] = (char)singleCard.cardSuit;
                cardDesign[2][6] = (char)singleCard.cardSuit;
                cardDesign[6][2] = (char)singleCard.cardSuit;
                cardDesign[6][6] = (char)singleCard.cardSuit;
                singleCard.cardValue++;
            }
            else if (singleCard.cardValue == 5)
            {
                cardDesign[1][1] = (char)53;
                cardDesign[7][7] = (char)53;
                cardDesign[2][2] = (char)singleCard.cardSuit;
                cardDesign[2][6] = (char)singleCard.cardSuit;
                cardDesign[4][4] = (char)singleCard.cardSuit;
                cardDesign[6][2] = (char)singleCard.cardSuit;
                cardDesign[6][6] = (char)singleCard.cardSuit;
                singleCard.cardValue++;
            }
            else if (singleCard.cardValue == 6)
            {
                cardDesign[1][1] = (char)54;
                cardDesign[7][7] = (char)54;
                cardDesign[2][2] = (char)singleCard.cardSuit;
                cardDesign[2][6] = (char)singleCard.cardSuit;
                cardDesign[4][2] = (char)singleCard.cardSuit;
                cardDesign[4][6] = (char)singleCard.cardSuit;
                cardDesign[6][2] = (char)singleCard.cardSuit;
                cardDesign[6][6] = (char)singleCard.cardSuit;
                singleCard.cardValue++;
            }
            else if (singleCard.cardValue == 7)
            {
                cardDesign[1][1] = (char)55;
                cardDesign[2][2] = (char)singleCard.cardSuit;
                cardDesign[2][6] = (char)singleCard.cardSuit;
                cardDesign[3][4] = (char)singleCard.cardSuit;
                cardDesign[4][2] = (char)singleCard.cardSuit;
                cardDesign[4][6] = (char)singleCard.cardSuit;
                cardDesign[6][2] = (char)singleCard.cardSuit;
                cardDesign[6][6] = (char)singleCard.cardSuit;
                cardDesign[7][7] = (char)55;
                singleCard.cardValue++;
            }
            else if (singleCard.cardValue == 8)
            {
                cardDesign[1][1] = (char)56;
                cardDesign[2][2] = (char)singleCard.cardSuit;
                cardDesign[2][6] = (char)singleCard.cardSuit;
                cardDesign[3][4] = (char)singleCard.cardSuit;
                cardDesign[4][2] = (char)singleCard.cardSuit;
                cardDesign[4][6] = (char)singleCard.cardSuit;
                cardDesign[5][4] = (char)singleCard.cardSuit;
                cardDesign[6][2] = (char)singleCard.cardSuit;
                cardDesign[6][6] = (char)singleCard.cardSuit;
                cardDesign[7][7] = (char)56;
                singleCard.cardValue++;
            }
            else if (singleCard.cardValue == 9)
            {
                cardDesign[1][1] = (char)57;
                cardDesign[2][2] = (char)singleCard.cardSuit;
                cardDesign[2][6] = (char)singleCard.cardSuit;
                cardDesign[3][2] = (char)singleCard.cardSuit;
                cardDesign[3][6] = (char)singleCard.cardSuit;
                cardDesign[4][4] = (char)singleCard.cardSuit;
                cardDesign[5][2] = (char)singleCard.cardSuit;
                cardDesign[5][6] = (char)singleCard.cardSuit;
                cardDesign[6][2] = (char)singleCard.cardSuit;
                cardDesign[6][6] = (char)singleCard.cardSuit;
                cardDesign[7][7] = (char)57;
                singleCard.cardValue++;
            }
            else if (singleCard.cardValue == 10)
            {
                cardDesign[1][1] = (char)49;
                cardDesign[1][2] = (char)48;
                cardDesign[2][4] = (char)singleCard.cardSuit;
                cardDesign[3][2] = (char)singleCard.cardSuit;
                cardDesign[3][4] = (char)singleCard.cardSuit;
                cardDesign[3][6] = (char)singleCard.cardSuit;
                cardDesign[4][2] = (char)singleCard.cardSuit;
                cardDesign[4][6] = (char)singleCard.cardSuit;
                cardDesign[5][2] = (char)singleCard.cardSuit;
                cardDesign[5][4] = (char)singleCard.cardSuit;
                cardDesign[5][6] = (char)singleCard.cardSuit;
                cardDesign[6][4] = (char)singleCard.cardSuit;
                cardDesign[7][6] = (char)49;
                cardDesign[7][7] = (char)48;
                singleCard.cardValue++;
            }
            else if (singleCard.cardValue == 11)
            {
                cardDesign[1][1] = (char)74;
                cardDesign[2][4] = (char)singleCard.cardSuit;
                cardDesign[3][2] = (char)singleCard.cardSuit;
                cardDesign[3][4] = (char)singleCard.cardSuit;
                cardDesign[3][6] = (char)singleCard.cardSuit;
                cardDesign[4][2] = (char)singleCard.cardSuit;
                cardDesign[4][4] = (char)singleCard.cardSuit;
                cardDesign[4][6] = (char)singleCard.cardSuit;
                cardDesign[5][2] = (char)singleCard.cardSuit;
                cardDesign[5][4] = (char)singleCard.cardSuit;
                cardDesign[5][6] = (char)singleCard.cardSuit;
                cardDesign[6][4] = (char)singleCard.cardSuit;
                cardDesign[7][7] = (char)74;
                singleCard.cardValue++;
            }
            else if (singleCard.cardValue == 12)
            {
                cardDesign[1][1] = (char)81;
                cardDesign[2][2] = (char)singleCard.cardSuit;
                cardDesign[2][6] = (char)singleCard.cardSuit;
                cardDesign[3][2] = (char)singleCard.cardSuit;
                cardDesign[3][4] = (char)singleCard.cardSuit;
                cardDesign[3][6] = (char)singleCard.cardSuit;
                cardDesign[4][2] = (char)singleCard.cardSuit;
                cardDesign[4][6] = (char)singleCard.cardSuit;
                cardDesign[5][2] = (char)singleCard.cardSuit;
                cardDesign[5][4] = (char)singleCard.cardSuit;
                cardDesign[5][6] = (char)singleCard.cardSuit;
                cardDesign[6][2] = (char)singleCard.cardSuit;
                cardDesign[6][6] = (char)singleCard.cardSuit;
                cardDesign[7][7] = (char)81;
                singleCard.cardValue++;
            }
            else if (singleCard.cardValue == 13)
            {
                cardDesign[1][1] = (char)75;
                cardDesign[2][2] = (char)singleCard.cardSuit;
                cardDesign[2][6] = (char)singleCard.cardSuit;
                cardDesign[3][2] = (char)singleCard.cardSuit;
                cardDesign[3][4] = (char)singleCard.cardSuit;
                cardDesign[3][6] = (char)singleCard.cardSuit;
                cardDesign[4][2] = (char)singleCard.cardSuit;
                cardDesign[4][4] = (char)singleCard.cardSuit;
                cardDesign[4][6] = (char)singleCard.cardSuit;
                cardDesign[5][2] = (char)singleCard.cardSuit;
                cardDesign[5][4] = (char)singleCard.cardSuit;
                cardDesign[5][6] = (char)singleCard.cardSuit;
                cardDesign[6][2] = (char)singleCard.cardSuit;
                cardDesign[6][6] = (char)singleCard.cardSuit;
                cardDesign[7][7] = (char)75;
                singleCard.cardValue++;
            }
        }
        singleCard.cardSuit++;
    }
}

void displayPile (card singleCard, pile deckOfCards, string cardDesign[9][9])
{
    initializeDeck(singleCard, deckOfCards, cardDesign);
    for (int i = 0; i < 52; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            for (int k = 0; k < 9; k++)
            {
                deckOfCards.cardDeck[i].cardGraphics[j][k] = cardDesign[j][k];
                cout<<deckOfCards.cardDeck[i].cardGraphics[j][k];
            }
        }
    }
    /*int amountOfCards = 1;
    int linesRequired = amountOfCards/8;
    if (amountOfCards % 8 != 0)
    {
        linesRequired++;
    }
    for (int l = 0; l< linesRequired; l++)
    {
        for(int i = 0; i < 9; i++)
        {
            for (int k = l*8; k < (l+1)*8; k++)
            {
                if (k == amountOfCards)
                {
                    cout<<endl;
                    break;
                }
                for(int j = 0; j < 9; j++)
                {
                    cout << cardDesign[i][j];
                }
                cout<<" ";
            }
        }
    }*/
}

void displayCard ()
{

}

void displayPlayer ()
{

}

pile shufflePile (card singleCard, pile deckOfCards)
{
    for (int i = 0; i < 1000; i++)
    {
        int j = rand() % 52;
        card buffer = deckOfCards.cardDeck[52];
        deckOfCards.cardDeck[52] = deckOfCards.cardDeck[j];
        deckOfCards.cardDeck[j] = buffer;
    }
}

player moveCard (card singleCard, pile &pileInput, player playerInput)
{
    int cardsDealt = 52;
    while (true)
    {
        for (int i = 0; i < 52; i++)
        {
            if (pileInput.cardDeck[i].cardInDealersPile == true)
            {
                pileInput.cardDeck[i].cardInDealersPile == false;
                playerInput.cardHand[playerInput.numberOfCards] = pileInput.cardDeck[i];
                playerInput.numberOfCards++;
            }
            if(playerInput.numberOfCards == cardsDealt)
            {
                return playerInput;
            }
            cout<<"Shuffling..."<<endl;
            pileInput = shufflePile(singleCard, pileInput);
        }
    }
}

int main()
{
    card _card;
    pile _pile;
    player _player;
    string design[9][9];
    displayPile(_card, _pile, design);
    moveCard(_card, _pile, _player);
}
