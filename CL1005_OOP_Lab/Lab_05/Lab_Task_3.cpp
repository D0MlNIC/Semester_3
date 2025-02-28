#include <iostream>
#include <string>

using namespace std;

class Professor {
    private:
        string name;
        int id;
    
    public:
        Professor(string name, int id) : name(name), id(id) {}

        int getId() {
            return id;
        }

        string getName() {
            return name;
        }

        void setId(int id) {
            this->id = id;
        }
        
        void setName(string name) {
            this->name = name;
        } 
};

class University {
    private:
        string name;
        int numProfessors;
        int count;
        Professor **professors;

    public:
        University(string name, int nump) : name(name), numProfessors(nump) {
            professors = new Professor*[nump]; 
            count = 0;
            for (int i=0; i<nump; i++) {
                professors[i] = NULL;
            }
        }

        void addProfessor(Professor *p) {
            if (count < numProfessors) {
                professors[count] = p;
                count++;
                cout << "Successfully Added Professor " << p->getName() << " to " << this->name << " University" << endl;
            } else {
                cout << "Space Full || Cannot Accomodate more Professors" << endl;
            }
        }

        string getName() {
            return this->name;
        }

        void printFacultyMembers() {
            cout << "Following Faculty Members are working in " << getName() << " University" << endl;
            for (int i=0; i<this->count; i++) {
                cout << "Professor " << professors[i]->getName() << " || ID: " << professors[i]->getId() << endl;
            }
            cout << endl;
        }

        ~University() {
            delete[] professors;
        }
};

int main() {
    Professor p1("Talha", 1);
    Professor p2("Shahid", 2);
    Professor p3("Basit", 3);
    University fast("FAST", 3);
    fast.addProfessor(&p1);
    fast.addProfessor(&p2);
    fast.addProfessor(&p3);
    fast.printFacultyMembers();
    return 0;
}