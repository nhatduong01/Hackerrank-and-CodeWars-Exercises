#include <iostream>
#include <string>
#include <map>
//#include <iterator>
#include <math.h>
using namespace std;
int result(string hex_num)
{
    int dec_num = 0;
    map<char, int> all_values;
    int j = 10;
    for (int i = 65; i <= 70; i++)
    {
        all_values.insert({(char)i, j++});
    }
    for (int i = 0; i < hex_num.length(); i++)
    {
        auto temp = all_values.find(hex_num[hex_num.length() - 1 - i]);
        if (temp != all_values.end())
            dec_num += temp->second * pow(16, i);
        else
            dec_num += (hex_num[hex_num.length() - 1 - i] - '0') * pow(16, i);
    }
    return dec_num;
}
void reverseStr(string &str)
{
    int n = str.length();

    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}
string dec_to_hex(int dex_num)
{
    if (dex_num < 0)
        dex_num = 0;
    if (dex_num == 0)
        return "00";
    if (dex_num > 255)
        dex_num = 255;
    string result = "";
    map<int, char> all_values;
    char j = 'A';
    for (int i = 10; i <= 15; i++)
    {
        all_values.insert({i, j++});
    }
    while (dex_num)
    {
        int temp = dex_num % 16;
        if (temp >= 10)
        {
            auto value = all_values.find(temp);
            result += value->second;
        }
        else
        {
            result += to_string(temp);
        }
        dex_num /= 16;
    }
    if (result.length() == 1)
    {
        result += '0';
    }
    reverseStr(result);
    return result;
}
class RGBToHex
{
public:
    static std::string rgb(int r, int g, int b)
    {
        string first = dec_to_hex(r);
        string second = dec_to_hex(g);
        string third = dec_to_hex(b);
        return first + second + third;
    }
};
int main()
{
    RGBToHex test;
    cout << test.rgb(148, 0, 211) << "\n";
    return 0;
}