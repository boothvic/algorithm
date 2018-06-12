/*
 * Author: L.F.N   File Name: substr.cpp
 * Created Time: 2018年06月10日 星期日 00时55分53秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
#include <string>
#include <vector>
using namespace std;

pair<int, string> fun(const string& str)
{
    vector<string> substrs;
    int maxcount = 1, count = 1;
    string substr;
    int i, len = str.size();
    for (i = 0; i < len; i++)
    {
        substrs.push_back(str.substr(i, len-1));
    }

    for (i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            count = 1;
            if (substrs[i].substr(0, j-i) == substrs[j].substr(0, j-i))
            {
                ++count;
                for (int k = j + (j-i); k < len; k += j-i)
                {
                    if (substrs[i].substr(0, j-i) == substrs[k].substr(0, j-i))
                        ++count;
                    else
                        break;
                }

                if (count > maxcount)
                {
                    maxcount = count;
                    substr = substrs[i].substr(0, j-i);
                }
            }
        }
    }
    return make_pair(maxcount, substr);
}

int main(int argc, char **argv)
{
    string str;
    pair<int, string> rs;
    while (cin >> str && str != "quit")
    {
        rs = fun(str);
        cout << rs.second << ":" << rs.first << endl;
    }
    return 0;
}
