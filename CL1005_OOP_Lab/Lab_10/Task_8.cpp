#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line;
    fstream file("config.txt", ios::in | ios::out);
    cout << endl;;
    file << "AAAAABBBBBCCCCC" << endl;
    file.seekg(0, ios::beg);
    getline(file, line);
    file.clear();
    cout << "Before Modification: " << line << endl;
    file.seekp(5, ios::beg);
    for(int i=0; i<5; i++) file.put('X');
    cout << endl;;
    file.seekg(0, ios::beg);
    getline(file, line);
    cout << "After Modification: " << line << endl;
    cout << endl;;
    file.close();
    return 0;
}