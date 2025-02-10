#include <iostream>
#include <string>

using namespace std;

class Planner {
    private:
        string months[12][31] = {{""}};
        int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    public:
        void add(int month, int day, string task) {
            months[month-1][day-1] = task;
            cout << "Task Added Successfully" << endl;
        }

        void update(int month, int day, string task) {
            cout << "Previous Task: " << months[month-1][day-1] << " has been deleted" << endl;
            months[month-1][day-1] = task;
            cout << "New Task Updated Successfully" << endl;
        }

        void remove(int month, int day) {
            cout << "Previous Task: " << months[month-1][day-1] << " has been deleted" << endl;
            months[month-1][day-1] = "";
        }

        void display() {
            for(int i=0; i<12; i++) {
                cout << "Month " << i+1 << " Tasks" << endl;
                for (int j=0; j<days[i]; j++) {
                    if (months[i][j] != "") {
                        cout << "Day " << j+1 << ": " << months[i][j] << endl;
                    }
                }
            }
        }
};

int main() {
    Planner plan;
    plan.add(2, 10, "Birthday");
    plan.add(5, 16, "Final Exams");
    plan.add(12,25, "Quaid-e-Azam Birthday");
    plan.display();
    plan.update(2, 10, "Some Event");
    plan.display();
    plan.remove(2, 10);
    return 0;
}