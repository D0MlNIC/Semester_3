#include <bits/stdc++.h>
#include "Book.h"

using namespace std;

int main()
{
    Book B("Harry Potter", "JK Rowling", "1234567890");
    cout << endl;
    cout << "Book Title: " << B.getTitle() << endl;
    cout << "Author: " << B.getAuthor() << endl;
    cout << "ISBN: " << B.getISBN() << endl;
    cout << endl;

    return 0;
}
//g++ 3_main.cpp Book.cpp -o 3.exe