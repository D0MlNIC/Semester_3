#include <iostream>
#include <string>

using namespace std;

class Car {
    private:
        int regNumber;
        string ownerName;
        string modelName;

    public:
        Car(int r, string o, string m) : regNumber(r), ownerName(o), modelName(m){};

        Car(Car &car) {
            regNumber = car.regNumber;
            modelName = car.modelName;
            cout << endl << "Enter new owner name: ";
            cin >> this->ownerName;
        }

        void displayCarDetails() {
            cout << "Registration Number: " << regNumber << endl;
            cout << "Owner Name: " << ownerName << endl;
            cout << "Model Name: " << modelName << endl;
        }
};

int main() {
    Car car1(1234, "Muhib", "City");
    cout << "Previous Owner" << endl;
    car1.displayCarDetails();
    Car car2(car1);
    cout << "New Owner" << endl;
    car2.displayCarDetails();
    return 0;
}