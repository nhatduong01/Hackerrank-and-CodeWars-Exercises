#include <iostream>
#include <vector>
using namespace std;

// Complete the hourglassSum function below.
int sum(vector<vector<int>> arr, int row, int col)
{
    return arr[row][col] + arr[row - 1][col] + arr[row + 1][col] + arr[row - 1][col - 1] + arr[row - 1][col + 1] + arr[row + 1][col - 1] + arr[row + 1][col + 1];
}
int hourglassSum(vector<vector<int>> arr)
{
    int result[4][4];
    int row = 0, col = 0;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            result[row][col] = sum(arr, i, j);
            col++;
        }
        col = 0;
        row++;
    }
    int max = -100;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (result[i][j] > max)
                max = result[i][j];
        }
    }
    return max;
}

int main()
{
    cout << hourglassSum({{1, 1, 1, 0, 0, 0},
                          {0, 1, 0, 0, 0, 0},
                          {1, 1, 1, 0, 0, 0},
                          {0, 0, 2, 4, 4, 0},
                          {0, 0, 0, 2, 0, 0},
                          {0, 0, 1, 2, 4, 0}});
    system("pause");
    return 0;
}
