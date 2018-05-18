/* Ramzi Yakan
   Triangle Area Assignment
   Asks the user for 3 sides lengths of a triangle, then uses the inputted side lengths calculates the perimeter, semiperimeter, area, and height of the triangle (from each side).
   May 11 2018
   */

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
        float largestSide = 0;      //variable that stores the value of the largest side length
        float smallerSide1;     //variables that each store one of the 2 remaining side lengths
        float smallerSide2;
        float smallerSideTotal = 0; //variable that stores the sum of the smaller side lengths
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
                    if ((side[i] <= 0) or (cin.fail() == true))   //if inputted side length cannot theoretically exist or will break the program
                    {
                        cout << "Please provide a valid side length." << endl;
                        if (cin.fail() == true)  //if inputted side length will break the program
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
            else
            {
                largestSide = side[2];
                smallerSide1 = side[0];
                smallerSide2 = side[1];
            }
            smallerSideTotal = smallerSide1 + smallerSide2;
            if (largestSide >= smallerSideTotal)    //if triangle cannot theoretically exist
            {
                cout << "Not a valid triangle." << endl << endl << endl;
            }
        }
    }
    void getPerimeter()     //function that calculates the perimeter of the triangle
    {
        perimeter = side[0] + side[1] + side[2];    //calculation for perimeter
        cout << "Perimeter: " << perimeter << " cm" << endl;
    }
    void getSemiPerimeter()  //function that calculates the semiperimeter of the triangle
    {
        semiPerimeter = perimeter/2;    //calculation for semiperimeter
        cout << "Semiperimeter: " << semiPerimeter << " cm" << endl;
    }
    void getArea()     //function that calculates the area of the triangle
    {
        area = sqrt(semiPerimeter*(semiPerimeter - side[0])*(semiPerimeter - side[1])*(semiPerimeter - side[2]));   //calculation for area
        cout << "Area: " << area << " cm^2" << endl;
    }
    void getHeight()       //function that calculates the height of the triangle from each of its three sides
    {
        for (int i = 0; i < 3; i++)     //calculation needs to be done 3 times since there are 3 sides
        {
            height[i] = 2*area/side[i];    //calculation for height
            cout << "Height from side "<< i+1 << ": " << height[i] << " cm" << endl;
        }
    }
    void getName()
    {
        if ((side[0] == side[1]) and (side[0] == side[2]) and (side[1] == side[2]))   //if all sides of the triangle are of equal length
        {
            cout << "Type of Triangle: Equilateral" << endl;
        }
        else if ((side[0] != side[1]) and (side[0] != side[2]) and (side[1] != side[2]))   //if each side of the triangle has a different length
        {
            cout << "Type of Triangle: Scalene" << endl;
        }
        else    //if 2 of the sides of the triangle are of equal length
        {
            cout << "Type of Triangle: Isosceles" << endl;
        }
    }
    Triangle();  //use of constructor
};

bool runAgain()     //boolean function that asks the user if they want to run the program again, returns user's answer to int main
{
    string answer;
    cout << "Run the program again? (y/n)" << endl;
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

Triangle::Triangle()    //use of constructor
{
    cout << "Welcome to the Triangle Area Program." << endl << endl << endl << endl;
}

int main()
{
    Triangle _triangle;
    bool programStatus = true;  //variable that determines whether the program is still running
    while (programStatus == true)
    {
        _triangle.isTriangleValid();
        _triangle.getPerimeter();
        _triangle.getSemiPerimeter();
        _triangle.getArea();
        _triangle.getHeight();
        _triangle.getName();
        cout << endl;
        programStatus = runAgain();
        cout << endl << endl;
    }
    return 0;
}
