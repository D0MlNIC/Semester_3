#include <bits/stdc++.h>
using namespace std;

int main()
{
    ofstream fout("sensor_log.txt");
    cout << endl;;
    fout << "Hi, this file is for sensor data";
    cout << "Position of cursor in file after first write: " << fout.tellp() << endl;
    fout << endl;
    cout << endl;;
    fout << "Currently writing invisible sensor data";
    cout << "Position of cursor in file after second write: " << fout.tellp() << endl;
    fout << endl;
    fout.close();
    cout << endl;;
    
    return 0;
}