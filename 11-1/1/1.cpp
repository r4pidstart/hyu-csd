#include<iostream>
#include<string>
using namespace std;

class Book
{
    private:
        string title;
        int price, pages;
    public:
        Book(string title="", int price=0, int pages=0)
        {
            this->title=title; this->price=price; this->pages=pages;
        }
        void show()
        {
            cout << "Book : "<<title<<" "<<price<<"won "<<pages<<"pages \n";
        }
        friend bool operator==(Book& a, Book& b);
        friend bool operator==(Book& a, int& b);
        friend bool operator==(Book& a, string& b);
};

bool operator==(Book& a, Book& b)
{
    if(a.title == b.title and a.price==b.price and a.pages==b.pages) return 1;
    else return 0;
}

bool operator==(Book& a, int& b)
{
    if(a.price == b) return 1;
    else return 0;
}

bool operator==(Book& a, string& b)
{
    if(a.title == b) return 1;
    else return 0;
}

int main(void)
{
    Book a("Dune1", 30000, 500), b("Dune2", 30000, 500);
    a.show();
    if(a=="Dune1") cout << "this book is dune1\n";
    if(a==30000) cout << "original price is 30000 won\n";
    if(a==b) cout << "they are the same book\n";
}