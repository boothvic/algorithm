/*
 * Author: L.F.N   File Name: wordSet.cpp
 * Created Time: 2018年06月11日 星期一 10时42分01秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

void wordCount()
{
    map<string, int> M;
    map<string, int>::iterator j;
    string t;
    while (cin >> t && t != "?!")
        M[t]++;
    for (j = M.begin(); j != M.end(); ++j)
        cout << j->first << " " << j->second << endl;
}

int main(int argc, char **argv)
{
    set<string> S;
    set<string>::iterator j;
    string t;
    while (cin >> t && t != "?!")
        S.insert(t); //排序插入
    for (j = S.begin(); j != S.end(); ++j)
        cout << *j << endl;
    wordCount();

    return 0;
}
