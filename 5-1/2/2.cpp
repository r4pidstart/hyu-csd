#include<iostream>
using namespace std;

class Flight
{
    private:
        string flightNum, flightDep, flightDes;
        double dis, fuel;
        void calFuel(void)
        {
            if(dis <= 1000) fuel=500;
            else if(dis <= 2000) fuel=1500;
            else fuel=3000;
        }
    public:
        void flightInfo(void)
        {
            cout << "Flight number :";
            cin >> flightNum;
            cout << "Departure :";
            cin >> flightDep;
            cout << "Destination :";
            cin >> flightDes;
            while(true)
            {
                cout << "Distance :";
                cin >> dis;
                if(dis < 100) cout << "\'warning\n";
                else break;
            }
            calFuel();
        }
        void showFlightInfo(void)
        {
            cout << "Flight Information" << '\n' << "Flight number : " << flightNum << '\n' << "Departure / Destination : " << flightDep << " / " << flightDes << '\n' << "Distance : " << dis << " Km\n" << "Fuel : " << fuel; 
        }
};

int main(void)
{
    Flight flight;
    flight.flightInfo();
    flight.showFlightInfo();
}