#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line;
    ifstream fin("large_log.txt");
    cout << endl;;
    getline(fin, line);
    cout << "Position after first reading: " << fin.tellg() << endl;
    cout << endl;;
    getline(fin, line);
    cout << "Position after second reading: " << fin.tellg() << endl;
    cout << endl;;
    getline(fin, line);
    fin.clear();
    cout << "Position after third reading: " << fin.tellg() << endl;
    cout << endl;;
    fin.close();
    return 0;
}