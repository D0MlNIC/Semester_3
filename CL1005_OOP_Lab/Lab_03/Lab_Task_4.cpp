#include <iostream>
#include <string>

using namespace std;

class Laptop
{
private:
    string brand;
    string model;
    string processor;
    string name;
    int ram;
    int storage;
    bool ison;

public:
    void setName(string n)
    {
        name = n;
    }

    void setBrand(string b)
    {
        brand = b;
    }

    void setModel(string m)
    {
        model = m;
    }

    void setProcessor(string p)
    {
        processor = p;
    }

    void setRam(int r)
    {
        ram = r;
    }

    void setStorage(int s)
    {
        storage = s;
    }

    void turnon()
    {
        ison = 1;
        cout << "Laptop Turned on" << endl;
    }

    void turnoff()
    {
        ison = 0;
        cout << "Laptop Turned off" << endl;
    }

    void runProgram()
    {
        if (ison)
        {
            cout << "Started Program Successfully" << endl;
        }
        else
        {
            cout << "Laptop is powered off. Cannot start the Program" << endl;
        }
    }

    void printSpecs()
    {
        cout << endl << name << " your Laptop Specs are:" << endl;
        cout << "Brand = " << brand << endl;
        cout << "Model = " << model << endl;
        cout << "Processor = " << processor << endl;
        cout << "RAM = " << ram << "GB" << endl;
        cout << "Storage = " << storage << "GB" << endl;
    }
};

void enterSpecs(Laptop &l, string name)
{
    string s;
    int i;
    l.setName(name);
    cout << endl << name << ", Enter your Specs" << endl;
    cout << "Brand: ";
    cin.clear();
    fflush(stdin);
    cin >> s;
    l.setBrand(s);
    cout << "Model: ";
    cin >> s;
    l.setModel(s);
    cout << "Processor: ";
    cin >> s;
    l.setProcessor(s);
    cout << "RAM (in GB): ";
    cin >> i;
    l.setRam(i);
    cout << "Storage (in GB): ";
    cin >> i;
    l.setStorage(i);
    cin.clear();
    fflush(stdin);
}

int main()
{
    Laptop Bilal;
    Laptop Ayesha;
    string temp;

    enterSpecs(Bilal, "Bilal");
    cin.clear();
    fflush(stdin);
    enterSpecs(Ayesha, "Ayesha");

    Bilal.printSpecs();
    Ayesha.printSpecs();

    return 0;
}