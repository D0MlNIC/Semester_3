#include <iostream>
#include <string>

using namespace std;

class Fraction {
    int numerator;
    int denominator;

    public:
        Fraction(int n, int d) : numerator(n), denominator(d) {}

        Fraction operator + (Fraction f) {
            int num = (numerator * f.denominator) + (f.numerator * denominator);
            int den = (denominator * f.denominator);
            return Fraction(num, den);
        }

        Fraction operator - (Fraction f) {
            int num = (numerator * f.denominator) - (f.numerator * denominator);
            int den = (denominator * f.denominator);
            return Fraction(num, den);
        }

        Fraction operator * (Fraction f) {
            int num = (numerator * f.numerator);
            int den = (denominator * f.denominator);
            return Fraction(num, den);
        }

        Fraction operator / (Fraction f) {
            int num = (numerator * f.denominator);
            int den = (denominator * f.numerator);
            return Fraction(num, den);
        }

        friend ostream &operator << (ostream &os, Fraction f) {
            os << f.numerator << "/" << f.denominator;
            return os;
        }
};

int main() {
    Fraction fracA (5, 2);
    Fraction fracB (3, 4);

    Fraction fracAdd = fracA + fracB;
    Fraction fracSub = fracA - fracB;
    Fraction fracMul = fracA * fracB;
    Fraction fracDiv = fracA / fracB;

    cout << "Frac A: " << fracA << endl; 
    cout << "Frac B: " << fracB << endl; 
    cout << "Frac Add: " << fracAdd << endl; 
    cout << "Frac Sub: " << fracSub << endl; 
    cout << "Frac Mul: " << fracMul << endl; 
    cout << "Frac Div: " << fracDiv << endl; 

    return 0;
}