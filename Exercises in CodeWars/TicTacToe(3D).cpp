/*
This Exercise is found on :
https://www.codewars.com/kata/5aa67541373c2e69a20000c9/train/cpp
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool checkwin(int matrix[4][4][4])
{
    for (int i = 0; i < 4; i++)
    {
        if (matrix[i][0][0] + matrix[i][1][1] + matrix[i][2][2] + matrix[i][3][3] == 4 || matrix[i][0][0] + matrix[i][1][1] + matrix[i][2][2] + matrix[i][3][3] == -4)
            return true;
        if (matrix[i][0][3] + matrix[i][1][2] + matrix[i][2][1] + matrix[i][3][0] == 4 || matrix[i][0][3] + matrix[i][1][2] + matrix[i][2][1] + matrix[i][3][0] == -4)
            return true;
        for (int j = 0; j < 4; j++)
        {
            if (matrix[i][j][0] + matrix[i][j][1] + matrix[i][j][2] + matrix[i][j][3] == 4 || matrix[i][j][0] + matrix[i][j][1] + matrix[i][j][2] + matrix[i][j][3] == -4)
                return true;
            if (matrix[i][0][j] + matrix[i][1][j] + matrix[i][2][j] + matrix[i][3][j] == 4 || matrix[i][0][j] + matrix[i][1][j] + matrix[i][2][j] + matrix[i][3][j] == -4)
                return true;
            if (matrix[0][i][j] + matrix[1][i][j] + matrix[2][i][j] + matrix[3][i][j] == 4 || matrix[0][i][j] + matrix[1][i][j] + matrix[2][i][j] + matrix[3][i][j] == -4)
                return true;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if (matrix[0][i][0] + matrix[1][i][1] + matrix[2][i][2] + matrix[3][i][3] == 4 || matrix[0][i][0] + matrix[1][i][1] + matrix[2][i][2] + matrix[3][i][3] == -4)
            return true;
        if (matrix[0][0][i] + matrix[1][1][i] + matrix[2][2][i] + matrix[3][3][i] == 4 || matrix[0][0][i] + matrix[1][1][i] + matrix[2][2][i] + matrix[3][3][i] == -4)
            return true;
    }
    if (matrix[0][0][0] + matrix[1][1][1] + matrix[2][2][2] + matrix[3][3][3] == 4 || matrix[0][0][0] + matrix[1][1][1] + matrix[2][2][2] + matrix[3][3][3] == -4)
        return true;
    if (matrix[0][3][3] + matrix[1][2][2] + matrix[2][1][1] + matrix[3][0][0] == 4 || matrix[0][3][3] + matrix[1][2][2] + matrix[2][1][1] + matrix[3][0][0] == -4)
        return true;
    return false;
}
string playOX3D(const vector<vector<int>> &moves)
{
    int matrix[4][4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                matrix[i][j][k] = 0;
    for (int i = 0; i < moves.size(); i++)
    {
        if (i % 2 == 0)
        {
            matrix[moves[i][0]][moves[i][1]][moves[i][2]] = -1;
            if (checkwin(matrix))
            {
                string result = "O wins after ";
                result += to_string(i + 1);
                result += " moves";
                return result;
            }
        }
        else
        {
            matrix[moves[i][0]][moves[i][1]][moves[i][2]] = 1;
            if (checkwin(matrix))
            {
                string result = "X wins after ";
                result += to_string(i + 1);
                result += " moves";
                return result;
            }
        }
    }
    return "No winner"; // Do your magic!
}
int main()
{
    cout << playOX3D({{0, 1, 1},
                      {0, 0, 0}, // X
                      {0, 2, 2},
                      {1, 1, 1}, // X
                      {1, 2, 2},
                      {2, 2, 2}, // X
                      {2, 1, 2},
                      {3, 3, 3}, // X
                      {0, 2, 1}});
    system("pause");
    return 0;
}