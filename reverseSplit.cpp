/*
 * Author: L.F.N   File Name: reverseSplit.cpp
 * Created Time: 2018年06月09日 星期六 22时45分44秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void reverseSplit(string& str)
{
    int len = str.size();
    char res[len+1];
    int i = 0;
    while (len-- > 0)
    {
        res[i++] = str[len];
    }
    res[i] = '\0';
    cout << res << endl;

    //word recovery
    int j = 0;
    int begin, end;
    while(res[j] != '\0')
    {
        if (res[j] != ' ')
        {
            begin = j;
            while (res[j] && res[j] != ' ')
            {
                j++;
            }
            end = j - 1;
        }

        char ch;
        while (end > begin)
        {
            ch = res[begin];
            res[begin] = res[end];
            res[end] = ch;
            end--;
            begin++;
        }
        j++;
    }
    
    cout << "finish: " << res << endl;
}

int main(int argc, char **argv)
{ 
    cout << "Enter str: ";
    string str;
    getline(cin, str);
    string& st = str;
    reverseSplit(st);

    return 0;
}
