#include<iostream>
#include<string>

using namespace std;

class Person {
    protected:
        string name;
        string id;
        string address;
        string phoneNumber;
        string email;
    public:

        Person( string n, string i, string a, string pN, string e) 
        : name(n), id(i), address(a), phoneNumber(pN), email(e) {};
    
        virtual void displayInfo() const {
            cout << "Name : " << name << endl;
            cout << "ID : " << id << endl;
            cout << "Address : " << address << endl;
            cout << "Phone Number : " << phoneNumber << endl;
            cout << "Email : " << email << endl;
        }

        virtual void updateInfo() {
            cout << "Enter new name : ";
            cin >> name;
            cout << "Enter new ID : ";
            cin >> id;
            cout << "Enter new address : ";
            cin >> address;
            cout << "Enter new phone number : ";
            cin >> phoneNumber;
            cout << "Enter new email : ";
            cin >> email;
        }
};

class Student : public Person {
    private:
        string coursesEnrolled;
        double GPA;
        int enrollmentYear;
    public:
        Student( string n , string i, string a, string pN, string e, string cE, double g, int eY) 
        : Person(n, i, a, pN, e), coursesEnrolled(cE), GPA(g), enrollmentYear(eY) {}; 

        string getName () { return name; } 
        void displayInfo() const override { 
            Person :: displayInfo();
            cout << "Acadmic Records" << endl;
            cout << "Courses Enrolled : " << coursesEnrolled << endl;
            cout << "GPA : " << GPA << endl;
            cout << "Enrollment Year : " << enrollmentYear << endl;
        }
};

class Professor : public Person {
    private:
        string department;
        string courseTaught;
        double salary;
    public:
        Professor( string n , string i, string a, string pN,string d , string cT, double s)
        : Person(n, i, a, pN, d), department(d), courseTaught(cT ), salary(s) {};

        void displayInfo() const override {
            Person :: displayInfo();
            cout << "faculty-specific details" << endl;
            cout << "Department : " << department << endl;
            cout << "Course Taught : " << courseTaught << endl;
            cout << "Salary : " << salary << endl;
        }
};

class Staff : public Person {
    private:
        string department;
        string position;
        double salary;
    public:
        Staff ( string n , string i, string a, string pN, string d, string p, double s)
        : Person(n, i, a, pN, d), department(d), position(p), salary(s) {};

        void displayInfo() const override {
            Person :: displayInfo();
            cout << "Staff-specific details" << endl;
            cout << "Department : " << department << endl;
            cout << "Position : " << position << endl;
            cout << "Salary : " << salary << endl;
        }
};

class Course {
    protected:
        string courseID;
        string courseName;
        int credit;
        string instructor;
        
    public:
        Course(string cID, string cN, int cr, string i)
        : courseID(cID), courseName(cN), credit(cr), instructor(i) {};

        void registerStudent(Student &s) {
            cout << s.getName() << " has been registered for " << courseName << endl;
        }

        void calculateGrade(Student &s) {
            cout << s.getName() << " has been graded for " << courseName << endl;
        }
};

int main() {
    Student student1("John Doe", "S123", "123 Street", "1234567890", "john@example.com", "Math, Science", 3.8, 2022);
    Professor professor1("Dr. Smith", "P456", "456 Avenue", "9876543210", "Computer Science", "Algorithms", 85000);
    Staff staff1("Alice Brown", "ST789", "789 Boulevard", "5555555555", "HR", "Manager", 60000);
    Course course1("C101", "Data Structures", 3, "Dr. Smith");
    
    cout << "Student Information:" << endl;
    student1.displayInfo();
    cout << "\nProfessor Information:" << endl;
    professor1.displayInfo();
    cout << "\nStaff Information:" << endl;
    staff1.displayInfo();
    
    cout << "\nCourse Registration:" << endl;
    course1.registerStudent(student1);
    course1.calculateGrade(student1);
    
    return 0;
}