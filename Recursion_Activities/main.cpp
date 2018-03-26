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

int squareNumberCalculator (int n)
{
    /*int previousAnswer;
    previousAnswer = squareNumberCalculator(n-1);
    int tempAnswer;
    tempAnswer = previousAnswer+2(n-1)-1;
    int answer = tempAnswer;
    return answer;*/
}

void getTextLength (int length)
{
    string buffer;
    cout << "Please enter a text length." << endl;
    while (length < 1)
    {
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
    //cout << "Enter your message." <<endl;
    cin.get(letter);
    cout.put(letter);
    keyboardInputReverse(length);
}

bool primeNumberCalculator (int n, int d)
{
    //cout << n << "/" << d << endl;
    if (d == 1)
    {
        cout << endl;
        cout << "Prime" << endl;
        return true;
    }
    else if (n%d == 0)
    {
        cout << endl;
        cout << "Not Prime" << endl;
        return false;
    }
    else
    {
        primeNumberCalculator (n, d-1);
    }
}

void selectProgram ()
{
    string buffer;
    int option = 0;
    int number;
    int divisor;
    int numberSquared;
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
                factorialCalculator(number);
                selectProgram();
                break;
            case 2:
                fibonacciCalculator();
                selectProgram();
                break;
            case 3:
                number = 1;
                numberSquared = squareNumberCalculator(number);
                selectProgram();
                break;
            case 4:
                getTextLength(textLength);
                keyboardInputReverse(textLength);
                selectProgram();
                break;
            case 5:
                cout << endl;
                cout << "Please enter a number." << endl;
                getline(cin, buffer);
                stringstream(buffer) >> number;
                cout << endl;
                divisor = number/2;
                primeNumberCalculator(number, divisor);
                cout << endl << endl << endl;
                selectProgram();
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
