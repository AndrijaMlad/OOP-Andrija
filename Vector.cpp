#include <iostream>
#include <stdexcept>

using namespace std;

class Vector {
private:
    int* data;
    int sz;
    int cap;

    void resize(int newCap) 
    {
        int* newData = new int[newCap];
        for(int i = 0; i < sz; i++) 
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        cap = newCap;
    }

public:
    // Constructor
    Vector() : data(nullptr), sz(0), cap(0) {}

    // Destructor
    ~Vector() 
    {
        delete[] data;
    }

    // push_back
    void push_back(int value) 
    {
        if(sz == cap) 
        {
            int newCap = (cap == 0) ? 1 : cap * 2;
            resize(newCap);
        }
        data[sz++] = value;
    }

    // pop_back
    void pop_back() 
    {
        if (sz == 0) 
        {
            cout<<"Vector is empty";
        }
        sz--;
    }

    // front
    int front() const 
    {
        if (sz == 0) 
        {
            cout<<"Vector is empty";
        }
        return data[0];
    }

    // back
    int back() const 
    {
        if(sz == 0) 
        {
            cout<<"Vector is empty";
        }
        return data[sz - 1];
    }

    // at
    int at(int index) const 
    {
        if(index < 0 || index >= sz) 
        {
            cout<<"Index out of range";
        }
        return data[index];
    }

    // size
    int size() const 
    {
        return sz;
    }
};
int main() 
{
    ///test od Chatgpt
    Vector A;

    A.push_back(10);
    A.push_back(20);
    A.push_back(30);

    cout << "Front: " << A.front() << '\n';
    cout << "Back: " << A.back() << '\n';
    cout << "At index 1: " << A.at(1) << '\n';

    A.pop_back();

    cout << "Size after pop: " << A.size() << '\n';
}
