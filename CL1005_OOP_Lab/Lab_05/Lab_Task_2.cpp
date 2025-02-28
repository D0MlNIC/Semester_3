#include <iostream>
#include <string>

using namespace std;

class Patient {
    private:
        int id;
        string name;
        int numTests;
        int *test;

    public:
        Patient(Patient &p) {
            id = p.id;
            name = p.name;
            cout << "Enter number of test to upload: ";
            cin >> numTests;
            test = new int[numTests];
            enterTests();
        }

        Patient(int i, string n, int t) : id(i), name(n) {
            numTests = t;
            test = new int[t];
            cout << endl;
            enterTests();
        }

        void enterTests() {
            for (int i=0; i<numTests; i++) {
                cout << "Enter Test " << i+1 << ": ";
                cin >> test[i];
            }
        }

        void displayTests() {
            cout << endl << "Patient Tests" << endl;
            for (int i=0; i<numTests; i++) {
                cout << i+1 << ": " << test[i] << endl;
            }
        }

        ~Patient() {
            delete[] test;
        }
        
};

int main() {
    Patient p1(1234, "Abdullah", 3);
    p1.displayTests();
    Patient p2(p1);
    p2.displayTests();
    return 0;
}