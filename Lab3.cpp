/* C++ Program to Perform Matrix Operations Using Functions and Switch Case
Oerations: Addition, Subtraction, Multiplication and Transpose.*/

#include <iostream>
using namespace std;

void add(int a[10][10], int b[10][10], int r, int c)
{
    cout << "Addition:\n";
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
            cout << a[i][j] + b[i][j] << " ";
        cout << endl;
    }
}

void subtract(int a[10][10], int b[10][10], int r, int c)
{
    cout << "Subtraction:\n";
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
            cout << a[i][j] - b[i][j] << " ";
        cout << endl;
    }
}

void multiply(int a[10][10], int b[10][10], int r, int c)
{
    cout << "Multiplication:\n";
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            int sum = 0;
            for(int k=0; k<c; k++)
                sum += a[i][k] * b[k][j];
            cout << sum << " ";
        }
        cout << endl;
    }
}

void transpose(int a[10][10], int r, int c)
{
    cout << "Transpose:\n";
    for(int j=0; j<c; j++)
    {
        for(int i=0; i<r; i++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int a[10][10], b[10][10];
    int r, c, choice;

    cout << "Enter rows and columns: ";
    cin >> r >> c;

    cout << "Enter first matrix:\n";
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin >> a[i][j];

    cout << "Enter second matrix:\n";
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin >> b[i][j];

    cout << "\n1. Addition";
    cout << "\n2. Subtraction";
    cout << "\n3. Multiplication";
    cout << "\n4. Transpose";
    cout << "\nEnter choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1: add(a,b,r,c); break;
        case 2: subtract(a,b,r,c); break;
        case 3: multiply(a,b,r,c); break;
        case 4: transpose(a,r,c); break;
        default: cout << "Invalid choice";
    }

    return 0;
}
