/*
This exercise is found on :
https://www.codewars.com/kata/573992c724fc289553000e95/train/cpp
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <utility>
using namespace std;
long long number(int arr[], int size)
{
    long long result = 0;
    int idx = 0;
    while (idx < size)
    {
        result += arr[idx] * powl(10, size - idx - 1);
        idx++;
    }
    return result;
}
class ToSmallest
{
public:
    static std::vector<long long> smallest(long long n)
    {
        vector<long long> result;
        int numdigits = log10(n) + 1;
        long long temp = n;
        int *arr = new int[numdigits];
        int idx = numdigits - 1;
        while (temp != 0)
        {
            arr[idx] = temp % 10;
            idx--;
            temp /= 10;
        }
        long long min = 0;
        int before, after;
        for (int i = 0; i < numdigits; i++)
        {
            for (int j = 0; j < numdigits; j++)
            {
                if (j == i)
                    continue;
                swap(arr[i], arr[j]);
                long long temp = number(arr, numdigits);
                if (min == 0 || min > temp)
                {
                    min = temp;
                    before = i;
                    after = j;
                }
                swap(arr[i], arr[j]);
            }
        }
        result.push_back(min);
        result.push_back(before);
        result.push_back(after);
        for (auto i = result.begin(); i != result.end(); i++)
        {
            cout << *i << "\t";
        }
        cout << endl;
        return result;
    }
};
int main()
{
    ToSmallest test;
    test.smallest(999);
    system("pause");
    return 0;
}
