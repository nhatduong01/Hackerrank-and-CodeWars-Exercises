/*
This Exercise is taken from  
https://www.codewars.com/kata/5508249a98b3234f420000fb/train/cpp
*/

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
class CaesarCipher
{
public:
    static std::vector<std::string> movingShift(const std::string &s, int shift)
    {
        vector<string> result;
        string temp = "";
        int size = ceil((float)s.length() / 5);
        int idx = shift;
        for (int i = 0; i < s.length(); i++)
        {
            if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
            {
                if (s[i] >= 65 && s[i] <= 90)
                {
                    int extra = s[i] + (idx % 26);
                    if (extra > 90)
                        extra -= 26;
                    temp += (char)extra;
                    if (temp.length() == size)
                    {
                        result.push_back(temp);
                        temp = "";
                    }
                }
                else
                {
                    int extra = s[i] + (idx % 26);
                    if (extra > 122)
                        extra -= 26;
                    temp += (char)extra;
                    if (temp.length() == size)
                    {
                        result.push_back(temp);
                        temp = "";
                    }
                }
            }
            else
            {
                temp += s[i];
                if (temp.length() == size)
                {
                    result.push_back(temp);
                    temp = "";
                }
            }
            idx++;
        }
        if (result.size() < 5)
            result.push_back(temp);
        if (result.size() != 5)
        {
            temp = "";
            for (int i = result.size(); i <= 5; i++)
                result.push_back(temp);
        }
        cout << "The vector is :" << endl;
        for (auto i = result.begin(); i != result.end(); i++)
            cout << *i << "\n";
        return result;
    }
    static std::string demovingShift(std::vector<std::string> &s, int shift)
    {
        string result = "";
        int idx = 0 - shift;
        for (auto i = s.begin(); i != s.end(); i++)
        {
            for (int j = 0; j < (*i).length(); j++)
            {
                if (((*i)[j] >= 65 && (*i)[j] <= 90) || ((*i)[j] >= 97 && (*i)[j] <= 122))
                {
                    if ((*i)[j] >= 65 && (*i)[j] <= 90)
                    {
                        int extra = (*i)[j] + (idx % 26);
                        if (extra < 65)
                            extra += 26;
                        result += (char)extra;
                    }
                    else
                    {
                        int extra = (*i)[j] + (idx % 26);
                        if (extra < 97)
                            extra += 26;
                        result += (char)extra;
                    }
                }
                else
                {
                    result += (*i)[j];
                }
                idx--;
            }
        }
        return result;
    }
};
int main()
{
    string test = " uoxIirmoveNreefckgieaoiEcooqo";
    CaesarCipher testing;
    vector<string> result = testing.movingShift(test, 2);
    cout << "The final string is : " << testing.demovingShift(result, 2) << "\n";
    system("pause");
    return 0;
}