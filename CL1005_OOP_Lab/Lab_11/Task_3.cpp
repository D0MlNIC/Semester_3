#include <bits/stdc++.h>
using namespace std;

class FileException
{
public:
    virtual const char *what() const noexcept
    {
        return "Unable to open file.";
    }
};

class FileNotFoundException: public FileException
{
public:
    const char *what() const noexcept override
    {
        return "Unable to find file.";
    }
};

class PermissionDeniedException: public FileException
{
public:
    const char *what() const noexcept override
    {
        return "Unable to access file.";
    }
};

void readFile(const string &fileName)
{
    ifstream file(fileName);
    if (!file)
    {
        if (errno == EACCES)
            throw PermissionDeniedException();
        else if (errno == ENOENT)
            throw FileNotFoundException();
        else
            throw FileException();
    }
    file.close();
}

int main()
{
    try{
        readFile("sample1.txt"); // File Exists, So No Error
    }
    catch(FileException& e){
        cout << "Exception Caught: " << e.what() << endl;
    }
    try {
        readFile("sample2.txt"); // File Doesn't Exist
    }
    catch(FileException& e){
        cout << "Exception Caught: " << e.what() << endl;
    }
    try {
        readFile("secret.txt");  // File Read Permission
    }
    catch(FileException& e){
        cout << "Exception Caught: " << e.what() << endl;
    }
    return 0;
}