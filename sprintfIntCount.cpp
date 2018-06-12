/*
 * Author: L.F.N   File Name: sprintfIntCount.cpp
 * Created Time: 2018年06月09日 星期六 22时22分28秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void sprintfIntCount(const string & str)
{
    int len = str.size();
    int count = 1;
    char res[64];
    res[0] = '\0';
    int i;
    for (i = 0; i < len; i++)
    {
       if (str[i] == str[i+1]) 
       {
           count++;
       }
       else
       {
           sprintf(res + strlen(res), "%c%d", str[i],count);
           count = 1;
       }
    }

    if (str[i] == str[i-1])
    {
        count++;
    }
    else
    {
        count = 1;
    }
    sprintf(res + strlen(res), "%c%d", str[i], count);
    cout << res << endl;
}

int main(int argc, char **argv)
{
    cout << "Enter the string number: ";
    string strNum;
    getline(cin, strNum);
    string& str = strNum;
    sprintfIntCount(strNum);

    return 0;
}
