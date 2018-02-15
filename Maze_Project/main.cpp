#include <cstdlib>
#include <iostream>
#include <conio.h>

using namespace std;

void drawMaze(char maze[15][15]);
void moveSprite(int y, int x, char maze[15][15]);
void checkIfCollide();

int main()
{
    char Map[15][15] = {(char)201, (char)205, (char)205, (char)205, (char)203, (char)205, (char)205, (char)205, (char)203, (char)205, (char)205, (char)205, (char)203, (char)205, (char)187,
                        (char)186, (char)255, (char)255, (char)248, (char)186, (char)255, (char)255, (char)255, (char)186, (char)255, (char)255, (char)255, (char)186, (char)255, (char)186,
                        (char)186, (char)255, (char)200, (char)205, (char)206, (char)205, (char)188, (char)255, (char)200, (char)205, (char)188, (char)255, (char)186, (char)255, (char)186,
                        (char)186, (char)255, (char)255, (char)255, (char)186, (char)255, (char)255, (char)255, (char)255, (char)255, (char)255, (char)255, (char)186, (char)255, (char)186,
                        (char)186, (char)255, (char)186, (char)255, (char)186, (char)255, (char)186, (char)255, (char)201, (char)205, (char)187, (char)255, (char)186, (char)255, (char)186,
                        (char)186, (char)255, (char)186, (char)255, (char)186, (char)255, (char)186, (char)255, (char)186, (char)255, (char)186, (char)255, (char)255, (char)255, (char)186,
                        (char)186, (char)255, (char)200, (char)205, (char)202, (char)205, (char)188, (char)255, (char)186, (char)255, (char)186, (char)255, (char)200, (char)205, (char)185,
                        (char)186, (char)255, (char)255, (char)255, (char)255, (char)255, (char)255, (char)255, (char)186, (char)255, (char)255, (char)255, (char)255, (char)255, (char)186,
                        (char)204, (char)205, (char)205, (char)205, (char)203, (char)205, (char)187, (char)255, (char)186, (char)255, (char)201, (char)205, (char)187, (char)255, (char)186,
                        (char)186, (char)255, (char)255, (char)255, (char)186, (char)255, (char)255, (char)255, (char)186, (char)255, (char)255, (char)255, (char)186, (char)255, (char)186,
                        (char)186, (char)255, (char)186, (char)255, (char)200, (char)205, (char)188, (char)255, (char)186, (char)255, (char)200, (char)205, (char)188, (char)255, (char)186,
                        (char)186, (char)255, (char)186, (char)255, (char)255, (char)255, (char)255, (char)255, (char)186, (char)255, (char)255, (char)255, (char)255, (char)255, (char)186,
                        (char)186, (char)255, (char)186, (char)255, (char)201, (char)205, (char)187, (char)255, (char)204, (char)205, (char)205, (char)205, (char)255, (char)255, (char)186,
                        (char)186, (char)255, (char)186, (char)255, (char)255, (char)255, (char)186, (char)255, (char)186, (char)255, (char)255, (char)255, (char)255, (char)255, (char)186,
                        (char)200, (char)205, (char)202, (char)205, (char)202, (char)205, (char)202, (char)205, (char)202, (char)205, (char)205, (char)176, (char)176, (char)205, (char)188};
    drawMaze(Map);
    int y_coord = 1;
    int x_coord = 3;
    moveSprite(y_coord, x_coord, Map);
}

void drawMaze(char maze[15][15])
{
   system("CLS");
   for(int i=0;i<15;i++)
   {
       for(int j=0;j<15;j++)
       {
           cout<<maze[i][j];
       }
       cout<<endl;
   }
}

void moveSprite(int y, int x, char maze[15][15])
{
   char direction;
   while(true)
   {
       direction = getch();
       if (direction == 'w')
       {
           maze[y][x] = maze[y-1][x];
           maze[y-1][x] = (char)248;
           y--;
       }
       if (direction == 'a')
       {
           maze[y][x] = maze[y][x-1];
           maze[y][x-1] = (char)248;
           x--;
       }
       if (direction == 's')
       {
           maze[y][x] = maze[y+1][x];
           maze[y+1][x] = (char)248;
           y++;
       }
       if (direction == 'd')
       {
           maze[y][x] = maze[y][x+1];
           maze[y][x+1] = (char)248;
           x++;
       }
       drawMaze(maze);
   }
}

