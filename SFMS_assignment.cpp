#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;

// Abstract class
class Advisory
{
public:
    virtual void giveAdvice() = 0;
    virtual ~Advisory() {}
};

// Base class
class Crop
{
protected:
    string name, season;
    double area, yieldPerAcre;

public:
    static int count;

    // Default constructor
    Crop()
    {
        name = "Unknown";
        season = "Unknown";
        area = 1;
        yieldPerAcre = 1;
        count++;
    }

    // Parameterized constructor
    Crop(string n, double a, string s, double y)
    {
        if (a <= 0 || y <= 0)
            throw invalid_argument("Area and yield must be positive!");

        name = n;
        area = a;
        season = s;
        yieldPerAcre = y;
        count++;
    }

    // Virtual function
    virtual double calculateYield()
    {
        return area * yieldPerAcre;
    }

    // Display crop details
    virtual void display()
    {
        cout << "\nCrop Name: " << name;
        cout << "\nArea: " << area;
        cout << "\nSeason: " << season;
        cout << "\nYield Per Acre: " << yieldPerAcre;
        cout << "\nTotal Yield: " << calculateYield();
    }

    // Operator overloading
    bool operator>(Crop &c)
    {
        return calculateYield() > c.calculateYield();
    }

    // Save data into file
    virtual void saveToFile(ofstream &file)
    {
        file << name << " " << area << " "
             << season << " " << yieldPerAcre << endl;
    }

    virtual ~Crop() {}

    static void showCount()
    {
        cout << "\nTotal Crops: " << count << endl;
    }
};

int Crop::count = 0;

// Derived class 1
class CerealCrop : public Crop, public Advisory
{
    string fertilizer;
    int irrigation;

public:
    CerealCrop(string n, double a, string s,
               double y, string f, int i)
        : Crop(n, a, s, y)
    {
        fertilizer = f;
        irrigation = i;
    }

    double calculateYield() override
    {
        return area * yieldPerAcre;
    }

    void display() override
    {
        Crop::display();
        cout << "\nFertilizer: " << fertilizer;
        cout << "\nIrrigation Frequency: "
             << irrigation << " times/week\n";
    }

    void giveAdvice() override
    {
        cout << "Advice: Maintain proper irrigation "
             << "and use quality fertilizer.\n";
    }

    void saveToFile(ofstream &file) override
    {
        file << "Cereal Crop: ";
        Crop::saveToFile(file);
    }
};

// Derived class 2
class VegetableCrop : public Crop, public Advisory
{
    string fertilizer;
    int irrigation;

public:
    VegetableCrop(string n, double a, string s,
                  double y, string f, int i)
        : Crop(n, a, s, y)
    {
        fertilizer = f;
        irrigation = i;
    }

    double calculateYield() override
    {
        return area * yieldPerAcre;
    }

    void display() override
    {
        Crop::display();
        cout << "\nFertilizer: " << fertilizer;
        cout << "\nIrrigation Frequency: "
             << irrigation << " times/week\n";
    }

    void giveAdvice() override
    {
        cout << "Advice: Provide regular watering "
             << "and protect vegetables from pests.\n";
    }

    void saveToFile(ofstream &file) override
    {
        file << "Vegetable Crop: ";
        Crop::saveToFile(file);
    }
};

// Main function
int main()
{
    try
    {
        string name, season, fertilizer;
        double area, yield;
        int irrigation;

        // Taking cereal crop input
        cout << "Enter Cereal Crop Name: ";
        getline(cin, name);

        cout << "Enter Area: ";
        cin >> area;

        if (area <= 0)
            throw invalid_argument("Invalid area!");

        cin.ignore();

        cout << "Enter Season: ";
        getline(cin, season);

        cout << "Enter Yield Per Acre: ";
        cin >> yield;

        if (yield <= 0)
            throw invalid_argument("Invalid yield!");

        cin.ignore();

        cout << "Enter Fertilizer Type: ";
        getline(cin, fertilizer);

        cout << "Enter Irrigation Frequency: ";
        cin >> irrigation;

        if (irrigation < 0)
            throw invalid_argument("Invalid irrigation frequency!");

        cin.ignore();

        CerealCrop c1(name, area, season,
                      yield, fertilizer, irrigation);

        // Taking vegetable crop input
        cout << "\nEnter Vegetable Crop Name: ";
        getline(cin, name);

        cout << "Enter Area: ";
        cin >> area;

        if (area <= 0)
            throw invalid_argument("Invalid area!");

        cin.ignore();

        cout << "Enter Season: ";
        getline(cin, season);

        cout << "Enter Yield Per Acre: ";
        cin >> yield;

        if (yield <= 0)
            throw invalid_argument("Invalid yield!");

        cin.ignore();

        cout << "Enter Fertilizer Type: ";
        getline(cin, fertilizer);

        cout << "Enter Irrigation Frequency: ";
        cin >> irrigation;

        if (irrigation < 0)
            throw invalid_argument("Invalid irrigation frequency!");

        VegetableCrop c2(name, area, season,
                         yield, fertilizer, irrigation);

        // Runtime polymorphism
        Crop *ptr;

        cout << "\n--- CEREAL CROP DETAILS ---";
        ptr = &c1;
        ptr->display();

        cout << "\n--- VEGETABLE CROP DETAILS ---";
        ptr = &c2;
        ptr->display();

        // Total yield
        cout << "\n\nTotal Cereal Yield: "
             << c1.calculateYield();

        cout << "\nTotal Vegetable Yield: "
             << c2.calculateYield();

        // Operator overloading
        cout << "\n\n--- YIELD COMPARISON ---\n";

        if (c1 > c2)
            cout << "Cereal crop has higher yield.\n";
        else
            cout << "Vegetable crop has higher or equal yield.\n";

        // Abstract class and advisory
        cout << "\n--- FARMING ADVICE ---\n";

        Advisory *advice;

        advice = &c1;
        advice->giveAdvice();

        advice = &c2;
        advice->giveAdvice();

        // Static member
        Crop::showCount();

        // File handling: writing data
        ofstream fout("cropdata.txt");

        if (!fout)
            throw runtime_error("File cannot be opened!");

        c1.saveToFile(fout);
        c2.saveToFile(fout);

        fout.close();

        cout << "\nCrop data saved successfully!\n";

        // File handling: reading data
        ifstream fin("cropdata.txt");

        if (!fin)
            throw runtime_error("File cannot be read!");

        string line;

        cout << "\n--- SAVED CROP DATA ---\n";

        while (getline(fin, line))
        {
            cout << line << endl;
        }

        fin.close();
    }

    catch (const exception &e)
    {
        cout << "\nError: " << e.what() << endl;
    }

    return 0;
}

