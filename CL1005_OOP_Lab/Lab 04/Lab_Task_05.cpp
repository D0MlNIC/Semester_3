#include <iostream>
#include <string>

using namespace std;

class Book {
    private:
        string title;
        float price;
        float *sales = new float(0);
        int stock;
        static int bookID;
        int thisID;
        
    public:
        Book() {
            title = "Unknown";
            price = 0.0;
            stock = 30;
            thisID = ++bookID;
        }

        // Book(int bookID) : bookID(bookID){}

        Book(string s, float p, int st) : title(s), price(p), stock(st), thisID(++bookID){}

        Book(Book &book) {
            title = book.title;
            price = book.price;
            *sales = *(book.sales);
            stock = book.stock;
            thisID = ++bookID;
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

        int getID() {
            return thisID;
        }

        void issueWarning() {
            if (stock < 5) {
                cout << "Low Stock Alert!!!" << endl;
                cout << title << " is less than 5" << endl;
            }
        }

        float applyDiscount(int copies) {
            if (copies > 10) {
                return this->price * 0.9 * copies;
            } else if (copies > 5) {
                return this->price * 0.95 * copies;
            } else {
                return this->price * copies;
            }
        }

        bool stockValidation(int c) {
            if (stock - c < 0) {
                cout << "You cannot buy " << c << " " << title << " books" << endl;
                cout << "Current Stock Available is " << stock << endl;
                return 0;
            }
            return 1;
        }

        void buy(int copies) {
            if (copies < 1) {
                cout << "Wrong Input" << endl;
                return;
            }
            bool sv = stockValidation(copies);
            if (!sv) return;
            float sales = applyDiscount(copies);
            cout << copies << " " << title << (copies == 1 ? " book" : " books") << " has been purchased for ";
            cout << "$" << sales << endl;
            *(this->sales) += sales;
            stock -= copies;
            cout << "Stock Available = " << stock << endl;
            issueWarning();
        }

        ~Book() {
            delete sales;
            cout << "Successfully released all of the allocated memory." << endl << "Deleting Class" << endl;
        }
};
int Book::bookID = 0;

int main() {
    Book b1("Harry Potter", 10, 50);
    // b1.setBookID(1);
    b1.buy(10);
    Book b2(b1);
    b2.buy(15);
    b1.buy(5);
    cout << "b1 id = " << b1.getID() << endl << "b2 id = " << b2.getID() << endl;
    Book *books = new Book[5];
    for (int i=0; i<5; i++) {
        cout << "b" << i+3 << " id = " << books[i].getID() << endl;
    }
    cout << endl;
    delete[] books;
    return 0;
}