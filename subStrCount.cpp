/*
 * Author: L.F.N   File Name: subStrCount.cpp
 * Created Time: 2018年06月10日 星期日 00时16分51秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
#include <string>
using namespace std;

bool subStrCount(const string& s)
{
    string tmp;
    for (int i = s.size()-1; i > 1; i--)
    {
        for (int j = 0; j < s.size(); j++)
        {
            if (j + i <= s.size())
            {
                size_t t = 0;
                size_t num = 0;
                tmp = s.substr(j, i);
                t = s.find(tmp);
                num = s.rfind(tmp);
                if (t != num)
                {
                    cout << tmp <<  " pos: " << t+1 << endl;
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    string str;
    cout << "Enter str: ";
    cin >> str;
    cout << endl;
    string& st = str;
    if (!subStrCount(st))
        cout << "not found!\n";
    return 0;
}
