// Ramzi Yakan
// Class Report

#include <cstdlib>
#include <iostream>

using namespace std;

class Report
{
    int studentNumber;
    string name;
    float averageMark;
    float getAverage(int mark1, int mark2, int mark3, int mark4, int mark5)
    {
        averageMark = (mark1 + mark2 + mark3 + mark4 + mark5);
        return (float)averageMark / 5;
    }
public:
    void readInfo(int mark1, int mark2, int mark3, int mark4, int mark5)
    {
        name = "This is a really long name";
        while (name.length() > 20)
        {
            cout << "Please enter the name of the student." << endl;
            cin >> name;
            if (name.length() > 20)
            {
                cout << "This name is too long. Please enter a different name." << endl;
            }
        }
        while ((mark1 < 0) or (mark1 > 100))
        {
            cout << endl;
            cout << "Please enter " << name <<"'s first mark." << endl;
            cin >> mark1;
            if ((mark1 < 0) or (mark1 > 100))
            {
                cout << "You deserve a big fat 0 for that response..." << endl;
            }
        }
        while ((mark2 < 0) or (mark2 > 100))
        {
            cout << endl;
            cout << "Please enter " << name <<"'s second mark." << endl;
            cin >> mark2;
            if ((mark2 < 0) or (mark2 > 100))
            {
                cout << "You deserve a big fat 0 for that response..." << endl;
            }
        }
        while ((mark3 < 0) or (mark3 > 100))
        {
            cout << endl;
            cout << "Please enter " << name <<"'s third mark." << endl;
            cin >> mark3;
            if ((mark3 < 0) or (mark3 > 100))
            {
                cout << "You deserve a big fat 0 for that response..." << endl;
            }
        }
        while ((mark4 < 0) or (mark4 > 100))
        {
            cout << endl;
            cout << "Please enter " << name <<"'s fourth mark." << endl;
            cin >> mark4;
            if ((mark4 < 0) or (mark4 > 100))
            {
                cout << "You deserve a big fat 0 for that response..." << endl;
            }
        }
        while ((mark5 < 0) or (mark5 > 100))
        {
            cout << endl;
            cout << "Please enter " << name <<"'s fifth mark." << endl;
            cin >> mark5;
            if ((mark5 < 0) or (mark5 > 100))
            {
                cout << "You deserve a big fat 0 for that response..." << endl;
            }
        }
        averageMark = getAverage(mark1, mark2, mark3, mark4, mark5);
        cout << endl;
        cout << "Average mark: " << averageMark << endl;
    }
    void displayInfo()
    {

    }
};

int main()
{
    Report report;
    int mark1;
    int mark2;
    int mark3;
    int mark4;
    int mark5;
    report.readInfo(mark1, mark2, mark3, mark4, mark5);
}
