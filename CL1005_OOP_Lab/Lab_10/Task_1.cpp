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
    int i = 0;
    cout << endl;;
    while(getline(fin,line)){
        if(line[0]=='/' || line[0]=='\0'){
            continue;
        }
        cout << line << endl;
        i++;
    }
    fin.close();
    return 0;
}