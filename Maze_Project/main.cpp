#include <cstdlib>
#include <iostream>
#include <conio.h>

using namespace std;

void drawMaze(char maze[15][15]);
void moveSprite(int y, int x, char maze[15][15]);
bool checkIfCollide(int y, int x, char maze[15][15], string direction);

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
                        (char)186, (char)255, (char)186, (char)255, (char)201, (char)205, (char)187, (char)255, (char)204, (char)205, (char)205, (char)205, (char)205, (char)255, (char)186,
                        (char)186, (char)255, (char)186, (char)255, (char)255, (char)255, (char)186, (char)255, (char)186, (char)255, (char)255, (char)255, (char)255, (char)255, (char)186,
                        (char)200, (char)205, (char)202, (char)205, (char)202, (char)205, (char)202, (char)205, (char)202, (char)205, (char)205, (char)176, (char)205, (char)205, (char)188};
    drawMaze(Map);
    int y_coord = 1;
    int x_coord = 3;
    moveSprite(y_coord, x_coord, Map);
    string direction;
    checkIfCollide(y_coord, x_coord, Map, direction);
    cout<<"Congratulations! You have completed the maze!"<<endl<<endl;
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
   while(maze[14][11] != (char)248)
   {
       direction = getch();
       if ((direction == 'w') and (checkIfCollide(y, x, maze, "Up")))
       {
           maze[y][x] = maze[y-1][x];
           maze[y-1][x] = (char)248;
           y--;
       }
       if ((direction == 'a') and (checkIfCollide(y, x, maze, "Left")))
       {
           maze[y][x] = maze[y][x-1];
           maze[y][x-1] = (char)248;
           x--;
       }
       if ((direction == 's') and (checkIfCollide(y, x, maze, "Down")))
       {
           maze[y][x] = maze[y+1][x];
           maze[y+1][x] = (char)248;
           y++;
       }
       if ((direction == 'd') and (checkIfCollide(y, x, maze, "Right")))
       {
           maze[y][x] = maze[y][x+1];
           maze[y][x+1] = (char)248;
           x++;
       }
       drawMaze(maze);
   }
   maze[13][11] = (char)255;
   drawMaze(maze);
}

bool checkIfCollide(int y, int x, char maze[15][15], string direction)
{
    if (direction == "Up")
    {
        if ((maze[y-1][x] == (char)186) or (maze[y-1][x] == (char)187) or (maze[y-1][x] == (char)188) or (maze[y-1][x] == (char)200) or (maze[y-1][x] == (char)201) or (maze[y-1][x] == (char)205))
        {
            return false;
        }
    }
    else if (direction == "Left")
    {
        if ((maze[y][x-1] == (char)186) or (maze[y][x-1] == (char)187) or (maze[y][x-1] == (char)188) or (maze[y][x-1] == (char)200) or (maze[y][x-1] == (char)201) or (maze[y][x-1] == (char)205))
        {
            return false;
        }
    }
    else if (direction == "Down")
    {
        if ((maze[y+1][x] == (char)186) or (maze[y+1][x] == (char)187) or (maze[y+1][x] == (char)188) or (maze[y+1][x] == (char)200) or (maze[y+1][x] == (char)201) or (maze[y+1][x] == (char)205))
        {
            return false;
        }
    }
    else if (direction == "Right")
    {
        if ((maze[y][x+1] == (char)186) or (maze[y][x+1] == (char)187) or (maze[y][x+1] == (char)188) or (maze[y][x+1] == (char)200) or (maze[y][x+1] == (char)201) or (maze[y][x+1] == (char)205))
        {
            return false;
        }
    }
    return true;
}
