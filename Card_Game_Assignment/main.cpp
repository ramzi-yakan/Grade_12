#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

void generateCard(char card[9][9])
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
    int value = rand() % 13 +1;
    if (value == 1)
    {
        card[4][4] = (char)65;
    }
    if (value == 2)
    {
        card[4][4] = (char)50;
    }
    if (value == 3)
    {
        card[4][4] = (char)51;
    }
    if (value == 4)
    {
        card[4][4] = (char)52;
    }
    if (value == 5)
    {
        card[4][4] = (char)53;
    }
    if (value == 6)
    {
        card[4][4] = (char)54;
    }
    if (value == 7)
    {
        card[4][4] = (char)55;
    }
    if (value == 8)
    {
        card[4][4] = (char)56;
    }
    if (value == 9)
    {
        card[4][4] = (char)57;
    }
    if (value == 10)
    {
        card[4][3] = (char)49;
        card[4][5] = (char)48;
    }
    if (value == 11)
    {
        card[4][4] = (char)74;
    }
    if (value == 12)
    {
        card[4][4] = (char)81;
    }
    if (value == 13)
    {
        card[4][4] = (char)76;
    }
}

void displayCard(char card[9][9])
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout<<card[i][j];
        }
    cout<<endl;
    }
}

int main()
{
    srand(time(NULL));
    char card[9][9];
    generateCard(card);
    displayCard(card);
}
