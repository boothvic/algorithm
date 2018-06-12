/*
 * Author: L.F.N   File Name: maxn.cpp
 * Created Time: 2018年06月05日 星期二 18时09分45秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
using namespace std;

template <class T>
T maxn(T* a, int n)
{
    T max = 0;
    int f = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
            f = i;
        }
    }
    return a[f];
}

template <> char maxn(char* a, int n);

int main(int argc, char **argv)
{
    int a[6] = {10,9,8,7,6,6};
    cout << maxn(a, 6) << endl;
    double b[4] = {1, 2.3, 4.5, 6.6};
    cout << maxn(b, 4) << endl;
    char* p[3] = {"a", "b", "c"};
    cout << maxn(p, 3) << endl;
    return 0;
}
