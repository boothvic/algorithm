/*
 * Author: L.F.N   File Name: Rand1MNUM.cpp
 * Created Time: 2018年06月11日 星期一 16时59分20秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
#include <time.h>
#include <fstream>
#include <cstdlib>
using namespace std;

const char* file = "/home/drlin/Exp/algorithm/out.txt";
bool out2file(int arr[])
{
    ofstream fout(file,ios_base::out | ios_base::trunc);
    if (!fout.is_open())
    {
        cout << "Can't open " << file << " file for output.\n";
        return false;
    }
    for (int i = 0; i < 1000000;)
    {
        fout << arr[i] << "\t";
        ++i;
        if (i%20 == 0)
            fout << endl;
    }
    fout.close();
    return true;
}

int main(int argc, char **argv)
{
    clock_t start = clock();
    int* arr = new int[1000000]; 
    
    srand((unsigned)time(0));
    for (int i = 0; i < 1000000; ++i)
    {
        arr[i] = rand()%1000;
    }
    if (!(out2file(arr)))
        cout << "Output file error!\n";
    clock_t end = clock();
    cout << (double)(end - start)/CLOCKS_PER_SEC << endl;
    return 0;
}
