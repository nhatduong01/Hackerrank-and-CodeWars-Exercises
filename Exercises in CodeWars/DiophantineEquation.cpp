/*
This exercise is found on :
https://www.codewars.com/kata/554f76dca89983cc400000bb/train/cpp
*/
#include <vector>
#include <utility>
#include <iostream>
#include <math.h>
using namespace std;
bool isInteger(double num)
{
    return floor(num) == num;
}
class Dioph
{
public:
    static std::vector<std::pair<long, long>> solEquaStr(long long n)
    {
        vector<pair<long, long>> result;
        for (long i = 1; i <= sqrt(n); i++)
        {
            double x = 0.5 * (i + (double)n / i);
            double y = 0.5 * (x - i);
            if (isInteger(x) && isInteger(y))
                result.push_back(make_pair(x, y));
        }
        return result;
    }
};
int main()
{
    Dioph test;
    vector<pair<long, long>> result = test.solEquaStr(90002);
    for (auto i = result.begin(); i != result.end(); i++)
    {
        cout << "(" << (*i).first << "," << (*i).second << ")\n";
    }
    system("pause");
    return 0;
}
