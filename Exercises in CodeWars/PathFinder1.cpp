/*
This kata can be found on:
https://www.codewars.com/kata/5765870e190b1472ec0022a2/train/cpp
*/
#include <iostream>
#include <string>
#include <stack>
#include <utility>
#define check_symbol 'x'
using namespace std;
bool FindUntil(char **maze, int size)
{
    stack<pair<int, int>> storage;
    storage.push(make_pair(0, 0));
    while (storage.size())
    {
        pair<int, int> top = storage.top();
        storage.pop();
        int x = top.first;
        int y = top.second;
        if (x == size - 1 && y == size - 1)
            return true;
        if (maze[x][y] == check_symbol)
            continue;
        if (x + 1 < size && maze[x + 1][y] == '.')
            storage.push(make_pair(x + 1, y));
        if (x - 1 >= 0 && maze[x - 1][y] == '.')
            storage.push(make_pair(x - 1, y));
        if (y + 1 < size && maze[x][y + 1] == '.')
            storage.push(make_pair(x, y + 1));
        if (y - 1 >= 0 && maze[x][y - 1] == '.')
            storage.push(make_pair(x, y - 1));
        maze[x][y] = 'x';
    }
    return false;
}
bool path_finder(string maze)
{
    if (maze.back() == 'W')
        return false;
    int num_rows = 1;
    for (unsigned int i = 0; i < maze.size(); i++)
        if (maze[i] == '\n')
            num_rows++;
    char **arr = new char *[num_rows];
    for (int i = 0; i < num_rows; i++)
    {
        arr[i] = new char[num_rows];
    }
    int row = 0, col = 0;
    for (unsigned int i = 0; i < maze.size(); i++)
    {
        if (maze[i] == '\n')
        {
            row++;
            col = 0;
        }
        else
        {
            arr[row][col++] = maze[i];
        }
    }

    if (arr[num_rows - 1][num_rows - 2] == 'W' && arr[num_rows - 2][num_rows - 1] == 'W')
        return false;
    bool result = FindUntil(arr, num_rows);
    for (int i = 0; i < num_rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return result;
}
int main()
{
    cout << path_finder(".W.\n.W.\nW..") << "\n";
    system("pause");
    return false;
}