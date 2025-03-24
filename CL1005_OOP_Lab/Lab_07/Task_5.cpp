#include <iostream>
#include <string>

using namespace std;

class Media {
    protected:
        string title;
        string publicationDate;
        int uniqueID;
        string publisher;
    public:
        Media( string t, string pD, int ID, string p)
        : title(t), publicationDate(pD), uniqueID(ID), publisher(p) {};

        virtual void displayInfo() const {
            cout << "Title: " << title << endl;
            cout << "Publication Date: " << publicationDate << endl;
            cout << "Unique ID: " << uniqueID << endl;
            cout << "Publisher: " << publisher << endl;
        }

        void checkOut() { 
            cout << title << " checked out." << endl; 
        }

        void returnItem() { 
            cout << title << " returned." << endl; 
        }  

        bool search(const string &query) const {
            return title == query;
        }
        bool search(int id) const {
            return uniqueID == id;
        }
};

class Book : public Media {
    private:
        string author;
        int ISBN;
        int numberOfPages;
    public:
    Book(string t, string pD, int ID, string p, string a, int i , int nP) 
    : Media(t, pD, ID, p), author(a), ISBN (i), numberOfPages(nP) {};

    void displayInfo() const override { 
        Media :: displayInfo();
        cout << "Author : " << author << endl;
        cout << "ISBN : " << ISBN << endl;
        cout << "Number of Pages : " << numberOfPages << endl;
    }
};

class DVD : public Media { 
    private:
        string director;
        float duration;
        float rating;
    public:
        DVD (string t, string pD, int ID, string p, string d, float dU, float r) 
        : Media(t, pD, ID, p), director(d), duration(dU), rating (r) {};

        void displayInfo() const override {
            Media :: displayInfo();
            cout << "Director : " << director << endl;
            cout << "Duration : " << duration << endl;
            cout << "Rating : " << rating << endl;
        }

};

class CD : public Media {
    private:
    string artist;
    int numberOFtracks;
    string genre;
    public:
    CD(string t, string pD, int ID, string p, string a, int nT, string g) 
    : Media(t, pD, ID, p), artist(a), numberOFtracks(nT), genre(g) {};
    
    void displayInfo() const override {
        Media :: displayInfo();
        cout << "Artist : " << artist << endl;
        cout << "Number of Tracks : " << numberOFtracks << endl;
        cout << "Genre : " << genre << endl;
    }
};

int main() {
    Book b1("The Great Gatsby", "1925", 1, "Scribner", "F. Scott Fitzgerald", 123456, 180);
    DVD d1("Inception", "2010", 2, "Warner Bros.", "Christopher Nolan", 148, 8.8);
    CD c1("Thriller", "1982", 3, "Epic Records", "Michael Jackson", 9, "Pop");

    b1.displayInfo();
    cout << endl;
    d1.displayInfo();
    cout << endl;
    c1.displayInfo();
    cout << endl;

    string query;
    cout << "Enter search term: ";
    cin >> query;

    if (b1.search(query)) cout << "Match found in Book." << endl;
    if (d1.search(query)) cout << "Match found in DVD." << endl;
    if (c1.search(query)) cout << "Match found in CD." << endl;

    return 0;
}