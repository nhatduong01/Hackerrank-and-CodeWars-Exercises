/*
This kata canbe found on :
https://www.codewars.com/kata/585894545a8a07255e0002f1/train/cpp
credit goes to :
https://www.geeksforgeeks.org/number-of-ways-to-make-mobile-lock-pattern/
*/
#include <iostream>
using namespace std;
int totalPatternFromCur(bool visit[10], int jump[10][10],
                        int cur, int toTouch)
{
    if (toTouch <= 0)
    {
        return (toTouch == 0) ? 1 : 0;
    }

    int ways = 0;

    visit[cur] = true;

    for (int i = 1; i < 10; i++)
    {
        if (!visit[i] && (!jump[i][cur] || visit[jump[i][cur]]))
            ways += totalPatternFromCur(visit, jump, i, toTouch - 1);
    }

    visit[cur] = false;

    return ways;
}
unsigned int countPatternsFrom(char firstDot, unsigned short length)
{

    int jump[10][10] = {0};
    jump[1][3] = jump[3][1] = 2;
    jump[7][9] = jump[9][7] = 8;

    jump[1][7] = jump[7][1] = 4;
    jump[3][9] = jump[9][3] = 6;
    jump[1][9] = jump[9][1] = jump[2][8] = jump[8][2] = jump[3][7] = jump[7][3] = jump[4][6] = jump[6][4] = 5;

    bool visit[10] = {0};
    int ways = 0;
    int location = firstDot - 'A' + 1;
    if (location % 2 == 1 && location != 5)
        ways += totalPatternFromCur(visit, jump, 1, length - 1);
    else if (location % 2 == 0)
        ways += totalPatternFromCur(visit, jump, 2, length - 1);
    else
        ways += totalPatternFromCur(visit, jump, 5, length - 1);

    return ways;
}
int main()
{
    cout << countPatternsFrom('E', 8) << endl;
    system("pause");
    return 0;
}