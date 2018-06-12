/*
 * Author: L.F.N   File Name: loopMoveStr.cpp
 * Created Time: 2018年06月09日 星期六 20时28分22秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
#include <cstring>
using namespace std;

void loopMoveStr(char* pStr, int steps)
{
    int n = strlen(pStr) - steps;
    char tmp[steps];
    cout << "strlen: " << strlen(tmp) << endl;
    cout << "sizeof: " << sizeof(tmp) << endl;
    memcpy(tmp, pStr + n, steps);
    memcpy(pStr + steps, pStr, n);
    memcpy(pStr, tmp, steps);
}

void loopMove(char* pStr, int steps)
{
    int n = strlen(pStr) - steps;
    char tmp[n + steps];
    strcpy(tmp, pStr + n);
    strcpy(tmp + steps, pStr);
    *(tmp + n + steps) = '\0';
    strcpy(pStr, tmp);
}

int main(int argc, char **argv)
{
    char src[] = "abcdefghi";
    cout << "origin src: " << src  << " sizeof: " << sizeof(src) << " strlen: " << strlen(src)<< endl;
    loopMoveStr(src, 2);
    cout << "after src: " << src  << " sizeof: " << sizeof(src) << " strlen: " << strlen(src)<< endl;
    loopMove(src, 3);
    cout << "after src: " << src  << " sizeof: " << sizeof(src) << " strlen: " << strlen(src)<< endl;
    return 0;
}
