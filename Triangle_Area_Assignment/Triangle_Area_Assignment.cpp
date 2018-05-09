#include <iostream>
#include <cstdlib>
#include <math.h>   //for sqrt function

using namespace std;

class Triangle
{
    float side[3];              //array that stores the 3 side lengths of the triangle
    float perimeter;            //variable that stores the perimeter of the triangle
    float semiPerimeter;        //variable that stores the semiperimeter of the triangle
    float area;                 //variable that stores the area of the triangle
    float height[3];            //array that stores the height of the triangle from all 3 side lengths
public:
    void isTriangleValid()      //function that checks if user-created triangle can theoretically exist
    {
        float largestSide;      //variable that stores the value of the largest side length
        float smallerSide1;     //variables that each store one of the 2 remaining side lengths
        float smallerSide2;
        float smallerSideTotal; //variable that stores the sum of the smaller side lengths
        while (largestSide >= smallerSideTotal)  //condition that needs to be broken in order for a triangle to theoretically exist, while loop continues until this condition is broken
        {
            cout << "Please enter 3 side lengths (in cm)." << endl;
            for (int i = 0; i < 3; i++)  //side 1 is in position 0 of the array, side 2 is in postion 1 of the array, side 3 is in position 2 of the array
            {
                side[i] = 0;
                while ((side[i] <= 0) or (cin.fail() == true))   //conditions required for a side length to theoretically exist, while not breaking the program, while loop continues until both conditions are broken
                {
                    cout << "Side " << i+1 << ": ";
                    cin >> side[i];   //user inputs side lengths
                    cout << endl;
                    if ((side[i] <= 0) or (cin.fail() == true))   //if inputted side length cannot theoretically exist or breaks the program
                    {
                        cout << "Please provide a valid side length." << endl;
                        if (cin.fail() == true)
                        {
                            cin.clear();    //clears inputted side length
                            cin.ignore();   //ignores inputted side length
                            side[i] = 0;
                        }
                    }
                }
            }
            if ((side[0] > side[1]) and (side[0] > side[2]))       //if the first inputted side length is the largest...
            {
                largestSide = side[0];
                smallerSide1 = side[1];
                smallerSide2 = side[2];
            }
            else if ((side[1] > side[0]) and (side[1] > side[2]))   //if the second inputted side length is the largest...
            {
                largestSide = side[1];
                smallerSide1 = side[0];
                smallerSide2 = side[2];
            }
            else if ((side[2] > side[0]) and (side[2] > side[1]))   //if the third inputted side length is the largest...
            {
                largestSide = side[2];
                smallerSide1 = side[0];
                smallerSide2 = side[1];
            }
            smallerSideTotal = smallerSide1 + smallerSide2;
            if (largestSide >= smallerSideTotal)
            {
                cout << "Not a valid triangle." << endl << endl;
            }
        }
    }
    float getPerimeter()
    {
        perimeter = side[0] + side[1] + side[2];
        cout << "Perimeter: " << perimeter << " cm" << endl;
    }
    float getSemiPerimeter()
    {
        semiPerimeter = perimeter/2;
        cout << "Semiperimeter: " << semiPerimeter << " cm" << endl;
    }
    float getArea()
    {
        area = sqrt(semiPerimeter*(semiPerimeter - side[0])*(semiPerimeter - side[1])*(semiPerimeter - side[2]));
        cout << "Area: " << area << " cm^2" << endl;
    }
    float getHeight()
    {
        for (int i = 0; i < 3; i++)
        {
            height[i] = 2*area/side[i];
            cout << "Height from side "<< i+1 << ": " << height[i] << " cm" << endl;
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
    cout << "Try again?" << endl;
    while ((answer != "y") and (answer != "n"))
    {
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
            cout << endl;
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
        _triangle.getPerimeter();
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
