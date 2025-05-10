#include <bits/stdc++.h>
using namespace std;

class InvalidValueException : public exception
{
    protected:
        int age;
        string message;
    public:
        InvalidValueException(int val) : age(val) {
            if (age < 0) {
                message = "Age cannot be negative";
            } else if (age > 120) {
                message = "Age cannot exceed 120";
            }
        }
        const char* what() const noexcept override{
            return message.c_str();
        }
};

void validateAge(int age){
    if(age < 0 || age > 120) throw InvalidValueException(age);
    else cout << "Age is valid" << endl;
}

int main()
{
    try{
        validateAge(20);
    }
    catch (InvalidValueException& e){
        cout << "Exception caught: " << e.what() << endl;
    }
    try{
        validateAge(-20);
    }
    catch (InvalidValueException& e){
        cout << "Exception caught: " << e.what() << endl;
    }
    try{
        validateAge(175);
    }
    catch (InvalidValueException& e){
        cout << "Exception caught: " << e.what() << endl;
    }
    return 0;
}