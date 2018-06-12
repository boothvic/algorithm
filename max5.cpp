/*
 * Author: L.F.N   File Name: max5.cpp
 * Created Time: 2018年06月05日 星期二 17时33分20秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
using namespace std;

template <class T>
T max5(T* a)
{
    T max = 0;
    for (int i = 0; i < 5; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

int main(int argc, char **argv)
{
    cout << "start: \n";
    int a[5] = {1,2,3,4,5};
    cout << max5(a) << endl;
    double b[5] = {2.3, 4.3, 6.43, 1.23, 10.24};
    cout << max5(b) << endl;
    return 0;
}
