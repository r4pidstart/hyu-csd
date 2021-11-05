#include<iostream>
#include<string>
#include<map>
using namespace std;

class DeliveryFood 
{
    protected:
        int totalPrice;
        string sideMenu;
    public:
        DeliveryFood() : totalPrice(0){}
        int getTotalPrice(){return totalPrice;}
        string getSideMenu() {return sideMenu;}
        virtual void sideMenuAdd(string _sideName) = 0;
        virtual void showSideMenu() = 0;
        virtual void addFood() = 0;
};

class Pizza : public DeliveryFood
{
    private:
        map<string,int> m;
        int price;
    public:
        Pizza(int price):price(price)
        {
            m["cola"]=2000;
            m["fried potato"]=3000;
            m["sprite"]=2000;
        }
        ~Pizza()
        {
            // ?
        }
        virtual void sideMenuAdd(string _sideName)
        {
            if(sideMenu!="") totalPrice-=m[sideMenu];
            sideMenu=_sideName, totalPrice+=m[sideMenu];
        }
        virtual void showSideMenu()
        {
            int i=1;
            for(auto& it : m)
                cout << i++ << ". "<<it.first << ' ' << it.second << '\n';
        }
        virtual void addFood()
        {
            totalPrice+=price;
        }
};

class Chicken : public DeliveryFood
{
    private:
        map<string,int> m;
        int price;
    public:
        Chicken(int price):price(price)
        {
            m["cheese ball"]=4000;
            m["cola"]=2000;
            m["fried potato"]=3000;
            m["sprite"]=2000;
        }
        ~Chicken()
        {

        }
        virtual void sideMenuAdd(string _sideName)
        {
            sideMenu=_sideName, totalPrice+=m[sideMenu];
        }
        virtual void showSideMenu()
        {
            int i=1;
            for(auto& it : m)
                cout << i++ << ". "<<it.first << ' ' << it.second << '\n';
        }
        virtual void addFood()
        {
            totalPrice+=price;
        }
};

int main() 
{
    DeliveryFood* margheritaPizza = new Pizza(12000);
    DeliveryFood* gorgonzolaPizza = new Pizza(15000);
    DeliveryFood* friedChicken = new Chicken(17000);
    DeliveryFood* spicyChicken = new Chicken(19000);
    int chooseFoodNum = 0;
    cout << "1. margherita pizza" << endl;
    cout << "2. gorgonzola pizza" << endl;
    cout << "3. fried chicken" << endl;
    cout << "4. spicy chicken" << endl;
    cout << "choose food : ";
    cin >> chooseFoodNum;

    DeliveryFood* sel;
    string chosenFood;
    switch(chooseFoodNum)
    {
        case 1:
            sel=margheritaPizza;
            chosenFood="margheritaPizza";
            break;
        case 2:
            sel=gorgonzolaPizza;
            chosenFood="gorgonzolaPizza";
            break;
        case 3:
            sel=friedChicken;
            chosenFood="friedChicken";
            break;
        case 4:
            sel=spicyChicken;
            chosenFood="spicyChicken";
            break;
    }

    sel->addFood();
    sel->showSideMenu();
    cout << "choose side menu : ";
    int chooseSideMenuNum; cin >> chooseSideMenuNum;
    string chosenSideMenu;
    switch(chooseSideMenuNum)
    {
        case 1:
            chosenSideMenu=chooseFoodNum/3 ? "cheese ball":"cola";
            break;
        case 2:
            chosenSideMenu=chooseFoodNum/3 ? "cola":"fried potato";
            break;
        case 3:
            chosenSideMenu=chooseFoodNum/3 ? "fried potato":"sprite";
            break;
        case 4:
            chosenSideMenu="sprite";
            break;
    }
    sel->sideMenuAdd(chosenSideMenu);
    cout << chosenFood <<", "<< sel->getSideMenu() <<" : " << sel->getTotalPrice();
}
