//Create a class Complex to overload increment (++) and decrement (--) operators.

#include <iostream>
using namespace std;

class Complex
{
    int real, imag;

public:
    Complex(int r, int i)
    {
        real = r;
        imag = i;
    }

    void operator++()
    {
        real++;
        imag++;
    }

    void operator--()
    {
        real--;
        imag--;
    }

    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main()
{
    Complex c(5, 3);

    cout << "Original: ";
    c.display();

    ++c;

    cout << "After Increment: ";
    c.display();

    --c;

    cout << "After Decrement: ";
    c.display();

    return 0;
}



