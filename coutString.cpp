/*
 * Author: L.F.N   File Name: coutString.cpp
 * Created Time: 2018年06月05日 星期二 10时22分26秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
using namespace std;

void coutString(char*);
void coutStr(char* , int);

int co = 0;

int main(int argc, char **argv)
{
    char* s = "I am my boss!";
    //cout << static_cast<void*>(&s) << endl;
    //coutString(s);
    cout << "\n0: ";
    co++;
    coutStr(s, 0); 
    cout << "\n1: ";
    co++;
    coutStr(s, 1);
    cout << "\n4: ";
    co++;
    coutStr(s, 4);
    cout << endl;
    return 0;
}

void coutString(char* str)
{
    //while (*str != '\0')
    //{
    //    cout << *str;
    //    str++;
    //}
    cout << endl;
    for (;*str != '\0';str++)
        cout << *str;
}

void coutStr(char* str , int n)
{
    if (n == 0)
        coutString(str);
    else
    {
        int n = co;
        while (n-- > 0)
            coutString(str);
    }
}
