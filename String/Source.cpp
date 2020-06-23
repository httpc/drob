#include<iostream>
using namespace std;

class String
{

    int size;
    char* str;
public:
    explicit String(int size = 80)
    {
        this->size = size;
        this->str = new char[size];
        cout << "DefConstructor:\t" << this << endl;
    }
    ~String()
    {
        delete[] str;
        cout << "Destructor:\t" << this << endl;
    }


    void print()const
    {
        cout << "Size:\t" << size << endl;
        cout << "Str:\t" << str << endl;
    }
};

void main()
{
    setlocale(LC_ALL, "Rus");
    String str(8);
    str.print();
    String str1 = "Hello";
}