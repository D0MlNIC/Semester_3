#include <iostream>
#include <string>

using namespace std;

class SmartDevice {
    public:
        virtual void turnOn() = 0; 
        virtual void turnOff() = 0; 
        virtual void getStatus() = 0; 
};

class LightBulb : public SmartDevice {
    bool isOn;
    int brightness;

    public: 
        LightBulb(bool isOn, int brightness) : isOn(isOn), brightness(brightness) {}
        void turnOn() {
            isOn = true;
        }
        void turnOff() {
            isOn = false;
        }
        void getStatus() {
            cout << "Light is " << (isOn ? "On" : "Off") << endl;
            cout << "Brightness: " << brightness << endl;
        }
};

class Thermostat : public SmartDevice {
    bool isOn;
    double temperature;

    public: 
        Thermostat(bool isOn, double temperature) : isOn(isOn), temperature(temperature) {}
        void turnOn() {
            isOn = true;
        }
        void turnOff() {
            isOn = false;
        }
        void getStatus() {
            cout << "Thermostat is " << (isOn ? "Active" : "Non-Active") << endl;
            cout << "Temperature: " << temperature << endl;
        }
};

int main() {
    LightBulb l1(0, 75);
    Thermostat t1(1, 32);
    l1.turnOn();
    t1.turnOff();
    l1.getStatus();
    cout << endl;
    t1.getStatus();
    return 0;
}