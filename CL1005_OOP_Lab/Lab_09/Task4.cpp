#include <bits/stdc++.h>

using namespace std;

class PaymentMethod
{
public:
    virtual void processPayment(double amount) = 0;
};

class CreditCard : public PaymentMethod
{
    string cardNumber;

public:
    CreditCard(string num) : cardNumber(num) {}
    void processPayment(double amount)
    {
        int cardNum = stoi(cardNumber);
        if(cardNum >= 0000 && cardNum <= 9999)
            cout << "Validation Successful. Now Processing Payment\nAmount = " << amount<< "$\n";
        else
            cout << "Validation Unsuccessful. Invalid Card Number\n";
    }
};

class DigitalWallet : public PaymentMethod
{
    double balance;

public:
    DigitalWallet(double balance) : balance(balance){}
    void processPayment(double amount)
    {
        if(amount >= 5000 && amount <= 199999 && amount < balance)
            cout << "Validation Successful. Now Processing Payment\nAmount = " << amount<< "$\n";
        else
            cout << "Validation Unsuccessful. Insufficient Money\n";
    }
};

int main()
{
    CreditCard CC("987");
    DigitalWallet DW(10000);
    cout << endl;
    CC.processPayment(1000);
    DW.processPayment(1001);
    cout << endl;
    return 0;
}