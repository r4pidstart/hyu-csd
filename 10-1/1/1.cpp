#include<iostream>
#include<string>
using namespace std;

class RangeCalc
{
    private:
        virtual void read()=0;
        virtual void write() const=0;
        virtual int calculate()=0;
    protected:
        int result;
    public:
        void run()
        {
            read();
            result=calculate();
            write();
        }
};

class RangeAdder : public RangeCalc
{
    private:
        virtual void read()
        {
            cout << "Add Ints In Range: Sum all integer values between first and second input.\nInsert two integers >>";
        }
        virtual int calculate()
        {
            int a,b; cin>>a>>b;
            return b*(b+1)/2 - (a-1)*(a)/2;
        }
        virtual void write() const
        {
            cout << "The result is " << result << "\n\n";
        }
};

class RangeMultiplier : public RangeCalc
{
    private:
        virtual void read()
        {
            cout << "Multiply Ints In Range: Multiply all integer values between first and second input.\nInsert two integers >>";
        }
        virtual int calculate()
        {
            int a,b; cin>>a>>b;
            int ret=1;
            for(int i=a; i<=b; i++) ret*=i;
            return ret;
        }
        virtual void write() const
        {
            cout << "The result is " << result << "\n\n";
        }
};

int main(void)
{
    RangeCalc *adder=new RangeAdder;
    adder->run();
    RangeCalc *multiplier=new RangeMultiplier;
    multiplier->run();
}