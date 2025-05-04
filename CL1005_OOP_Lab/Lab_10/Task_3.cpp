#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line;

    ifstream fin;
    fin.open("vehicles.txt");
    if(!fin){
        cerr << "File Not Found!" << endl;
        exit(1);
    }
    int i = 1;
    cout << endl;;
    while(getline(fin,line)){
        if(line[0]=='/' || line[0]=='\0'){
            continue;
        }
        istringstream sin(line);
        string type, id, name, year, extra, cert;

        getline(sin, type, ',');
        getline(sin, id, ',');
        getline(sin, name, ',');
        getline(sin, year, ',');
        getline(sin, extra, ',');
        getline(sin, cert, ',');

        cout << "Vehicle: " << i << endl; 
        int intYear = stoi(year);
        cout << "String Version of Year: " << year << endl;
        cout << "Integer Version of Year: " << intYear << endl;
        cout << endl;
        i++;
    }
    fin.close();
    return 0;
}