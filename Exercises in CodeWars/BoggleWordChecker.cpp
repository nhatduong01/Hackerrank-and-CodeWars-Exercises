#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using namespace std;
bool Found = false;
int a = 0;
void FindUntil(vector<vector<char>> board, bool **flag, int row, int column, string &recent, string word)
{
    flag[row][column] = true;
    recent += board[row][column];
    //cout << "The string is : "<< recent << endl;
    if (word == recent)
    {
        Found = true;
        return;
    }
    for (int i = max(0, row - 1); i < min(a, row + 2); i++)
    {
        for (int j = max(0, column - 1); j < min(a, column + 2); j++)
        {
            if (flag[i][j] == false && Found == false)
                FindUntil(board, flag, i, j, recent, word);
        }
    }
    recent.erase(recent.length() - 1);
    flag[row][column] = false;
}
bool check_word(const vector<vector<char>> &board, const string &word)
{
    a = board.size();
    bool **flag = new bool *[a];
    for (int i = 0; i < a; i++)
    {
        flag[i] = new bool[a];
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
            flag[i][j] = false;
    }
    string str = "";
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            FindUntil(board, flag, i, j, str, word);
            if (Found)
                break;
        }
        if (Found)
            break;
    }
    for (int i = 0; i < a; i++)
        delete flag[i];
    delete flag;
    return Found;
}
int main()
{
    vector<vector<char>> test_board = {{'E', 'A', 'R', 'A'},
                                       {'N', 'L', 'E', 'C'},
                                       {'I', 'A', 'I', 'S'},
                                       {'B', 'Y', 'O', 'R'}};
    cout << check_word(test_board, "RSCAREIOYBAILNEA");
    return 0;
}