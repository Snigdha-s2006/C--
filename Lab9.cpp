/*Write a program to swap two numbers using Friend Function (create two classes).
Definition: A friend function is a function that can access the private and protected members of a class.*/

#include <iostream>
using namespace std;

class B;

class A
{
    int x;

public:
    void getA()
    {
        cout << "Enter first number: ";
        cin >> x;
    }

    friend void swap(A &, B &);
};

class B
{
    int y;

public:
    void getB()
    {
        cout << "Enter second number: ";
        cin >> y;
    }

    friend void swap(A &, B &);
};

void swap(A &a, B &b)
{
    int temp;

    temp = a.x;
    a.x = b.y;
    b.y = temp;

    cout << "After swapping:" << endl;
    cout << "First number: " << a.x << endl;
    cout << "Second number: " << b.y << endl;
}

int main()
{
    A obj1;
    B obj2;

    obj1.getA();
    obj2.getB();

    swap(obj1, obj2);

    return 0;
}
