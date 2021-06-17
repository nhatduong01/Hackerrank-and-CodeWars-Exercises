/*
This kata can be found on :
https://www.codewars.com/kata/576986639772456f6f00030c/train/cpp
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int MinIDX(int *dis, bool *flags, int num_rows)
{
    int min = INT16_MAX, min_idx;
    for (int i = 0; i < num_rows; i++)
        if (dis[i] < min && !flags[i])
        {
            min_idx = i;
            min = dis[i];
        }
    return min_idx;
}
int path_finder(std::string maze)
{
    unsigned int size = maze.size();
    int num_rows = 1;
    string fixed_maze = "";
    for (unsigned int i = 0; i < size; i++)
    {
        if (maze[i] == '\n')
            num_rows++;
        else
            fixed_maze += maze[i];
    }
    int num_each = num_rows;
    num_rows *= num_rows;
    int **graph = new int *[num_rows];
    for (int i = 0; i < num_rows; i++)
        graph[i] = new int[num_rows];

    for (int i = 0; i < num_rows; i++)
    {
        int j = i + 1;
        if (j < num_rows && j % num_each != 0)
            graph[i][j] = abs((int)fixed_maze[i] - (int)fixed_maze[j]);
        j = i - 1;
        if (j >= 0 && i % num_each != 0)
            graph[i][j] = abs((int)fixed_maze[i] - (int)fixed_maze[j]);
        j = i - num_each;
        if (j >= 0)
            graph[i][j] = abs((int)fixed_maze[i] - (int)fixed_maze[j]);
        j = i + num_each;
        if (j < num_rows)
            graph[i][j] = abs((int)fixed_maze[i] - (int)fixed_maze[j]);
    }
    int *distance = new int[num_rows];
    bool *flags = new bool[num_rows];
    for (int i = 0; i < num_rows; i++)
        flags[i] = false, distance[i] = INT16_MAX;
    distance[0] = 0;
    for (int i = 0; i < num_rows; i++)
    {
        int minidx = MinIDX(distance, flags, num_rows);
        flags[minidx] = true;
        vector<int> storage;
        if (minidx + 1 < num_rows && (minidx + 1) % num_each != 0)
        {
            storage.push_back(minidx + 1);
        }
        if (minidx - 1 >= 0 && minidx % num_each != 0)
        {
            storage.push_back(minidx - 1);
        }
        if (minidx - num_each >= 0)
            storage.push_back(minidx - num_each);
        if (minidx + num_each < num_rows)
            storage.push_back(minidx + num_each);
        for (unsigned int vertice = 0; vertice < storage.size(); vertice++)
        {
            if (!flags[storage[vertice]] && distance[minidx] + graph[minidx][storage[vertice]] < distance[storage[vertice]])
                distance[storage[vertice]] = graph[minidx][storage[vertice]] + distance[minidx];
        }
    }
    int result = distance[num_rows - 1];
    for (int i = 0; i < num_rows; i++)
        delete[] graph[i];
    delete[] graph;
    delete[] distance;
    delete[] flags;
    return result;
}
int main()
{
    std::string s1 =

        "000\n"
        "000\n"
        "000";

    std::string s2 =

        "010\n"
        "010\n"
        "010";

    std::string s3 =

        "010\n"
        "101\n"
        "010";

    std::string s4 =

        "0707\n"
        "7070\n"
        "0707\n"
        "7070";

    std::string s5 =

        "700000\n"
        "077770\n"
        "077770\n"
        "077770\n"
        "077770\n"
        "000007";

    std::string s6 =

        "777000\n"
        "007000\n"
        "007000\n"
        "007000\n"
        "007000\n"
        "007777";

    std::string s7 =

        "000000\n"
        "000000\n"
        "000000\n"
        "000010\n"
        "000109\n"
        "001010";
    cout << path_finder(s7);
    system("pause");
    return 0;
}