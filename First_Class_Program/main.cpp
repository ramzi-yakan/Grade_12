#include <iostream>
#include <cstdlib>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class City
{
    public:
    string name;
    int population;
    int length;
    int width;
    string capital;
    int area()
    {
        return length*width;
    }
};

void executeProgram()
{
    City theCity;
    cout << "Please enter the name of your city." << endl;
    cin >> theCity.name;
    cout << endl;
    cout << "Please enter the population of your city." << endl;
    cin >> theCity.population;
    cout << endl;
    cout << "Please enter the length of your city." << endl;
    cin >> theCity.length;
    cout << endl;
    cout << "Please enter the width of your city." << endl;
    cin >> theCity.width;
    cout << endl;
    while ((theCity.capital != "yes") and (theCity.capital != "no"))
    {
        cout << "Is your city a capital city? (yes/no)" << endl;
        cin >> theCity.capital;
        if ((theCity.capital != "yes") and (theCity.capital != "no"))
        {
            cout << "Please enter either yes or no." << endl << endl;
        }
    }
    cout << endl;
    cout << theCity.name << endl;
    cout << "Population: " << theCity.population << endl;
    cout << "Area: " << theCity.area() << endl;
    cout << "Capital City? " << theCity.capital << endl;
}

int main()
{
    executeProgram();
    return 0;
}
