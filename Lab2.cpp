//C++ Program to Show the Effect of Call by Reference

#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x = 10, y = 20;

    cout << "Before swapping: " << x << " " << y << endl;

    swap(x, y);

    cout << "After swapping: " << x << " " << y;

    return 0;
}