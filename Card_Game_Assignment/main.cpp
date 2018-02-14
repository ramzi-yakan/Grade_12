#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    char card[9][9] = {(char)201, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)205, (char)187,
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
}
