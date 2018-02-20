#include <cstdlib>
#include <iostream>

using namespace std;

void generateCard(char card[9][9])
{
    for(int i=0;i<9;i++)
    {
       for(int j=0;j<9;j++)
       {
           card[i][j] = (char)255;
       }
    }
    for(int i=0;i<9;i++)
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
}

int main()
{
    char card[9][9] = {};
    /*generateCard(card);*/
    cout<<card[9][9]<<endl;
}
