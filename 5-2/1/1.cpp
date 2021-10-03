#include<iostream>
#include<string>
using namespace std;

class Library
{
    private:
        string *_title, *_author;
        int *_price;
    public:
        Library(int num)
        {
            _title=new string[num];
            _author=new string[num];
            _price=new int[num];
        }
        void setBookInfo(int idx, string title, string author, int price)
        {
            _title[idx]=title, _author[idx]=author, _price[idx]=price;
        }
        void showBookList(int num)
        {
            for(int i=0; i<num; i++)
            {
                cout << "Book " << i+1 << " : " <<  _title[i] << '\n' << _author[i] << " / " << _price[i] << '\n';
            }
        }
        ~Library()
        {
            delete[] _title;
            delete[] _author;
            delete[] _price;
        }
};

int main(void)
{
    int num;
    cout << "How many register book : "; cin >> num;
    Library lib = Library(num);
    for(int i=0; i<num; i++)
    {
        string title, author;
        int price;
        cin.ignore();
        cout << "Book title : "; getline(cin, title);
        cout << "Book author : "; getline(cin, author);
        cout << "Book price : "; cin >> price;
        lib.setBookInfo(i, title, author, price);
    }
    lib.showBookList(num);
}