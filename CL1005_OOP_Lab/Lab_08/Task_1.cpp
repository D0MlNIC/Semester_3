#include <iostream>
#include <cmath>

using namespace std;

class Humidity;

class Temperature {
    private:
        float temp;

    public:
        Temperature(float t) : temp(t) {}
        friend float calculateHeatIndex(Temperature t, Humidity h);
};

class Humidity {
    private:
        float humidity;

    public:
        Humidity(float h) : humidity(h) {}
        friend float calculateHeatIndex(Temperature t, Humidity h);
};

float calculateHeatIndex(Temperature t, Humidity h) {
    float tc = (t.temp * 9.0 / 5.0) + 32.0;
    float HI_F = -42.379 
                  + 2.04901523 * tc
                  + 10.14333127 * h.humidity 
                  - 0.22475541 * tc * h.humidity 
                  - 0.00683783 * pow(tc, 2) 
                  - 0.05481717 * pow(h.humidity, 2) 
                  + 0.00122874 * pow(tc, 2) * h.humidity 
                  + 0.00085282 * tc * pow(h.humidity, 2) 
                  - 0.00000199 * pow(tc, 2) * pow(h.humidity, 2);
    float HI_C = (HI_F - 32.0) * 5.0 / 9.0;
    return HI_C;
}

int main() {
    Temperature temp(32);
    Humidity h(70);
    float hi = calculateHeatIndex(temp, h);
    cout << "Heat Index is " << hi << " Celsius" << endl;
    return 0;
}