#include <vector>
#include <iostream>
using namespace std;
std::vector<int> snail(const std::vector<std::vector<int>> &snail_map)
{
    int size = snail_map.size();
    vector<vector<bool>> flag;
    vector<bool> temp;
    for (int i = 0; i < size; i++)
    {
        temp.push_back(false);
    }
    for (int i = 0; i < size; i++)
    {
        flag.push_back(temp);
    }
    vector<int> result;
    int i = 0, j = 0;

    while (result.size() != size * size)
    {
        result.push_back(snail_map[i][j]);
        flag[i][j] = true;
        if (j < size - 1 && !flag[i][j + 1])
        {
            j++;
        }
        else if (i < size - 1 && !flag[i + 1][j])
        {
            i++;
        }
        else if (j > 0 && !flag[i][j - 1])
        {
            j--;
        }
        else if (i > 0 && !flag[i - 1][j])
        {
            i--;
            int m = i, n = j;
            for (; m >= size - i - 1; m--)
            {
                result.push_back(snail_map[m][n]);
                flag[m][n] = true;
            }
            j = i = m + 1;
        }
    }
    return result;
}
int main()
{
    vector<int> result = snail({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    for (auto i = result.begin(); i != result.end(); i++)
        cout << *i << "\t";
    return 0;
}