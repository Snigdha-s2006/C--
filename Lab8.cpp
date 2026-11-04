/*Design three classes: Student, Exam and Result using inheritance.
Type of inheritance: Multilevel Inheritance
Student → Exam → Result*/

#include <iostream>
using namespace std;

class Student
{
public:
    int roll;
    string name;

    void getStudent()
    {
        cout << "Enter Roll No: ";
        cin >> roll;
        cout << "Enter Name: ";
        cin >> name;
    }
};

class Exam : public Student
{
public:
    int marks[6];

    void getMarks()
    {
        cout << "Enter marks of 6 subjects:\n";
        for(int i = 0; i < 6; i++)
            cin >> marks[i];
    }
};

class Result : public Exam
{
public:
    int total = 0;

    void display()
    {
        for(int i = 0; i < 6; i++)
            total += marks[i];

        cout << "\nRoll No: " << roll;
        cout << "\nName: " << name;
        cout << "\nTotal Marks: " << total;
    }
};

int main()
{
    Result r;

    r.getStudent();
    r.getMarks();
    r.display();

    return 0;
}