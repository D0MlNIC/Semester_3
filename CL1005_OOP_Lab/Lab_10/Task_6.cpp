#include <bits/stdc++.h>
using namespace std;

struct InventoryItem{
    int id;
    char name[20];
};

class FileHandler
{
private:
    ifstream fin;
    ofstream fout;

public:
    void writeFile(string fileName, InventoryItem& s)
    {
        fout.open(fileName, ios::binary);
        fout.write((char*)&s, sizeof(s));
        cout << "Successfully written content" << endl;
        fout.close();
    }
    void readFile(string fileName, InventoryItem& s)
    {
        fin.open(fileName, ios::binary);
        fin.read((char*)&s, sizeof(s));
        cout << "Successfully read content" << endl;
        fin.close();
    }
};

int main()
{
    InventoryItem s1 = {101, "Shahmir"};
    InventoryItem s2;

    FileHandler f1, f2;

    f1.writeFile("inventory.data", s1);
    f1.readFile("inventory.data", s2);

    cout << endl;;
    cout << "Item Id: " << s2.id << endl;
    cout << "Item Name: " << s2.name << endl;
    cout << endl;;

    return 0;
}