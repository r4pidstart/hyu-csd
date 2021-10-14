#include<iostream>
#include<string>
using namespace std;

class SimpleTest
{
    public:
        SimpleTest(int _num)
        {  
            num=_num;
        }
        void showTest()
        {
            cout << "Call number : " << num << '\n';
        }
        void showTest() const
        {
            cout << "Call const number : " << num << '\n';
        }
        void changeNum(int target)
        {
            num=target;
        }
    private:
        int num;
};

int main(){
    int num_1,num_2;
    std::cout << "Number_1 : ";
    std::cin >> num_1;
    std::cout << "Number_2 : ";
    std::cin >> num_2;
    SimpleTest simpleTest(num_1);
    const SimpleTest constSimpleTest(num_2);
    std::cout << "Change num_ : ";
    std::cin >> num_1;
    simpleTest.changeNum(num_1);
    simpleTest.showTest();
    constSimpleTest.showTest();
    return 0;
}