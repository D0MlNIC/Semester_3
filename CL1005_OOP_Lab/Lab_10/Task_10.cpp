#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("data_record.txt");
    fin.seekg(20, ios::beg);
    string record;
    getline(fin, record);
    cout << record << endl;
    fin.close();
    return 0;
}