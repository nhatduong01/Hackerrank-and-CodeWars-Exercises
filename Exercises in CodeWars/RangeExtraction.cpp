/*
This kata can be found on :
https://www.codewars.com/kata/51ba717bb08c1cd60f00002f/train/cpp
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;
std::string range_extraction(std::vector<int> args)
{
    bool flag = true;
    int i = 0;
    string final_string = "";
    unsigned int size = args.size();
    while (i < size)
    {
        final_string += to_string(args[i]);
        if (i + 2 != size)
        {
            if (args[i + 1] == args[i] + 1 && args[i + 2] == args[i] + 2)
            {
                int j = i + 3;
                while (j != size && args[j] == args[i] + j - i)
                {
                    j++;
                }
                final_string += '-';
                final_string += to_string(args[j - 1]);
                i = j - 2;
            }
        }
        if (i != size - 1)
            final_string += ',';
        i++;
    }
    return final_string;
}
int main()
{
    cout << range_extraction({-6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20});
    return 0;
}