#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

void factorialCalculator ()
{
    int factorialSum = 1;
    cout << "1!= " << factorialSum << endl;
}

void fibonacciCalculator ()
{

}

void squareNumberCalculator ()
{

}

void keyboardInputReverse ()
{

}

void primeNumberCalculator ()
{

}

void selectProgram ()
{
    string buffer;
    int option = 0;
    while ((option < 1) or (option > 6))
    {
        cout << "Please select a program:" << endl;
        cout << "1) Factorial Calculator" << endl;
        cout << "2) Fibonacci Calculator" << endl;
        cout << "3) Square Number Calculator" << endl;
        cout << "4) Keyboard Input Reverse" << endl;
        cout << "5) Prime Number Calculator" << endl;
        cout << "6) Exit Program" << endl;
        getline(cin, buffer);
        stringstream(buffer) >> option;
        switch (option)
        {
            case 1:
                factorialCalculator();
                break;
            case 2:
                fibonacciCalculator();
                break;
            case 3:
                squareNumberCalculator();
                break;
            case 4:
                keyboardInputReverse();
                break;
            case 5:
                primeNumberCalculator();
                break;
            case 6:
                break;
            default:
                cout << "Please enter a valid option." << endl << endl;
        }
    }
}

int main()
{
    selectProgram();
    return 0;
}
