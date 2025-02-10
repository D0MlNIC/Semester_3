#include <iostream>
#include <string>

using namespace std;

class MarkerPen {
    private:
        string brand;
        string color;
        double inkLevel;
        bool isrefillable;

    public:
        MarkerPen(string b, string c, bool ir) {
            brand = b;
            color = c;
            inkLevel = 95; // constant
            isrefillable = ir;
        }

        void write(int t) {
            // 1t = 0.1 intlevel;
            inkLevel -= t*0.1;
            if (inkLevel < 15) inkLevel = 15;
            if (inkLevel == 15) {
                return;
            } else if (inkLevel < 30) {
                cout << color << " Pen Ink Level is less than 30. Better to Refill it if it is refillable." << endl;
            } else {
                cout << color << " Pen Ink Level is " << inkLevel << endl;
            }
        }

        void refill() {
            if (inkLevel < 30 && isrefillable) {
                inkLevel = 95;
                cout << color << " Pen Ink Refilled" << endl;
            } else {
                cout << color << " Pen Ink can not be Refilled" << endl;
            }
        }
};

int main() {
    MarkerPen blue("Dollar", "Blue", 1);
    MarkerPen red("Dollar", "Red", 0);
    for (int i=0; i<9; i++) {
        blue.write(250);
        red.write(250);
    }
    blue.refill();
    red.refill();
    return 0;
}