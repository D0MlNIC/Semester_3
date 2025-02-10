#include <iostream>
#include <string>

using namespace std;

class TeaMug {
    private:
        string brand;
        string color;
        double currentFillLevel;
        int capacity;

    public:
        TeaMug(string b, string c) {
            brand = b;
            color = c;
            currentFillLevel = 100; // constant
            capacity = 100;
        }

        void sipTea(int t) {
            // 1t = 0.1 tealevel;
            currentFillLevel -= t*0.1;
            if (currentFillLevel < 0) currentFillLevel = 0;
            if (currentFillLevel == 0) {
                return;
            } else if (currentFillLevel < 5) {
                cout << "Tea Mug is nearly empty. It's time to make a fresh cup of tea." << endl;
            } else {
                cout << color << " Tea Level is " << currentFillLevel << endl;
            }
        }

        void refill() {
            currentFillLevel = capacity;
            cout << color << " Fresh cup of tea served hot ready!" << endl;
        }
};

int main() {
    TeaMug black("Tapal", "Black");
    TeaMug brown("vital", "Brown");
    for (int i=0; i<2; i++) {
        black.sipTea(250);
        brown.sipTea(250);
    }
    for (int i=0; i<5; i++) {
        black.sipTea(120);
        brown.sipTea(120);
    }
    black.refill();
    brown.refill();
    return 0;
}