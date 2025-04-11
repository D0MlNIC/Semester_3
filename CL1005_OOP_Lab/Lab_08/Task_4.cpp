#include <iostream>

using namespace std;

class Currency {
    int value;

    public:
        Currency(int v) : value(v) {}
        int getValue() {return value;}

        Currency operator - () {
            return Currency(-value);
        }

        Currency operator + (Currency c) {
            return Currency(value + c.getValue());
        }

        Currency operator - (Currency c) {
            return Currency(value - c.getValue());
        }

        Currency &operator += (int v) {
            value += v;
            return *this;
        }

        Currency &operator -= (int v) {
            value -= v;
            return *this;
        }

        friend ostream & operator << (ostream &o, Currency c) {
            o << c.value;   
            return o;     
        }
};

int main() {
    Currency LaptopPrice(1000);
    Currency LaptopPriceAfterDiscount = LaptopPrice - Currency(100);
    Currency DualLaptop = LaptopPrice + Currency(750);
    cout << "Laptop Price: " << LaptopPrice << endl;
    cout << "Laptop Price After Discount: " << LaptopPriceAfterDiscount << endl;
    cout << "Dual Laptop: " << DualLaptop << endl;
    return 0;
}