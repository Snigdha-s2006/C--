/*Create a class Person
The class contains:
Name – character array of size 64.
Age – integer.
Address – character array of size 64.
Salary – divided into different components.
Create an array of 10 Person objects.
(a) Write an inline function to find the youngest and oldest person using an array.
(b) Use inline function to find youngest and oldest*/



#include <iostream>
using namespace std;

class Person
{
public:
    char name[64];
    int age;
    char address[64];
    float basic, hra, da;

};

inline void findYoungOld(Person p[])
{
    int min = p[0].age;
    int max = p[0].age;

    int young = 0;
    int old = 0;

    for(int i = 1; i < 10; i++)
    {
        if(p[i].age < min)
        {
            min = p[i].age;
            young = i;
        }

        if(p[i].age > max)
        {
            max = p[i].age;
            old = i;
        }
    }

    cout << "\nYoungest Person: ";
    cout << p[young].name << " " << p[young].age << endl;

    cout << "Oldest Person: ";
    cout << p[old].name << " " << p[old].age << endl;
}

int main()
{
    Person p[10];

    for(int i = 0; i < 10; i++)
    {
        cout << "\nEnter name, age and address: ";
        cin >> p[i].name >> p[i].age >> p[i].address;

        cout << "Enter Basic Salary, HRA and DA: ";
        cin >> p[i].basic >> p[i].hra >> p[i].da;
    }

    findYoungOld(p);

    return 0;
}
