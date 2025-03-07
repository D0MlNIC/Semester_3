#include <iostream>
#include <string>

using namespace std;

class Device {
    protected:
        int deviceID;
        bool status;

    public:
        Device(int did, bool s) : deviceID(did), status(s) {}

        void displayDetails() {
            cout << "Device ID: " << deviceID << endl;
            cout << "Status: " << status << endl;
        }
};

class SmartPhone : virtual public Device {
    protected:
        float screenSize;

    public:
        SmartPhone(int did, bool s, float ss) : Device(did, s), screenSize(ss) {}
        
        void displayDetails() {
            Device::displayDetails();
            cout << "Screen Size: " << screenSize << endl;
        }
};

class SmartWatch : virtual public Device {
    protected:
        bool heartRateMonitor;

    public:
        SmartWatch(int did, bool s, bool hrm) : Device(did, s), heartRateMonitor(hrm) {}
        
        void displayDetails() {
            Device::displayDetails();
            cout << "Heart Rate Monitor: " << heartRateMonitor << endl;
        }
};

class SmartWearable : public SmartPhone, public SmartWatch {
    protected:
        int stepCounter;

    public:
        SmartWearable(int did, bool s, float ss, bool hrm, int sc) :
            Device(did, s), SmartPhone(did, s, ss), SmartWatch(did, s, hrm), stepCounter(sc) {}

        void displayDetails() {
            SmartPhone::displayDetails();
            cout << "Heart Rate Monitor: " << heartRateMonitor << endl;
            cout << "Step Counter: " << stepCounter << endl;
        }
};

int main() {
    SmartWearable s1(1, true, 6, true, 1000);
    s1.displayDetails();
    return 0;
}