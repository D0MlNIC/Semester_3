#include <iostream>
#include <string>

using namespace std;

class Account {
protected:
    string accountNumber;
    string accountHolderName;
    double balance;
    string accountType;
    pair<string, double> transactionDetail[10] = { {"", 0.0} };
    int count = 0;

public:
    Account(string accNum, string accHolder, double bal, string accType) 
        : accountNumber(accNum), accountHolderName(accHolder), balance(bal), accountType(accType) {}

    void addTransactionDetails(string transType, double amount) {
        if(count == 10) {
            for (int i = 1; i < count; i++) {
                transactionDetail[i - 1].first = transactionDetail[i].first;
                transactionDetail[i - 1].second = transactionDetail[i].second;
            }
            count = 9;
        }
        transactionDetail[count].first = transType;
        transactionDetail[count].second = amount;
        count++;
    }

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << "\nNew Balance: " << balance << endl;
            addTransactionDetails("Deposit", amount);
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    virtual bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << "\nNew Balance: " << balance << endl;
            addTransactionDetails("Withdrawal", amount);
            return true;
        } else {
            cout << "Invalid withdrawal amount or insufficient funds!" << endl;
            return false;
        }
    }

    virtual double calculateInterest() = 0; // Pure virtual function

    virtual void printStatement() const {
        cout << "Account Type: " << accountType << "\nAccount Holder: " << accountHolderName 
             << "\nAccount Number: " << accountNumber << "\nBalance: " << balance << endl;
    }

    virtual ~Account() {}
};

// Savings Account
class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(string accNum, string accHolder, double bal, double rate, double minBal)
        : Account(accNum, accHolder, bal, "Savings"), interestRate(rate), minimumBalance(minBal) {}

    double calculateInterest() override {
        return balance * (interestRate / 100);
    }

    bool withdraw(double amount) override {
        if (balance - amount >= minimumBalance) {
            return Account::withdraw(amount);
        } else {
            cout << "Cannot withdraw! Minimum balance requirement not met." << endl;
            return false;
        }
    }

    void printStatement() const override {
        Account::printStatement();
        cout << "Interest Rate: " << interestRate << "%\nMinimum Balance: " << minimumBalance << endl;
        cout << "Transaction Details:" << endl;
        for(int i = 0; i < count; i++) {
            cout << transactionDetail[i].first << ": " << transactionDetail[i].second << endl;
        }
    }
};

// Checking Account
class CheckingAccount : public Account {
public:
    CheckingAccount(string accNum, string accHolder, double bal)
        : Account(accNum, accHolder, bal, "Checking") {}

    double calculateInterest() override {
        return 0.0;
    }

    void printStatement() const override {
        Account::printStatement();
        cout << "Checking accounts do not earn interest." << endl;
        for(int i = 0; i < count; i++) {
            cout << transactionDetail[i].first << ": " << transactionDetail[i].second << endl;
        }
    }
};

//FD account
class FixedDepositAccount : public Account {
private:
    double fixedInterestRate;
    string maturityDate;

    bool isMatured(string currentDate) const {
        return currentDate >= maturityDate;
    }

public:
    FixedDepositAccount(string accNum, string accHolder, double bal, double rate, string maturity)
        : Account(accNum, accHolder, bal, "Fixed Deposit"), fixedInterestRate(rate), maturityDate(maturity) {}

    double calculateInterest() override {
        return balance * (fixedInterestRate / 100);
    }

    bool withdraw(double amount) override {
        string currentDate;
        cout << "Enter today's date (YYYY-MM-DD): ";
        cin >> currentDate;

        if (isMatured(currentDate)) {
            return Account::withdraw(amount);
        } else {
            cout << "Cannot withdraw! Maturity date not reached yet. Maturity Date: " << maturityDate << endl;
            return false;
        }
    }

    void printStatement() const override {
        Account::printStatement();
        cout << "Fixed Interest Rate: " << fixedInterestRate << "%\nMaturity Date: " << maturityDate << endl;
        for(int i = 0; i < count; i++) {
            cout << transactionDetail[i].first << ": " << transactionDetail[i].second << endl;
        }
    }
};

int main() {
    SavingsAccount sa("SA123", "Alice", 5000, 3.5, 1000);
    CheckingAccount ca("CA456", "Bob", 2000);
    FixedDepositAccount fda("FD789", "Charlie", 10000, 5.0, "2025-12-01");

    cout << "\nSavings Account:" << endl;
    sa.deposit(1000);
    sa.withdraw(3000);
    sa.withdraw(6000); 
    sa.printStatement();

    cout << "\nChecking Account:" << endl;
    ca.deposit(500);
    ca.withdraw(2500); 
    ca.printStatement();

    cout << "\nFixed Deposit Account Statement:" << endl;
    fda.printStatement();
    fda.deposit(10000);
    fda.withdraw(5000); 

    return 0;
}
