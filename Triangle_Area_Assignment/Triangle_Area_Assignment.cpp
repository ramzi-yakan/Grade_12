#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

class Triangle
{
    float side[3] = {0,0,0};
    float semiPerimeter;
    float area;
    float height[3];
public:
    void isTriangleValid()
    {
        float largestSide;
        float smallerSide1;
        float smallerSide2;
        float smallerSideTotal;
        while ((side[0] <= 0) or (side[1] <=0) or (side[2] <= 0) or (largestSide >= smallerSideTotal))
        {
            cout << "Please enter 3 side lengths." << endl;
            cout << "Side 1: ";
            cin >> side[0];
            cout << endl;
            cout << "Side 2: ";
            cin >> side[1];
            cout << endl;
            cout << "Side 3: ";
            cin >> side[2];
            cout << endl;
            if ((side[0] > side[1]) and (side[0] > side[2]))
            {
                largestSide = side[0];
                smallerSide1 = side[1];
                smallerSide2 = side[2];
            }
            else if ((side[1] > side[0]) and (side[1] > side[2]))
            {
                largestSide = side[1];
                smallerSide1 = side[0];
                smallerSide2 = side[2];
            }
            else if ((side[2] > side[0]) and (side[2] > side[1]))
            {
                largestSide = side[2];
                smallerSide1 = side[0];
                smallerSide2 = side[1];
            }
            smallerSideTotal = smallerSide1 + smallerSide2;
            if ((side[0] <= 0) or (side[1] <=0) or (side[2] <= 0) or (largestSide >= smallerSideTotal))
            {
                cout << "Not a valid triangle." << endl << endl;
            }
        }
    }
    float getSemiPerimeter()
    {
        semiPerimeter = (side[0] + side[1] + side[2])/2;
        cout << "Semiperimeter: " << semiPerimeter << endl;
    }
    float getArea()
    {
        area = sqrt(semiPerimeter*(semiPerimeter - side[0])*(semiPerimeter - side[1])*(semiPerimeter - side[2]));
        cout << "Area: " << area << endl;
    }
    float getHeight()
    {
        for (int i = 0; i < 3; i++)
        {
            height[i] = 2*area/side[i];
            cout << "Height from side "<< i+1 << ": " << height[i] << endl;
        }
    }
    void getName()
    {
        if ((side[0] == side[1]) and (side[0] == side[2]) and (side[1] == side[2]))
        {
            cout << "Type of Triangle: Equilateral" << endl;
        }
        else if ((side[0] != side[1]) and (side[0] != side[2]) and (side[1] != side[2]))
        {
            cout << "Type of Triangle: Scalene" << endl;
        }
        else
        {
            cout << "Type of Triangle: Isosceles" << endl;
        }
    }
};

bool tryAgain()
{
    string answer;
    while ((answer != "y") and (answer != "n"))
    {
        cout << "Try again?" << endl;
        cin >> answer;
        if (answer == "y")
        {
            return true;
        }
        else if (answer == "n")
        {
            return false;
        }
        else
        {
            cout << "Please provide a valid answer." << endl;
        }
    }
}

int main()
{
    Triangle _triangle;
    bool programStatus = true;
    while (programStatus == true)
    {
        _triangle.isTriangleValid();
        _triangle.getSemiPerimeter();
        _triangle.getArea();
        _triangle.getHeight();
        _triangle.getName();
        cout << endl;
        programStatus = tryAgain();
        cout << endl << endl;
    }
    return 0;
}
