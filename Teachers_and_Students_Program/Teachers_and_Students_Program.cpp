#include <iostream>
#include <cstdlib>

using namespace std;

class Student
{
    string firstName;
    string lastName;
    int studentNumber;
    int grade;
    int birthday[3] = {};
    string schedule[4] = {};
};

class Teacher
{
    string firstName;
    string lastName;
    string schedule[4] = {};
};

void addStudent(vector<Student> _students)
{

}

void modifyStudent(vector<Student> _students)
{

}

void removeStudent(vector<Student> _students)
{

}

void addTeacher(vector<Teacher> _teachers)
{

}

void modifyTeacher(vector<Teacher> _teachers)
{

}

void removeTeacher(vector<Teacher> _teachers)
{

}

void displayStudentTimetable(vector<Student> _students)
{

}

void displayTeacherTimetable(vector<Teacher> _teachers)
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
            addStudent(students);
            break;
        case 2:
            modifyStudent(students);
            break;
        case 3:
            removeStudent(students);
            break;
        case 4:
            addTeacher(teachers);
            break;
        case 5:
            modifyTeacher(teachers);
            break;
        case 6:
            removeTeacher(teachers);
            break;
        case 7:
            displayStudentTimetable(students);
            break;
        case 8:
            displayTeacherTimetable(students);
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
    vector<Student> students;
    vector<Teacher> teachers;
    menu();
}
