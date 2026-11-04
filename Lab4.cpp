//Define a class Shape whose attributes are radius, length and width. Calculate the perimeter of the rectangle of a circle using constructor and destructors.

#include <iostream>
using namespace std;

class Shape
{
    float radius, length, width;

public:
    Shape(float r, float l, float w)
    {
        radius = r;
        length = l;
        width = w;
    }

    void calculate()
    {
        cout << "Perimeter of Circle = " << 2 * 3.14 * radius << endl;
        cout << "Perimeter of Rectangle = " << 2 * (length + width) << endl;
    }

    ~Shape()
    {
        cout << "Destructor called";
    }
};

int main()
{
    Shape s(5, 10, 6);
    s.calculate();

    return 0;
}