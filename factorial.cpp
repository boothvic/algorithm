/*
 * Author: L.F.N   File Name: factorial.cpp
 * Created Time: 2018年06月05日 星期二 09时47分08秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
using namespace std;

int factorial(int);

int main(int argc, char **argv)
{
    int n;
    cout << "input n: ";
    //cin >> n;
    //while (n >= 0)
    //{
    //    int ret = factorial(n);
    //    cout << n << "! = " << ret << endl;
    //    cout << "input n: ";
    //    cin >> n;
    //}
    while (cin >> n)
    {
        if (n >= 0)
        {
            int ret = factorial(n);
            cout << n << "! = " << ret << endl;
        }
        else
            break;
    }
    return 0;
}

int factorial(int n)
{
    int fac = 1;
    if (n ==0 || n ==1)
        return fac;
    fac = n * factorial(n-1);
    return fac;
}
