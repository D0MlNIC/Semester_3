#include <iostream>
#include <string>

using namespace std;

class Vehicle {
    protected:
        string brand;
        int speed;

    public:
        Vehicle(string brand = "", int speed = 0) : brand(brand), speed(speed) {}

        void displayDetails() {
            cout << "Brand: " << this->brand << endl;
            cout << "Speed: " << this->speed << endl;
        }
};

class Car : public Vehicle {
    protected:
        int seats;

    public:
        Car(string brand = "", int speed = 0, int seats = 0) : Vehicle(brand, speed), seats(seats) {}

        void displayDetails() {
            Vehicle::displayDetails();
            cout << "Seats: " << this->seats << endl;
        }
};

class ElectricCar : public Car {
    protected:
        int batteryLife;

    public:
        ElectricCar(string brand = "", int speed = 0, int seats = 0, int bl = 0) : Car(brand, speed, seats), batteryLife(bl) {}

        void displayDetails() {
            Car::displayDetails();
            cout << "Battery Life: " << this->batteryLife << endl;
        }
};

int main() {
    ElectricCar ec("Tesla", 220, 5, 6);
    ec.displayDetails();
}