#include <iostream>
#include <string>

using namespace std;

class Vehicle {
    protected:
        string model;
        double rate;
    
    public:
        Vehicle(string m, double r) : model(m), rate(r) {}
        virtual double getDailyRate() = 0;
        virtual void displayDetails() = 0;
};

class Car : public Vehicle {
    private:

    public:
        Car(string m, double r) : Vehicle(m, r) {}

        double getDailyRate() {
            return rate;
        }

        void displayDetails() {
            cout << "Model: " << model << endl;
            cout << "Rate: " << getDailyRate() << endl << endl;
        }
};

class Bike : public Vehicle {
    public:
        Bike(string m, double r) : Vehicle(m, r) {}

        double getDailyRate() {
            return rate;
        }

        void displayDetails() {
            cout << "Model: " << model << endl;
            cout << "Rate: " << getDailyRate() << endl << endl;
        }
};

int main() {
    Car c1("Passo", 1000);
    Car c2("Vitz", 850);
    Bike b1("125", 300);
    Bike b2("250", 125);
    Vehicle *vehicles[] = {&c1, &c2, &b1, &b2};
    vehicles[0]->displayDetails();
    vehicles[1]->displayDetails();
    vehicles[2]->displayDetails();
    vehicles[3]->displayDetails();
    return 0;
}