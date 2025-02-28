#include <iostream>
#include <string>

using namespace std;

class Movie {
    private:
        string title;
        string director;
        int duration;

    public:
        Movie() {}
        Movie(string title, string director, int duration) : title(title), director(director), duration(duration) {}

        string getTitle() {
            return this->title;
        }

        void setTitle(string title) {
            this->title = title;
        }

        string getDirector() {
            return this->director;
        }

        void setDirector(string director) {
            this->director = director;
        }

        int getDuration() {
            return this->duration;
        }

        void setDuration(int duration) {
            this->duration = duration;
        }
};

class Cinema {
    private:
        string name;
        int numMovies;
        int count;
        Movie *movies;

    public:
        Cinema(string name, int numMovies) : name(name), numMovies(numMovies) {
            count = 0;
            movies = new Movie[numMovies];
        }

        void addMovie(string t, string di, int du) {
            if (count < numMovies) {
                movies[count].setTitle(t);
                movies[count].setDirector(di);
                movies[count].setDuration(du);
                cout << "Successfully Added Movie " << t << endl;
                count++;
            } else {
                cout << "Cannot Add More Movies || Space Full" << endl;
            }
        }

        void printMoviesInCinema() {
            cout << endl << "Following Movies are being played in " << this->name << " Cinema" << endl;
            for (int i=0; i<this->count; i++) {
                cout << "Movie " << i+1 << endl;
                cout << "Movie Title: " << movies[i].getTitle() << endl;
                cout << "Movie Director: " << movies[i].getDirector() << endl;
                cout << "Movie Duration: " << movies[i].getDuration() << "mins" << endl;
                cout << endl;
            }
        }

        ~Cinema() {
            delete[] movies;
        }
};

int main() {
    Cinema neuplex("Neuplex", 3);
    neuplex.addMovie("The Fast And The Furious", "Rob Cohen", 106);
    neuplex.addMovie("Die Hard", "John McTiernan", 132);
    neuplex.addMovie("Harry Potter and the Philosopher's Stone", "Chrus Colombus", 152);
    neuplex.printMoviesInCinema();
}