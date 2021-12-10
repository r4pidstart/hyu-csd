#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
    char *strbuf;
    int len;

    int strbuf_size;

public:
    MyString();
    MyString(const char *str);
    MyString(const MyString &str);
    MyString(MyString &&str);
    MyString &operator=(const MyString &s);
    MyString& operator=(MyString&& s);
    ~MyString();

    int length() const;
    void println();
};

MyString::MyString()
{
    len = 0;
    strbuf_size = 0;
    strbuf = NULL;
}

MyString::MyString(const char *str)
{
    len = strlen(str);
    strbuf_size = len;
    strbuf = new char[len];

    for (int i = 0; i != len; i++)
        strbuf[i] = str[i];
}

MyString::MyString(const MyString &str)
{
    std::cout << "Copy constructor!" << std::endl;
    len = str.len;
    strbuf = new char[len];

    for (int i = 0; i != len; i++)
        strbuf[i] = str.strbuf[i];
}

MyString::~MyString()
{
    if (strbuf)
        delete[] strbuf;
}

MyString &MyString::operator=(const MyString &s)
{
    std::cout << "Copy assignment operator!" << std::endl;
    if (s.len > strbuf_size)
    {
        delete[] strbuf;
        strbuf = new char[s.len];
        strbuf_size = s.len;
    }
    len = s.len;
    for (int i = 0; i != len; i++)
    {
        strbuf[i] = s.strbuf[i];
    }

    return *this;
}

int MyString::length() const { return len; }

void MyString::println()
{
    for (int i = 0; i != len; i++)
        std::cout << strbuf[i];

    std::cout << std::endl;
}

MyString& MyString::operator=(MyString&& s)
{
    cout << "Move operator\n";
    len=strbuf_size=s.len;
    strbuf = new char[s.len];

    for(int i=0; i!=len; i++)
        strbuf[i]=s.strbuf[i];

    return *this;
}

MyString::MyString(MyString&& s)
{
    cout << "Move assign operator\n";
    len=strbuf_size=s.len;
    strbuf = new char[s.len];

    for(int i=0; i!=len; i++)
        strbuf[i]=s.strbuf[i];
}


template <typename T>
void my_swap(T &a, T &b)
{
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}

int main()
{
    MyString str1("abc");
    MyString str2("def");
    std::cout << "Before swap -----" << std::endl;
    std::cout << "str1 : ";
    str1.println();
    std::cout << "str2 : ";
    str2.println();

    std::cout << "After swap -----" << std::endl;
    my_swap(str1, str2);
    std::cout << "str1 : ";
    str1.println();
    std::cout << "str2 : ";
    str2.println();
}
