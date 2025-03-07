#include <iostream>
#include <string>

using namespace std;

class Account {
    protected:
        int accountNumber;
        float balance;
    
    public:
        Account(int accountNumber, float balance) : accountNumber(accountNumber), balance(balance) {}

        void displayDetails() {
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: " << balance << endl;
        }
};

class SavingsAccount : public Account {
    protected:
        float interestRate;

    public:
        SavingsAccount(int accountNumber, float balance, float interestRate) :
            Account(accountNumber, balance), interestRate(interestRate) {}

        void displayDetails() {
            Account::displayDetails();
            cout << "Interest Rate: " << interestRate << endl;
        }
};

class CheckingAccount : public Account {
    protected:
        float overdraftLimit;

    public:
        CheckingAccount(int accountNumber, float balance, float overdraftLimit) :
            Account(accountNumber, balance), overdraftLimit(overdraftLimit) {}

        void displayDetails() {
            Account::displayDetails();
            cout << "Overdraft Limit: " << overdraftLimit << endl;
        }
};

int main() {
    SavingsAccount s1(1, 1000, 10);
    CheckingAccount c1(2, 20000, 50000);

    s1.displayDetails();
    cout << endl;
    c1.displayDetails();

    return 0;
}