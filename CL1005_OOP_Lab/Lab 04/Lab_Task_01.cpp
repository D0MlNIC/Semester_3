#include <iostream>
#include <string>

using namespace std;

class Book {
    private:
        string title;
        float price;
        int stock;

    public:
        Book() {
            title = "Unknown";
            price = 0.0;
            stock = 30;
        }

        void updateTitle(string s) {
            title = s;
        }

        void updatePrice(float p) {
            price = p;
        }

        void updatestock(int s) {
            stock = s;
        }

        void issueWarning() {
            if (stock < 5) {
                cout << "Low Stock Alert!!!" << endl;
                cout << title << " book stock is less than 5" << endl;
            }
        }

        void buy(int copies) {
            if (copies < 1) {
                cout << "Wrong Input" << endl;
                return;
            }
            if (stock - copies < 0) {
                cout << "You cannot buy " << copies << " " << title << " books" << endl;
                return;
            }  
            cout << copies << " " << title << (copies == 1 ? " book" : " books") << " has been purchased for ";
            cout << "$" << price * copies << endl;
            stock -= copies;
            issueWarning();
        }
};

int main() {
    Book b1;
    b1.updatePrice(5);

    for (int i=1; i<=10; i++) {
        b1.buy(i);
    }
}