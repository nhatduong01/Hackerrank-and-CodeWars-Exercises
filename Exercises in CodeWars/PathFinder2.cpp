/*
You can find this kata at:
https://www.codewars.com/kata/57658bfa28ed87ecfa00058a/train/cpp
*/
#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <vector>
#define check_symbol 'x'
using namespace std;
int FindUntil(char **maze, int size)
{
    if (size == 1)
        return 0;
    queue<pair<int, int>> storage;
    storage.push(make_pair(0, 0));
    map<pair<int, int>, pair<int, int>> all_paths;
    all_paths.insert(make_pair(make_pair(0, 0), make_pair(-1, -1)));
    bool found = false;
    while (storage.size())
    {
        pair<int, int> top = storage.front();
        storage.pop();
        int x = top.first;
        int y = top.second;
        if (x == size - 1 && y == size - 1)
        {
            found = true;
            break;
        }
        if (maze[x][y] == check_symbol)
            continue;
        if (y + 1 < size && maze[x][y + 1] == '.')
        {
            storage.push(make_pair(x, y + 1));
            all_paths.insert(make_pair(make_pair(x, y + 1), make_pair(x, y)));
        }
        if (x + 1 < size && maze[x + 1][y] == '.')
        {
            storage.push(make_pair(x + 1, y));
            all_paths.insert(make_pair(make_pair(x + 1, y), make_pair(x, y)));
        }
        if (x - 1 >= 0 && maze[x - 1][y] == '.')
        {
            storage.push(make_pair(x - 1, y));
            all_paths.insert(make_pair(make_pair(x - 1, y), make_pair(x, y)));
        }
        if (y - 1 >= 0 && maze[x][y - 1] == '.')
        {
            storage.push(make_pair(x, y - 1));
            all_paths.insert(make_pair(make_pair(x, y - 1), make_pair(x, y)));
        }
        maze[x][y] = 'x';
    }
    if (!found)
        return -1;

    pair<int, int> temp = all_paths.find(make_pair(size - 1, size - 1))->second;
    vector<pair<int, int>> final_path;
    final_path.push_back(temp);
    //cout << "The temp is : [" << temp.first << ", " << temp.second << "] \n";
    while (temp != make_pair(0, 0))
    {
        if (temp == make_pair(-1, -1))
            break;
        int x = temp.first;
        int y = temp.second;
        temp = all_paths.find(make_pair(x, y))->second;
        final_path.push_back(temp);
    }
    return final_path.size();
}
int path_finder(string maze)
{
    // TODO: Return the minimal number of steps required to reach the exit located at
    // (n - 1, n - 1) from the initial position (0, 0) in an n × n maze if possible and
    // -1 otherwise
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
    int result = FindUntil(arr, num_rows);
    for (int i = 0; i < num_rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return result;
}
int main()
{
    cout << path_finder(".......\n.......\n.......\nWWWWW.W\n......W\n.......\n.......");
    system("pause");
    return 0;
}