/*
This kata can be found on :
https://www.codewars.com/kata/5a0573c446d8435b8e00009f/train/cpp
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
enum Direction
{
    RIGHT,
    LEFT,
    UP,
    DOWN
};
int x = 0;
int y = 0;
Direction current = LEFT;
int get_steps(string path, unsigned int &curr_loc)
{
    string final_num = "";
    while (curr_loc < path.size() && path[curr_loc] <= 57 && path[curr_loc] >= 48)
    {
        final_num += path[curr_loc++];
    }
    return final_num == "" ? 0 : stoi(final_num);
}
std::vector<int> i_am_here(std::string path)
{
    for (unsigned int i = 0; i < path.length(); i++)
    {
        int steps = 0;
        if (i == 0 && isdigit(path[i]))
        {
            switch (current)
            {
            case LEFT:
                steps = get_steps(path, i);
                i--;
                x -= steps;
                break;
            case RIGHT:
                steps = get_steps(path, i);
                i--;
                x += steps;
                break;
            case UP:
                steps = get_steps(path, i);
                i--;
                y += steps;
                break;
            case DOWN:
                steps = get_steps(path, i);
                i--;
                y -= steps;
                break;
            }
            continue;
        }
        switch (path[i])
        {
        case 'l':
            switch (current)
            {
            case LEFT:
                steps = get_steps(path, ++i);
                i--;
                y -= steps;
                current = DOWN;
                break;
            case RIGHT:
                steps = get_steps(path, ++i);
                i--;
                y += steps;
                current = UP;
                break;
            case UP:
                steps = get_steps(path, ++i);
                i--;
                x -= steps;
                current = LEFT;
                break;
            case DOWN:
                steps = get_steps(path, ++i);
                i--;
                x += steps;
                current = RIGHT;
                break;
            }
            break;
        case 'r':
            switch (current)
            {
            case LEFT:
                steps = get_steps(path, ++i);
                i--;
                y += steps;
                current = UP;
                break;
            case RIGHT:
                steps = get_steps(path, ++i);
                i--;
                y -= steps;
                current = DOWN;
                break;
            case UP:
                steps = get_steps(path, ++i);
                i--;
                x += steps;
                current = RIGHT;
                break;
            case DOWN:
                steps = get_steps(path, ++i);
                i--;
                x -= steps;
                current = LEFT;
                break;
            }
            break;
        default:
            switch (current)
            {
            case LEFT:
                steps = get_steps(path, ++i);
                i--;
                x += steps;
                current = RIGHT;
                break;
            case RIGHT:
                steps = get_steps(path, ++i);
                i--;
                x -= steps;
                current = LEFT;
                break;
            case UP:
                steps = get_steps(path, ++i);
                i--;
                y -= steps;
                current = DOWN;
                break;
            case DOWN:
                steps = get_steps(path, ++i);
                i--;
                y += steps;
                current = UP;
                break;
            }
            break;
        }
    }
    return {x, y};
}
int main()
{
    vector<int> result = i_am_here("");
    cout << "{" << result[0] << ", " << result[1] << "}\n";
    result = i_am_here("RLrl");
    cout << "{" << result[0] << ", " << result[1] << "}\n";
    result = i_am_here("r5L2l4");
    cout << "{" << result[0] << ", " << result[1] << "}\n";
    result = i_am_here("r5L2l4");
    cout << "{" << result[0] << ", " << result[1] << "}\n";
    cout << "The direction is : " << current << "\n";
    result = i_am_here("10r5r0");
    cout << "{" << result[0] << ", " << result[1] << "}\n";
    result = i_am_here("10r5r0");
    cout << "{" << result[0] << ", " << result[1] << "}\n";
    system("pause");
    return 0;
}