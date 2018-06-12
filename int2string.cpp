/*
 * Author: L.F.N   File Name: int2string.cpp
 * Created Time: 2018年06月09日 星期六 18时36分53秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
using namespace std;

void int2string(char*, int);
int string2int(char*);

void int2string(char* s, int num)
{
    while (num)
    {
        *s = num % 10 + '0';
        num /= 10;
        ++s;
    }
    *s = '\0';
}

int string2int(char* s)
{
    int res = 0;
    while (*s != '\0')
    {
        res = res * 10 + (*s - '0');
        ++s;
    }
    return res;
}

int main(int argc, char **argv)
{
    int x = 123456789;
    char str[16];
    int2string(str, x);
    cout << x << endl;
    char st[] = "123456";
    int y = string2int(st);
    cout << y << endl;
    return 0;
}
