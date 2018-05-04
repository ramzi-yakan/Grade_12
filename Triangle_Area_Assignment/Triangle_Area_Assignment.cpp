#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

class Triangle
{
    float side1;
    float side2;
    float side3;
    float semiPerimeter;
    float area;
public:
    void isTriangleValid()
    {
        float largestSide;
        float smallerSide1;
        float smallerSide2;
        float smallerSideTotal;
        while ((side1 <= 0) or (side2 <=0) or (side3 <= 0) or (largestSide >= smallerSideTotal))
        {
            cout << "Please enter 3 side lengths." << endl;
            cout << "Side 1: ";
            cin >> side1;
            cout << endl;
            cout << "Side 2: ";
            cin >> side2;
            cout << endl;
            cout << "Side 3: ";
            cin >> side3;
            cout << endl;
            if ((side1 > side2) and (side1 > side3))
            {
                largestSide = side1;
                smallerSide1 = side2;
                smallerSide2 = side3;
            }
            else if ((side2 > side1) and (side2 > side3))
            {
                largestSide = side2;
                smallerSide1 = side1;
                smallerSide2 = side3;
            }
            else if ((side3 > side1) and (side3 > side2))
            {
                largestSide = side3;
                smallerSide1 = side1;
                smallerSide2 = side2;
            }
            smallerSideTotal = smallerSide1 + smallerSide2;
            if ((side1 <= 0) or (side2 <=0) or (side3 <= 0) or (largestSide >= smallerSideTotal))
            {
                cout << "Not a valid triangle." << endl << endl;
            }
        }
    }
    void getSemiPerimeter()
    {

    }
    void getArea()
    {

    }
    void getHeight()
    {

    }
    void getName()
    {

    }
};

int main()
{
    Triangle _triangle;
    _triangle.isTriangleValid();
    _triangle.getSemiPerimeter();
    _triangle.getArea();
    _triangle.getName();
    return 0;
}
