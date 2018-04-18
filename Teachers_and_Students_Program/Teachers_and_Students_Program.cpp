#include <iostream>
#include <cstdlib>

using namespace std;

class Teacher
{
    string firstName;
    string lastName;
    string schedule[4] = {};
};

class Student
{
    string firstName;
    string lastName;
    int studentNumber;
    int grade;
    int birthday[3] = {};
    string schedule[4] = {};
};

void addStudent()
{

}

void modifyStudent()
{

}

void removeStudent()
{

}

void addTeacher()
{

}

void modifyTeacher()
{

}

void removeTeacher()
{

}

void displayStudentTimetable()
{

}

void displayTeacherTimetable()
{

}

void menu()
{
    int option;
    cout << "Welcome user!" << endl;
    cout << "What would you like to do?" << endl;
    cout << "1) Add a student" << endl;
    cout << "2) Modify a student" << endl;
    cout << "3) Remove a student" << endl;
    cout << "4) Add a teacher" << endl;
    cout << "5) Modify a teacher" << endl;
    cout << "6) Remove a techer" << endl;
    cout << "7) Display student timetable" << endl;
    cout << "8) Display teacher timetable" << endl;
    cout << "9) Quit program" << endl;
    while ((option < 1) or (option > 9))
    {
        cin >> option;
        switch (option)
        {
        case 1:
            addStudent();
            break;
        case 2:
            modifyStudent();
            break;
        case 3:
            removeStudent();
            break;
        case 4:
            addTeacher();
            break;
        case 5:
            modifyTeacher();
            break;
        case 6:
            removeTeacher();
            break;
        case 7:
            displayStudentTimetable();
            break;
        case 8:
            displayTeacherTimetable();
            break;
        case 9:
            break;
        default:
            cout << "Not a valid option. Try again." << endl << endl;
            //cout << "What would you like to do?" << endl;
        }
    }
}

int main()
{
    menu();
}
