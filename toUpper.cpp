/*
 * Author: L.F.N   File Name: toUpper.cpp
 * Created Time: 2018年06月05日 星期二 11时00分58秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
#include <ctype.h>
#include <string>
#include <algorithm>
using namespace std;

bool myToUpper(string&);
char toUpper(char ch)
{
    return toupper(ch);
}

int main(int argc, char **argv)
{
    //vector<string> words;
    string input;
    while (cin >> input && input != "quit")
    {
        //words. push_back(input);
        string& ss = input;
        if (!myToUpper(ss))
            cout << "call function error!\n";
        cout << ss << endl;
    }
    return 0;
}

bool myToUpper(string& str)
{
    transform(str.begin(),str.end(),str.begin(),toUpper);
    return true;
}

