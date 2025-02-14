#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int dataLines[15];

void readData()
{
    ifstream ipFile("inputData.txt");

    int i = 0;

    while(!ipFile.eof())
    {
        ipFile >> dataLines[i];
        i++;
    }

    ipFile.close();
}

class Shape
{
    protected:
        virtual int calcPerimeter() const = 0;
        virtual int calcArea() const = 0;

    public:
        Shape();
        double pi = 3.14159265;
};

class Rectangle : public Shape
{
    private:
        int length, width;
        int i = 0;

    public:
        virtual int calcPerimeter() const
        {
           return 0;
        }

        virtual int calcArea() const
        {
           return 0;
        }

        friend ostream &operator << (ostream &out, Rectangle r);
};

class Circle : public Shape
{
    private:
        int radius;

    public:
        int i = 0;
        virtual int calcPerimeter() const
        {
           return 0;
        }

        virtual int calcArea() const
        {
           return 0;
        }

        friend ostream &operator << (ostream &out, Circle c);
};

ostream &operator << (ostream &out, Rectangle r)
{
    ofstream opFile("answers.txt");
    opFile << r.calcArea();
    opFile << r.calcPerimeter();
    return out;
}

ostream &operator << (ostream &out, Circle c)
{
    ofstream opFile("answers.txt");
    opFile << c.calcArea();
    opFile << c.calcPerimeter();
    return out;
}