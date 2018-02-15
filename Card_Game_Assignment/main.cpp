#include <cstdlib>
#include <iostream>

using namespace std;

void generateCard()
{
    for(int i=0;i<9;i++)
    {
       for(int j=0;j<9;j++)
       {
           card[i][j] = 0;
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
    if (cardValue)
}

int main()
{
    /*char card[9][9] = {(char)201, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)187,
                       (char)186, (char)255, (char)  3, (char)255, (char)  3, (char)255, (char)  3, (char)255, (char)186,
                       (char)186, (char)255, (char)255, (char)255, (char)255, (char)255, (char)255, (char)255, (char)186,
                       (char)186, (char)255, (char)  3, (char)255, (char)  3, (char)255, (char)  3, (char)255, (char)186,
                       (char)186, (char)255, (char)255, (char)255, (char) 75, (char)255, (char)255, (char)255, (char)186,
                       (char)186, (char)255, (char)  3, (char)255, (char)  3, (char)255, (char)  3, (char)255, (char)186,
                       (char)186, (char)255, (char)255, (char)255, (char)255, (char)255, (char)255, (char)255, (char)186,
                       (char)186, (char)255, (char)  3, (char)255, (char)  3, (char)255, (char)  3, (char)255, (char)186,
                       (char)200, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)188};
    for(int i=0;i<9;i++)
    {
       for(int j=0;j<9;j++)
       {
           cout<<card[i][j];
       }
       cout<<endl;
    }
    */
}
