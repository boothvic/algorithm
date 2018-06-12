/*
 * Author: L.F.N   File Name: mystrstr.cpp
 * Created Time: 2018年06月09日 星期六 23时56分52秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
using namespace std;

const char* mystrstr(const char* str, const char* strSet)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        int j = 0;
        int tmp = i;
        if (str[i] == strSet[j])
        {
            while (str[i++] == strSet[j++])
            {
                if (strSet[j] == '\0')
                {
                    return &str[i-j];
                }
            }
            i = tmp;
        }
    }
    return NULL;
}

int main(int argc, char **argv)
{
    char str[] = "1234568883344508";
    cout << "str: " << str << endl;
    cout << "Enter strSet: ";
    char strSet[16];
    cin >> strSet;
    cout << "strSet: " << strSet << endl;
    cout << "after strSet: " << mystrstr(str, strSet) << endl; 
    return 0;
}
