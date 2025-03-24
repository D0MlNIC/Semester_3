#include <iostream>
#include <string>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate; 
public:
    Currency(double amt, string code, string symbol, double rate)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    double convertToBase() const {
        return amount * exchangeRate;
    }

    double convertTo(Currency targetCurrency) {
        return convertToBase() / targetCurrency.exchangeRate;
    }

    void displayCurrency() const {
        cout << currencyCode << " " << currencySymbol << " " << amount << endl;
    }
};

class USD : public Currency {
public:
    USD(double a) : Currency(a, "USD", "$", 1) {}
};

class Euro : public Currency {
public:
    Euro(double a) : Currency(a, "EUR", "€", 0.88) {} 
};

class Rupee : public Currency {
public:
    Rupee(double a) : Currency(a, "PKR", "Rs", 0.0036) {} 
};

int main() {
    USD usd(100);
    Euro eur(100);
    Rupee pkr(10000);

    cout << "Initial Currency Details:\n";
    usd.displayCurrency();
    eur.displayCurrency();
    pkr.displayCurrency();

    cout << "\nConversions:\n";
    cout << "100 USD to EUR: " << usd.convertTo(eur) << " EUR\n";
    cout << "100 EUR to USD: " << eur.convertTo(usd) << " USD\n";
    cout << "10000 PKR to USD: " << pkr.convertTo(usd) << " USD\n";

    return 0;
}
