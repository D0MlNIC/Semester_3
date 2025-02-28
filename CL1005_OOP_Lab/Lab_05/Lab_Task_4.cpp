#include <iostream>
#include <string>

using namespace std;

class Battery {
    private:
        int mah;
        int lifetime;

    public:
        int getMah() {
            return mah;
        }

        int getLifetime() {
            return lifetime;
        }

        void setMah(int m) {
            mah = m;
        }

        void setLifetime(int l) {
            lifetime = l;
        }
};

class Mobile {
    private:
        Battery battery;
        string model;
        string company;
        int ram;

    public:
        Mobile(string c, string m, int r, int mah, int lifetime) : model(m), company(c), ram(r) {
            battery.setLifetime(lifetime);
            battery.setMah(mah);
        }

        void getMobileSpecs() {
            cout << company << model <<  " Mobile Specs" << endl;
            cout << "RAM: " << ram << "GB" << endl;
            cout << "Battery Power: " << battery.getMah() << "MAH" << endl;
            cout << "Battery Lifetime: " << battery.getLifetime() << "Hrs" << endl;
            cout << endl;
        }
};

int main() {
    Mobile m1("Samsung", "A30s", 4, 4000, 18);
    Mobile m2("Samsung", "S20", 8, 4000, 22);
    m1.getMobileSpecs();
    m2.getMobileSpecs();
}