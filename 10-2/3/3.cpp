#include<iostream>
#include<string>
using namespace std;

class PublicTransport
{
    protected:
        int totalPrice;
    public:
        PublicTransport():totalPrice(0){cout << "ctor";}
        void show()
        {
            cout << "total price : " << totalPrice << '\n';
        }
};

class Bus : virtual public PublicTransport
{
    private:
        int busPrice, busTicket;
    public:
        Bus():busPrice(8000), busTicket(0){}
        void setTicket(int _ticket)
        {
            totalPrice+=_ticket*busPrice;
            busTicket+=_ticket;
        }
        int getTicket()
        {
            return busTicket;
        }
        int getPrice()
        {
            return busPrice;
        }   
        void show()
        {
            cout << "bus price : " << busPrice*busTicket << '\n';
        }
};

class Train : virtual public PublicTransport
{
    private:
        int trainPrice, trainTicket;
    public:
        Train():trainPrice(12000),trainTicket(0){}
        void setTicket(int _ticket)
        {
            totalPrice+=_ticket*trainPrice;
            trainTicket+=_ticket;
        }
        int getTicket()
        {
            return trainTicket;
        }
        int getPrice()
        {
            return trainPrice;
        }
        void show()
        {
            cout << "train price : " << trainPrice*trainTicket << '\n';
        }
};

class Transportation : public Bus, public Train
{
    public:
        void show()
        {
            Bus::show();
            Train::show();
            PublicTransport::show();
        }
        void buyTrain()
        {
            cout << "Train Price: " << Train::getPrice() << '\n';
            cout << "Train Ticket: " << Train::getTicket() << '\n';
            int ticket;
            cout << "Train Ticket: "; cin >> ticket;
            Train::setTicket(ticket);
        }
        void buyBus()
        {
            cout << "Bus Price: " << Bus::getPrice() << '\n';
            cout << "Bus Ticket: " << Bus::getTicket() << '\n';
            int ticket;
            cout << "Bus Ticket: "; cin >> ticket;
            Bus::setTicket(ticket);
        }
};

int main(void)
{
    Transportation transportation = Transportation();   
    transportation.buyBus();
    transportation.buyTrain();
    transportation.show();
}