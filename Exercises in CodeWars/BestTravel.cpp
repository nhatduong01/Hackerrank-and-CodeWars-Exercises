/*
This exercise is founded on :
https://www.codewars.com/kata/55e7280b40e1c4a06d0000aa/train/cpp
*/
#include <iostream>
#include <vector>
using namespace std;
void CombinationGenerator(int arr[], int data[], vector<vector<int>> &result, int start, int end, int idx, int size)
{
    if (idx == size)
    {
        result.push_back({});
        for (int i = 0; i < size; i++)
        {
            result.back().push_back(data[i]);
        }
        return;
    }
    for (int i = start; i <= end && end - i + 1 >= size - idx; i++)
    {
        data[idx] = arr[i];
        CombinationGenerator(arr, data, result, i + 1, end, idx + 1, size);
    }
}
class BestTravel
{
public:
    static int chooseBestSum(int t, int k, std::vector<int> &ls)
    {
        int *arr = new int[ls.size()];
        int *data = new int[k];
        for (int i = 0; i < ls.size(); i++)
            arr[i] = ls[i]; // Create an array
        vector<vector<int>> result;
        CombinationGenerator(arr, data, result, 0, ls.size() - 1, 0, k);
        int max = 0;
        int sum;
        for (auto i = result.begin(); i != result.end(); i++)
        {
            sum = 0;
            for (auto j = (*i).begin(); j != (*i).end(); j++)
                sum += *j;
            if (sum > max && sum <= t)
                max = sum;
        }
        delete[] arr;
        delete[] data;
        return (max == 0) ? -1 : max;
    }
};  
int main()
{
    BestTravel test;
    vector<int> value{91, 74, 73, 85, 73, 81, 87};
    cout << test.chooseBestSum(230, 3, value);
    system("pause");
    return 0;
}