/*
 * Author: L.F.N   File Name: mystrcpy.cpp
 * Created Time: 2018年06月09日 星期六 19时17分01秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

char* myStrcpy(char* strDest, const char* strSrc)
{
    assert(strDest != NULL && strSrc != NULL);
    char* ptr = strDest;
    while ('\0' != *strSrc)
    {
        *strDest++ = *strSrc++;
    }
    *strDest = '\0';
    return ptr;
}

int main(int argc, char **argv)
{
    char src[] = "i am boss! want you!";
    char dest[32];
    int srcLength = strlen(src);
    int destLength = strlen(myStrcpy(dest, src));
    cout << "src: " << src << " lenght: " << srcLength << " sizeof: " << sizeof(src) << endl;
    cout << "dest: " << dest << " lenght: " << destLength << " sizeof: " << sizeof(dest) << endl;

    return 0;
}
