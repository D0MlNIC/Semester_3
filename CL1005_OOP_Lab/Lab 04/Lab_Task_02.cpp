#include <iostream>
#include <string>

using namespace std;

class Book {
    private:
        string title;
        float price;
        float sales = 0;
        int stock;

    public:
        Book() {
            title = "Unknown";
            price = 0.0;
            stock = 30;
        }

        Book(string s, float p, int st) : title(s), price(p), stock(st){}

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
                cout << title << " is less than 5" << endl;
            }
        }

        float applyDiscount(int copies) {
            if (copies > 10) {
                return price * 0.9 * copies;
            } else if (copies > 5) {
                return price * 0.95 * copies;
            } else {
                return price * copies;
            }
        }

        bool stockValidation(int c) {
            if (stock - c < 0) {
                cout << "You cannot buy " << c << " " << title << " books" << endl;
                cout << "Current Stock Available is " << stock << " books" << endl;
                return 0;
            }
            return 1;
        }

        void buy(int copies) {
            float sale = 0;
            if (copies < 1) {
                cout << "Wrong Input" << endl;
                return;
            }
            bool sv = stockValidation(copies);
            if (!sv) return;
            sale = applyDiscount(copies);
            cout << copies << " " << title << (copies == 1 ? " book" : " books") << " has been purchased for ";
            cout << "$" << sale << endl;
            sales += sale;
            stock -= copies;
            issueWarning();
        }
};

int main() {
    Book b1("Harry Potter", 10, 50);

    for (int i=1; i<=10; i++) {
        b1.buy(i);
    }
}