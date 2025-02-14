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

    if (dataLines[i] = 50)
    {
        cout << "Not Permitted Data Detected";
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
           try
           {
            readData();
            ofstream opFile("myAnswers.txt");

            int addedData1 = (dataLines[0] + dataLines[1]);
            int p1 = (addedData1 * 2);
            opFile << "Calculated Rectangle Perimeter for line 1: " << p1 << endl;

            readData();
            int addedData2 = (dataLines[3] + dataLines[4]);
            int p2 = (addedData2 * 2);
            opFile << "Calculated Rectangle Perimeter for line 2: " << p2 << endl;

            readData();
            int addedData3 = (dataLines[6] + dataLines[7]);
            int p3 = (addedData3 * 2);
            opFile << "Calculated Rectangle Perimeter for line 3: " << p3 << endl;

            readData();
            int addedData4 = (dataLines[9] + dataLines[10]);
            int p4 = (addedData4 * 2);
            opFile << "Calculated Rectangle Perimeter for line 4: " << p4 << endl;

    //LINE 5 SHOULD THROW ERROR STRING
            readData();
            int addedData5 = (dataLines[12] + dataLines[13]);
            int p5 = (addedData5 * 2);
            opFile << "Calculated Rectangle Perimeter for line 5: " << p5 << "\n" << endl;
           }

           catch(string b)
           {
                cout << b;
           }
           
        }

        virtual int calcArea() const
        {
           try
           {
            readData();
            ofstream opFile("myAnswers.txt");
            // Area calculations for rectangle
            opFile << "Calculated Rectangle Area for line 1: " << (dataLines[0] * dataLines[1]) << endl;

            opFile << "Calculated Rectangle Area for line 2: " << (dataLines[3] * dataLines[4]) << endl;

            opFile << "Calculated Rectangle Area for line 3: " << (dataLines[6] * dataLines[7]) << endl;

            opFile << "Calculated Rectangle Area for line 4: " << (dataLines[9] * dataLines[10]) << endl;
    //LINE 5 SHOULD THROW ERROR STRING
            opFile << "Calculated Rectangle Area for line 5: " << (dataLines[12] * dataLines[13]) << "\n" << endl;
           }

           catch(string b)
           {
            cout << b;
           }
        }

        friend ostream &operator << (ostream &out, const Rectangle &r);
};

class Circle : public Shape
{
    private:
        int radius;

    public:
        int i = 0;
        virtual int calcPerimeter() const
        {
           try
           {
            readData();
            ofstream opFile("myAnswers.txt");
            // Perimeter calculations for circle
            int radius1 = dataLines[2];
            double circP1 = (radius1 * 2 * pi);
            opFile << "Calculated Circle Perimeter for line 1: " << circP1 << endl;

            int radius2 = dataLines[5];
            double circP2 = (radius2 * 2 * pi);
            opFile << "Calculated Circle Perimeter for line 2: " << circP2 << endl;

            int radius3 = dataLines[8];
            double circP3 = (radius3 * 2 * pi);
            opFile << "Calculated Circle Perimeter for line 3: " << circP3 << endl;

            int radius4 = dataLines[11];
            double circP4 = (radius4 * 2 * pi);
            opFile << "Calculated Circle Perimeter for line 4: " << circP4 << endl;

            int radius5 = dataLines[14];
            double circP5 = (radius5 * 2 * pi);
            opFile << "Calculated Circle Perimeter for line 5: " << circP5 << "\n" << endl;
           }

           catch(string b)
           {
            cout << b;
           }
           
        }

        virtual int calcArea() const
        {
            try
            {
                readData();
                ofstream opFile("myAnswers.txt");
                // Area calculations for circle
                int radius1 = dataLines[2];
                opFile << "Calculated Circle Area for line 1: " << (radius1 * radius1 * pi) << endl;

                int radius2 = dataLines[5];
                opFile << "Calculated Circle Area for line 2: " << (radius2 * radius2 * pi) << endl;

                int radius3 = dataLines[8];
                opFile << "Calculated Circle Area for line 3: " << (radius3 * radius3 * pi) << endl;

                int radius4 = dataLines[11];
                opFile << "Calculated Circle Area for line 4: " << (radius4 * radius4 * pi) << endl;

                int radius5 = dataLines[14];
                opFile << "Calculated Circle Area for line 5: " << (radius5 * radius5 * pi);
            }

            catch(string b)
            {
                cout << b;
            }

        }

        friend ostream &operator << (ostream &out, Circle c);
};

ostream &operator << (ostream &out, const Rectangle &r)
{
    out << r.calcArea() << " " << r.calcPerimeter();
    return out;
}

ostream &operator << (ostream &out, Circle &c)
{
    ofstream opFile("myAnswers.txt");
    opFile << c.calcArea();
    opFile << c.calcPerimeter();
    return out;
}