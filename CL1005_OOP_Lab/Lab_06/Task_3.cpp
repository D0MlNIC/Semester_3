#include <iostream>
#include <string>

using namespace std;

class Person {
    protected:
        string name;
        int age;
    
    public:
        Person(string name, int age) : name(name), age(age) {}

        void displayDetails() {
            cout << "Name: " << this->name << endl;
            cout << "Age: " << this->age << endl;
        }
};

class Teacher : virtual public Person {
    protected:
        string subject;

    public:
    Teacher(string name, int age, string subject) : Person(name, age), subject(subject) {}

    void displayDetails() {
        Person::displayDetails();
        cout << "Subject: " << this->subject << endl;
    }
};

class Researcher : virtual public Person {
    protected:
        string researchArea;

    public:
        Researcher(string name, int age, string researchArea) : Person(name, age), researchArea(researchArea) {}

    void displayDetails() {
        Person::displayDetails();
        cout << "ResearchArea: " << this->researchArea << endl;
    }   
};

class Professor : public Teacher, public Researcher {
    protected:
        int publications;

    public:
        Professor(string name, int age, string subject, string researchArea, int publications) : 
            Person(name, age), Teacher(name, age, subject), Researcher(name, age, researchArea), publications(publications) {}

        void displayDetails() {
            Teacher::displayDetails();
            cout << "ResearchArea: " << this->researchArea << endl;
            cout << "Publications: " << this->publications << endl;
        }
};

int main() {
    Professor p1("Usama Antuley", 41, "Calculus", "Artificial Intelligence", 25);
    p1.displayDetails();
    return 0;
}