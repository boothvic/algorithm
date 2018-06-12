/*
 * Author: L.F.N   File Name: bit3.cpp
 * Created Time: 2018年06月09日 星期六 12时36分06秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
#define BIT3 (0x1 << 3) //1 向左移动３位, *8
using namespace std;


int main(int argc, char **argv)
{
    int a = 0x0000ffff;
    cout << (a |= BIT3) << endl;
    cout << (a &= ~BIT3) << endl;
    int z = 3;
    z = z | BIT3;
    cout << z << endl;
    return 0;
}
