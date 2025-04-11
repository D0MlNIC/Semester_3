#include <iostream>
#include <string>

using namespace std;

class Teacher;

class Student {
    private:
        string name;
        int grades[3];

    public:
        Student(string n, int g1, int g2, int g3) : name(n) {
            grades[0] = g1;
            grades[1] = g2;
            grades[2] = g3;
        }

        friend class Teacher;
        friend float averageGrade(Student);
};

class Teacher {
    private:
        string name;

    public:
        Teacher(string n) : name(n) {}

        void viewGrades(Student s) {
            cout << "Student Name: " << s.name << endl;
            for (int i=1; i<=3; i++) {
                cout << "Grade " << i << ": " << s.grades[i-1] << endl;
            }
            cout << endl;
        }

        void updateGrade(Student &s, int index, int marks) {
            s.grades[index] = marks;
        }
};

float averageGrade(Student s) {
    float avg = 0;
    for (int i=0; i<3; i++) {
        avg += s.grades[i];
    }
    avg /= 3;
    return avg;
}

int main() {
    Student s("Muhib", 90, 80, 55);
    Teacher t("Talha");
    t.viewGrades(s);
    t.updateGrade(s, 2, 95);
    t.viewGrades(s);
    float avg = averageGrade(s);
    cout << "Average Marks = " << avg << endl;
    return 0;
}