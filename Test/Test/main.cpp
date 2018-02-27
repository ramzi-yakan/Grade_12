#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

void generateCard(char card[9][9], int value, int suit)
{
    for(int i = 0; i < 9; i++)
    {
       for(int j = 0; j < 9; j++)
       {
           card[i][j] = (char)255;
       }
    }
    for(int i = 0; i < 9; i++)
    {
        card[0][i] = (char)205;
        card[8][i] = (char)205;
        card[i][0] = (char)186;
        card[i][8] = (char)186;
    }
    card[0][0] = (char)201;
    card[0][8] = (char)187;
    card[8][0] = (char)200;
    card[8][8] = (char)188;
    if (value == 1)
    {
        card[1][1] = (char)65;
        card[7][7] = (char)65;
        card[4][4] = (char)suit;
    }
    if (value == 2)
    {
        card[1][1] = (char)50;
        card[7][7] = (char)50;
        card[2][4] = (char)suit;
        card[6][4] = (char)suit;
    }
    if (value == 3)
    {
        card[1][1] = (char)51;
        card[7][7] = (char)51;
        card[2][4] = (char)suit;
        card[4][4] = (char)suit;
        card[6][4] = (char)suit;
    }
    if (value == 4)
    {
        card[1][1] = (char)52;
        card[7][7] = (char)52;
        card[2][2] = (char)suit;
        card[2][6] = (char)suit;
        card[6][2] = (char)suit;
        card[6][6] = (char)suit;
    }
    if (value == 5)
    {
        card[1][1] = (char)53;
        card[7][7] = (char)53;
        card[2][2] = (char)suit;
        card[2][6] = (char)suit;
        card[4][4] = (char)suit;
        card[6][2] = (char)suit;
        card[6][6] = (char)suit;
    }
    if (value == 6)
    {
        card[1][1] = (char)54;
        card[7][7] = (char)54;
        card[2][2] = (char)suit;
        card[2][6] = (char)suit;
        card[4][2] = (char)suit;
        card[4][6] = (char)suit;
        card[6][2] = (char)suit;
        card[6][6] = (char)suit;
    }
    if (value == 7)
    {
        card[1][1] = (char)55;
        card[2][2] = (char)suit;
        card[2][6] = (char)suit;
        card[3][4] = (char)suit;
        card[4][2] = (char)suit;
        card[4][6] = (char)suit;
        card[6][2] = (char)suit;
        card[6][6] = (char)suit;
        card[7][7] = (char)55;
    }
    if (value == 8)
    {
        card[1][1] = (char)56;
        card[2][2] = (char)suit;
        card[2][6] = (char)suit;
        card[3][4] = (char)suit;
        card[4][2] = (char)suit;
        card[4][6] = (char)suit;
        card[5][4] = (char)suit;
        card[6][2] = (char)suit;
        card[6][6] = (char)suit;
        card[7][7] = (char)56;
    }
    if (value == 9)
    {
        card[1][1] = (char)57;
        card[2][2] = (char)suit;
        card[2][6] = (char)suit;
        card[3][2] = (char)suit;
        card[3][6] = (char)suit;
        card[4][4] = (char)suit;
        card[5][2] = (char)suit;
        card[5][6] = (char)suit;
        card[6][2] = (char)suit;
        card[6][6] = (char)suit;
        card[7][7] = (char)57;
    }
    if (value == 10)
    {
        card[1][1] = (char)49;
        card[1][2] = (char)48;
        card[2][4] = (char)suit;
        card[3][2] = (char)suit;
        card[3][4] = (char)suit;
        card[3][6] = (char)suit;
        card[4][2] = (char)suit;
        card[4][6] = (char)suit;
        card[5][2] = (char)suit;
        card[5][4] = (char)suit;
        card[5][6] = (char)suit;
        card[6][4] = (char)suit;
        card[7][6] = (char)49;
        card[7][7] = (char)48;
    }
    if (value == 11)
    {
        card[1][1] = (char)74;
        card[2][4] = (char)suit;
        card[3][2] = (char)suit;
        card[3][4] = (char)suit;
        card[3][6] = (char)suit;
        card[4][2] = (char)suit;
        card[4][4] = (char)suit;
        card[4][6] = (char)suit;
        card[5][2] = (char)suit;
        card[5][4] = (char)suit;
        card[5][6] = (char)suit;
        card[6][4] = (char)suit;
        card[7][7] = (char)74;
    }
    if (value == 12)
    {
        card[1][1] = (char)81;
        card[2][2] = (char)suit;
        card[2][6] = (char)suit;
        card[3][2] = (char)suit;
        card[3][4] = (char)suit;
        card[3][6] = (char)suit;
        card[4][2] = (char)suit;
        card[4][6] = (char)suit;
        card[5][2] = (char)suit;
        card[5][4] = (char)suit;
        card[5][6] = (char)suit;
        card[6][2] = (char)suit;
        card[6][6] = (char)suit;
        card[7][7] = (char)81;
    }
    if (value == 13)
    {
        card[1][1] = (char)75;
        card[2][2] = (char)suit;
        card[2][6] = (char)suit;
        card[3][2] = (char)suit;
        card[3][4] = (char)suit;
        card[3][6] = (char)suit;
        card[4][2] = (char)suit;
        card[4][4] = (char)suit;
        card[4][6] = (char)suit;
        card[5][2] = (char)suit;
        card[5][4] = (char)suit;
        card[5][6] = (char)suit;
        card[6][2] = (char)suit;
        card[6][6] = (char)suit;
        card[7][7] = (char)75;
    }
}

void displayCard(char card[9][9], int value, int suit)
{
    int amountOfCards = 1;
    int linesRequired = amountOfCards/8;
    if (amountOfCards % 8 != 0)
    {
        linesRequired++;
    }
    for (int l = 0; l< linesRequired; l++)
    {
        for(int i = 0; i < 9; i++)
        {
            for (int k = 0; k<9; k++)
            {
                if (k == 8)
                {
                    cout<<endl;
                    break;
                }

                for(int j = 0; j < 9; j++)
                {
                    cout<<card[i][j];
                }
            }
        }
    }
}

void initializeDeck()
{
    char card[9][9];
    for (int suitOfCard = 3; suitOfCard <= 6; suitOfCard++)
    {
        for (int valueOfCard = 1; valueOfCard <= 13; valueOfCard++)
        {
            generateCard(card, valueOfCard, suitOfCard);
            displayCard(card, valueOfCard, suitOfCard);
        }
    }
}

int main()
{
    srand(time(NULL));
    initializeDeck();
}
