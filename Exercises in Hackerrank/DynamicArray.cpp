#include <iostream>
#include <vector>
using namespace std;
vector<int> dynamicArray(int n, vector<vector<int>> queries)
{
    vector<vector<int>> temp;
    vector<int> result;
    int lastAnswer = 0;
    for (int i = 0; i < n; i++)
    {
        temp.push_back({});
    }
    for (int i = 0; i < queries.size(); i++)
    {
        if (queries[i][0] == 1)
        {
            temp[(queries[i][1] ^ lastAnswer) % n].push_back(queries[i][2]);
        }
        else
        {
            lastAnswer = temp[(queries[i][1] ^ lastAnswer) % n][queries[i][2] % temp[(queries[i][1] ^ lastAnswer) % n].size()];
            result.push_back(lastAnswer);
        }
    }
    return result;
}
int main()
{
    vector<int> result = dynamicArray(2, {{1, 0, 5}, {1, 1, 7}, {1, 0, 3}, {2, 1, 0}, {2, 1, 1}});
    for (auto i = result.begin(); i != result.end(); i++)
        cout << *i << "\t";
    system("pause");
    return 0;
}