//c++ Program: Function Overloading to Calculate Area of Circle, Rectangle and Triangle

#include <iostream>
using namespace std;

class Area
{
public:

    void calculate(float r)
    {
        cout << "Area of Circle = " << 3.14*r*r << endl;
    }

    void calculate(float l, float b)
    {
        cout << "Area of Rectangle = " << l*b << endl;
    }

    void calculate(int b, int h, int x)
    {
        cout << "Area of Triangle = " << 0.5*b*h << endl;
    }
};

int main()
{
    Area a;

    a.calculate(5.0f);
    a.calculate(10.0f, 5.0f);
    a.calculate(4, 6, 0);

    return 0;
}