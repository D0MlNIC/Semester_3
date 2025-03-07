#include <iostream>
#include <string>

using namespace std;

class Employee {
    protected:
        string name;
        float salary;

    public:
        Employee() : name(""), salary(0) {}

        Employee(string name, float salary) : name(name), salary(salary) {}

        void displayDetails() {
            cout << "Name: " << name << endl;
            cout << "Salary: " << salary << endl;
        }
};

class Manager : public Employee {
    protected:
        float bonus;

    public:
        Manager() : Employee(), bonus(0) {}

        Manager(string name, float salary, float bonus) : Employee(name, salary), bonus(bonus) {}

        void displayDetails() {
            Employee::displayDetails();
            cout << "Bonus: " << bonus << endl;
        }
};

int main() {
    Manager manager("Muhib", 1000, 500);
    manager.displayDetails();
    return 0;
}