/*
This kata can be found on :
https://www.codewars.com/kata/5518a860a73e708c0a000027/train/cpp
*/
#include <list>
#include <iostream>
#include <math.h>
using namespace std;
int last_digit(list<int> array)
{
    if (array.size() == 0)
        return 1;
    int result = 1;
    for (auto i = array.rbegin(); i != array.rend(); i++)
    {
        int temp = (result < 4) ? result : result % 4 + 4;
        cout << "The value of temp is : " << temp << endl;
        result = pow(*i, temp);
    }
    return result % 10;
}
int main()
{
    cout << last_digit({12, 30, 21}) << endl;
    return 0;
}