#include <bits/stdc++.h>
using namespace std;

template <class X>
class InsufficientFundException : public exception {
    protected:
        X deficit;
        string message;
    public:
        InsufficientFundException(X deficit) : deficit(deficit) {
            message = "Deficit: $" + to_string(deficit);
        }
        const char *what() const noexcept override
        {
            return message.c_str();
        }
};

template <class T>
class BankAccount
{
private:
    T balance;

public:
    BankAccount(T balance) : balance(balance) {}
    void withdraw(T amount)
    {
        if (amount > balance)
            throw InsufficientFundException<T>(amount - balance);
        balance -= amount;
    }
};

int main()
{
    BankAccount<double> acc(919.05);
    try
    {
        acc.withdraw(1005.49);
    }
    catch (InsufficientFundException<double> &e)
    {
        cout << "Insufficient Balance" << endl;
        cout << e.what() << endl;
    }
    return 0;
}