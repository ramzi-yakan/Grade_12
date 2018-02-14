#include <cstdlib>
#include <iostream>

using namespace std;

void drawMaze(char maze[15][15]);

int main()
{
    char Map[15][15];
    drawMaze(Map);
}

void drawMaze(char maze[15][15])
{
   for(int i=0;i<15;i++)
   {
       for(int j=0;j<15;j++)
       {
           maze[i][j]=(char)255;
           maze[i][0]=(char)186;
           maze[i][14]=(char)186;
           maze[0][j]=(char)205;
           maze[14][j]=(char)205;
           maze[0][0]=(char)201;
           maze[0][14]=(char)187;
           maze[14][0]=(char)200;
           maze[14][14]=(char)188;
           maze[i][12]=(char)186;
           if ((i>=2) and (i<=12))
           {
                maze[i][12];
           }
           cout<<maze[i][j];
       }
       cout<<endl;
   }
}
