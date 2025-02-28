#include <iostream>
#include <string>

using namespace std;

class TourGuide {
    private:
        string name;
        string specialization;
        int yearsOfExperience;
    
    public:
        TourGuide(string name, string specialization, int yearsOfExperience) : name(name), yearsOfExperience(yearsOfExperience), specialization(specialization) {}

        int getYearsOfExperience() {
            return yearsOfExperience;
        }

        string getName() {
            return name;
        }

        string getSpecialization() {
            return specialization;
        }

        void setSpecialization(string spec) {
            this->specialization = spec ;
        }

        void setYearsOfExperience(int yearsOfExperience) {
            this->yearsOfExperience = yearsOfExperience;
        }
        
        void setName(string name) {
            this->name = name;
        } 
};

class TravelAgency {
    private:
        string name;
        int numTourGuides;
        int count;
        TourGuide **tourGuides;

    public:
        TravelAgency(string name, int numt) : name(name), numTourGuides(numt) {
            tourGuides = new TourGuide*[numt]; 
            count = 0;
            for (int i=0; i<numt; i++) {
                tourGuides[i] = NULL;
            }
        }

        void addTourGuide(TourGuide *p) {
            if (count < numTourGuides) {
                tourGuides[count] = p;
                count++;
                cout << "Successfully Added TourGuide " << p->getName() << " to " << this->name << " TravelAgency" << endl;
            } else {
                cout << "Space Full || Cannot Accomodate more TourGuides" << endl;
            }
        }

        string getName() {
            return this->name;
        }

        void printTravelAgencyMembers() {
            cout << endl << "Following Tour Guides are working in " << getName() << " TravelAgency" << endl;
            for (int i=0; i<this->count; i++) {
                cout << "TourGuide " << i+1 << endl;
                cout << "TourGuide Name: " << tourGuides[i]->getName() << endl;
                cout << "TourGuide YOE: " << tourGuides[i]->getYearsOfExperience() << endl;
                cout << "TourGuide Specialization: " << tourGuides[i]->getSpecialization() << endl;
                cout << endl;
            }
        }

        ~TravelAgency() {
            delete[] tourGuides;
        }
};

int main() {
    TourGuide t1("Talha", "Teaching Expert", 1);
    TourGuide t2("Shahid", "Teaching Expert", 2);
    TourGuide t3("Basit", "Management Expert", 3);
    TravelAgency fast("FAST", 3);
    fast.addTourGuide(&t1);
    fast.addTourGuide(&t2);
    fast.addTourGuide(&t3);
    fast.printTravelAgencyMembers();
    return 0;
}