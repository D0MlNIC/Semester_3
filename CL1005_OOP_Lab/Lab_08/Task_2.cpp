#include <iostream>
#include <string>

using namespace std;

class Librarian;

class Book {
    private:
        string title;
        string author;
        float price;

    public:
        Book(string t, string a, float p) : title(t), author(a), price(p) {}
        friend class Librarian;
};

class Librarian {
    private:
        string name;

    public:
        Librarian(string n) : name(n) {}
        void displayBookDetails(Book b) {
            cout << "Book Title: " << b.title << endl;
            cout << "Book Author: " << b.author << endl;
            cout << "Book Price: " << b.price << endl;
            cout << endl;
        }

        void applyDiscount(Book &b) {
            b.price = b.price * 0.9;
        }
};

int main() {
    Book b("Harry Potter", "JK Rowling", 100);
    Librarian l("Muhib");
    l.displayBookDetails(b);
    l.applyDiscount(b);
    l.displayBookDetails(b);
    return 0;
}