#include <iostream>
#include <cstdlib>
#include <list>
#include <sstream>

using namespace std;

class Student
{
public:
    string firstName;
    string lastName;
    int studentNumber;
    int grade;
    const string jksk[2] = {"JK","SK"};
    int birthday[3] = {};
    string schedule[4] = {};
};

class Teacher
{
public:
    string firstName;
    string lastName;
    string schedule[4] = {};
};

void addStudent(list<Student> _students)
{
    Student buffer;
    string gradeBuffer;
    cout << "Please enter the student's first name." << endl;
    cin >> buffer.firstName;
    cout << "Please enter the student's last name." << endl;
    cin >> buffer.lastName;
    cout << "Please enter the student's student #." << endl;
    cin >> buffer.studentNumber;
    cout << "Please enter the student's grade." << endl;
    cin >> gradeBuffer;
    stringstream(gradeBuffer) >> buffer.grade;
    if ((gradeBuffer == "JK") or (gradeBuffer == "jk") or (gradeBuffer == "SK") or (gradeBuffer == "sk") or (gradeBuffer == "1")
}

void modifyStudent(list<Student> _students)
{

}

void removeStudent(list<Student> _students)
{

}

void addTeacher(list<Teacher> _teachers)
{

}

void modifyTeacher(list<Teacher> _teachers)
{

}

void removeTeacher(list<Teacher> _teachers)
{

}

void displayStudentTimetable(list<Student> _students)
{

}

void displayTeacherTimetable(list<Teacher> _teachers)
{

}

void menu(list<Student> _students, list<Teacher> _teachers)
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
            addStudent(_students);
            break;
        case 2:
            modifyStudent(_students);
            break;
        case 3:
            removeStudent(_students);
            break;
        case 4:
            addTeacher(_teachers);
            break;
        case 5:
            modifyTeacher(_teachers);
            break;
        case 6:
            removeTeacher(_teachers);
            break;
        case 7:
            displayStudentTimetable(_students);
            break;
        case 8:
            displayTeacherTimetable(_teachers);
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
    list<Student> students;
    list<Teacher> teachers;
    menu(students, teachers);
}
