#include <iostream>
using namespace std;
int checkN()
{
    int num;
    cout << "S = ";
    cin >> num;
    if (!(num > 0 && num <= 100)) throw(domain_error("Out of range error"));
    return num;
}
int main(void)
{
    int N, cnt = 0;
    string input;
    try
    {
        N=checkN();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        abort();
    }
    for (int i = 0; i < N; i++)
    {
        while (true)
        {
            int eli = 0;
            cin >> input;
            for (int i = 0; i < input.size(); i++)
            {
                if (!(input[i] >= 'a' && input[i] <= 'z'))
                {
                    cout << "warning" << endl;
                    eli = 1;
                    break;
                }
            }
            if (eli == 0)
            {
                break;
            }
        }
        bool group = true;
        for (int j = 0; j < input.size(); j++)
        {
            for (int k = 0; k < j; k++)
            {
                if (input[j] != input[j - 1] && input[j] == input[k])
                {
                    group = false;
                    break;
                }
            }
        }
        if (group == true)
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}