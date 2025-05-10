#include <bits/stdc++.h>
using namespace std;

class StackOverflowException : public exception {
    protected:
        int len;
        string message;
    public:
        StackOverflowException(int len) : len(len) {
            message = "Stack is full with size " + to_string(len);
        }
        const char *what() const noexcept override
        {
            return message.c_str();
        }
};

class StackUnderflowException : public exception {
    public:
        const char *what() const noexcept override
        {
            return "Stack is empty!";
        }
};

template <class T>
class myStack
{
public:
    size_t size;
    T *arr = nullptr;
    size_t cur = 0;

    myStack(size_t size) : size(size)
    {
        arr = new T[size];
    }
    void push(T value)
    {
        if (cur == size)
            throw StackOverflowException(size);
        arr[cur++] = value;
    }
    void pop()
    {
        if (cur == 0)
            throw StackUnderflowException();
        cur--;
    }
    ~myStack()
    {
        delete[] arr;
    }
};

int main()
{
    myStack<int> S(4);
    cout << "Poping empty Stack" << endl;
    try
    {
        S.pop();
    }
    catch (const StackUnderflowException &e)
    {
        cout << "Exception Caught: " << e.what() << endl;
    }

    cout << "Pushing some values in Stack" << endl;
    S.push(10);
    S.push(11);
    S.push(12);
    S.push(13);

    cout << "Pushing a value in already Full Stack" << endl;
    try
    {
        S.push(20);
    }
    catch (StackOverflowException &e)
    {
        cout << "Exception Caught: " << e.what() << endl;
    }
    return 0;
}