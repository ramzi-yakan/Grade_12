#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

int factorialCalculator (int n)
{
    if (n = 0)
    {

    }
}

void fibonacciCalculator ()
{

}

void squareNumberCalculator ()
{

}

void getTextLength (int length)
{
    string buffer;
    while (length < 1)
        {
            cout << "Please enter a text length." << endl;
            getline(cin, buffer);
            stringstream(buffer) >> length;
            if (length < 1)
            {
                cout << "Please enter a valid text length." << endl << endl;
            }
        }
}

void keyboardInputReverse (int length)
{
    char letter;
    cin.get(letter);
    keyboardInputReverse(length);
    cout.put(letter);
}

void primeNumberCalculator ()
{

}

void selectProgram ()
{
    string buffer;
    int option = 0;
    int n;
    int textLength = 0;
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
                factorialCalculator(n);
                break;
            case 2:
                fibonacciCalculator();
                break;
            case 3:
                squareNumberCalculator();
                break;
            case 4:
                getTextLength(textLength);
                keyboardInputReverse(textLength);
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
