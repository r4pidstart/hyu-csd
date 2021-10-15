#include<iostream>
#include<string>
using namespace std;

class Printer
{
    private: 
        int availableCount, availablePage;
    public:
        // count, page
        Printer(int availableCount, int availablePage)
            :availableCount(availableCount), availablePage(availablePage) {}
        void print(int usedPage)
        {
            availableCount-=usedPage, availablePage-=usedPage;
        }
        int getAvailableCount(void)
        {
            return availableCount;
        }
        int getAvailablePage(void)
        {
            return availablePage;
        }
};

class InkjetPrinter : Printer
{
    private:
        const string model, manufacturer;
    public:
        InkjetPrinter(string model, string manufacturer, int availableCount, int availablePage)
            :Printer(availableCount, availablePage), model(model), manufacturer(manufacturer) {}
        void print(int usedPage)
        {
            if(usedPage <= getAvailableCount() && usedPage <= getAvailablePage())
            {
                Printer::print(usedPage);
                cout << "Printed.\n";
            }
            else
            {
                if(usedPage > getAvailableCount())
                    cout << "Cannot print because of not enough Ink.\n";
                if(usedPage > getAvailablePage())
                    cout << "Cannot print because of not enough Page.\n";
            }
        }
        void showInfo(void)
        {
            cout << "InkJet: " << model << ", " << manufacturer << ", " << getAvailablePage() << " availavle pages, " << getAvailableCount() << " available Ink\n";
        }
};

class LaserPrinter : Printer
{
    private:
        const string model, manufacturer;
    public:
        LaserPrinter(string model, string manufacturer, int availableCount, int availablePage)
            :Printer(availableCount, availablePage), model(model), manufacturer(manufacturer) {}
        void print(int usedPage)
        {
            if(usedPage <= getAvailableCount() && usedPage <= getAvailablePage())
            {
                Printer::print(usedPage);
                cout << "Printed.\n";
            }
            else
            {
                if(usedPage > getAvailableCount())
                    cout << "Cannot print because of not enough Toner.\n";
                if(usedPage > getAvailablePage())
                    cout << "Cannot print because of not enough Page.\n";
            }
        }
        void showInfo(void)
        {
            cout << "Laser: " << model << ", " << manufacturer << ", " << getAvailablePage() << " availavle pages, " << getAvailableCount() << " available Toner\n";
        }       
};

int main(void)
{
    int a,b;
    cout << "Currently operating 2 printers are follow\n"; cin >> a >> b;
    InkjetPrinter p1("OfficeJet V30", "HP", b, a);
    p1.showInfo();
    cin >> a >> b;
    LaserPrinter p2("SCX-6x47", "Samsung", b, a);
    p2.showInfo();

    while(true)
    {
        int type,pages;
        cout << "\nInsert printer(1:InkJet, 2:Laser) ans pages: "; cin >> type >> pages;
        if(type==1) p1.print(pages);
        else p2.print(pages);

        p1.showInfo();
        p2.showInfo();

        char c;
        while(true)
        {
            cout << "Do you want keep printing? (y/n) >>"; cin >> c;
            if(c=='y' || c=='n') break;
        }
        if(c=='n') break;
    }
}