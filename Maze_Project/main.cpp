#include <cstdlib>
#include <iostream>

using namespace std;

void drawMaze();

int main()
{
    drawMaze();
}

void drawMaze()
{
   char maze[15][15] = {(char)201, (char)205, (char)205, (char)255, (char)201, (char)205, (char)205, (char)205, (char)203, (char)205, (char)205, (char)205, (char)203, (char)205, (char)187,
                        (char)186, (char)255, (char)187, (char)255, (char)186, (char)255, (char)255, (char)255, (char)186, (char)255, (char)255, (char)255, (char)186, (char)255, (char)186,
                        (char)186, (char)255, (char)200, (char)205, (char)206, (char)205, (char)188, (char)255, (char)200, (char)205, (char)188, (char)255, (char)186, (char)255, (char)186,
                        (char)186, (char)255, (char)255, (char)255, (char)186, (char)255, (char)255, (char)255, (char)255, (char)255, (char)255, (char)255, (char)186, (char)255, (char)186,
                        (char)186, (char)255, (char)186, (char)255, (char)186, (char)255, (char)186, (char)255, (char)201, (char)205, (char)187, (char)255, (char)186, (char)255, (char)186,
                        (char)186, (char)255, (char)186, (char)255, (char)186, (char)255, (char)186, (char)255, (char)186, (char)255, (char)186, (char)255, (char)255, (char)255, (char)186,
                        (char)186, (char)255, (char)200, (char)205, (char)202, (char)205, (char)188, (char)255, (char)186, (char)255, (char)186, (char)255, (char)200, (char)205, (char)185,
                        (char)186, (char)255, (char)255, (char)255, (char)255, (char)255, (char)255, (char)255, (char)186, (char)255, (char)255, (char)255, (char)255, (char)255, (char)186,
                        (char)204, (char)205, (char)205, (char)205, (char)203, (char)205, (char)187, (char)255, (char)186, (char)255, (char)201, (char)205, (char)187, (char)255, (char)186,
                        (char)186, (char)255, (char)255, (char)255, (char)186, (char)255, (char)186, (char)255, (char)186, (char)255, (char)186, (char)255, (char)186, (char)255, (char)186,
                        (char)186, (char)255, (char)186, (char)255, (char)200, (char)205, (char)188, (char)255, (char)186, (char)255, (char)200, (char)205, (char)188, (char)255, (char)186,
                        (char)186, (char)255, (char)186, (char)255, (char)255, (char)255, (char)255, (char)255, (char)186, (char)255, (char)255, (char)255, (char)255, (char)255, (char)186,
                        (char)186, (char)255, (char)204, (char)205, (char)187, (char)255, (char)201, (char)205, (char)202, (char)205, (char)205, (char)205, (char)187, (char)255, (char)186,
                        (char)186, (char)255, (char)200, (char)205, (char)185, (char)255, (char)186, (char)255, (char)187, (char)255, (char)205, (char)205, (char)188, (char)255, (char)186,
                        (char)200, (char)205, (char)205, (char)205, (char)202, (char)205, (char)188, (char)255, (char)200, (char)205, (char)205, (char)205, (char)205, (char)205, (char)188};
   for(int i=0;i<15;i++)
   {
       for(int j=0;j<15;j++)
       {
           cout<<maze[i][j];
       }
       cout<<endl;
   }
}

