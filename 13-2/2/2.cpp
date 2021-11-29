#include<iostream>
#include<string>
using namespace std;

class MyException
{
    public:
        void report()
        {
            cout << "Exception report";
        }
};

class MyArray
{
    private:
        int* my_array;
        int maxSize;
    public:
        MyArray(int s)
        {
            maxSize=s;
            my_array=new int[s];
        }
        ~MyArray()
        {
            delete[] my_array;
        }
        int& operator[](const int& index)
        {
            if(!(0<=index and index<maxSize)) throw(MyException());
            return my_array[index];
        }
};

int main() {
    MyArray myArray(5);
    try{
        myArray[20];
    }
    catch(MyException & e){
        e.report();
    }
    return 0;
}