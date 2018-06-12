/*
 * Author: L.F.N   File Name: sort1mint.cpp
 * Created Time: 2018年06月12日 星期二 14时07分35秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

const char* file = "/home/drlin/Exp/algorithm/out.txt";
const char* sortfile = "/home/drlin/Exp/algorithm/in.txt";
const int count = 1000000;

int* getIntFormFile(const char* file);
bool out2file(int a[], const char* file);
bool selectsort(int a[], int n);
bool bubblesort(int a[], int n);
bool quicksort(int* low, int* high);
int* partition(int* low, int* high);

int main(int argc, char **argv)
{
    int* a = getIntFormFile(file);

    //bubblesort()
    clock_t begin = clock();
    if (!bubblesort(a+100000, 100000))
    {
        cout << "sort failure.\n";
    }
    clock_t finish = clock();
    cout << "bubblesort run time: " << (double)(finish-begin)/CLOCKS_PER_SEC << "s.\n";

    //selectsort()
    clock_t start = clock();
    if (!selectsort(a+200000, 100000))
    {
        cout << "sort failure.\n";
    }
    clock_t end = clock();
    cout << "selectsort run time: " << (double)(end-start)/CLOCKS_PER_SEC << "s.\n";

    //quicksort()
    clock_t begintime = clock();
    if (!quicksort(a, a+100000))
    {
        cout << "sort failure.\n";
    }
    clock_t finishtime = clock();
    cout << "quicksort run time: " << (double)(finishtime-begintime)/CLOCKS_PER_SEC << "s.\n";

    if (out2file(a, sortfile))
    {
        cout << "Out put successed.\n";
    }
    delete[] a;
    return 0;
}

int* getIntFormFile(const char* file)
{
    ifstream fin;
    fin.open(file);
    if (!fin.is_open())
    {
        cout << "Open " << file << " file failure!\n";
    }
    
    int* a = new int[count];
    int i = 0;
    while (!fin.eof())
    {
        fin >> a[i];
        ++i;
    }
    fin.close();

    return a; 
}

bool out2file(int a[], const char* file)
{
    ofstream fout(file,ios_base::out | ios_base::trunc);
    if (!fout.is_open())
    {
        cout << "Can't open " << file << " file for output.\n";
        return false;
    }
    for (int i = 0; i < count;)
    {
        fout << a[i] << "\t";
        ++i;
        if (i%20 == 0)
            fout << endl;
    }
    fout.close();
    return true;
}

bool selectsort(int a[], int n)
{
    int temp;
    int index;
    for (int i = 0; i < n - 1; ++i)
    {
        index = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] < a[index])
                index = j;
        }

        if (index != i)
        {
            temp = a[i];
            a[i] = a[index];
            a[index] = temp;
        }
    }

    return true;
}

bool bubblesort(int a[], int n)
{
    int temp;
    int i;
    bool change;
    for (i = n -1, change = true; i >= 1 && change; --i)
    {
        change = false;
        for (int j = 0; j < i; ++j)
        {
            if (a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] =  temp;
                change = true; 
            }
        }
    }

    return true;
}

//quicksort
int* partition(int* low, int* high)
{
    int pivotkey = *low;
    int swap;
    while (low < high)
    {
        while (low < high && *high >= pivotkey)
            --high;
        *low = *high;
        while (low < high && *low <= pivotkey)
            ++low;
        *high = *low;
    }
    *low = pivotkey;

    return low;
}

bool quicksort(int* low, int* high)
{
    if (low < high)
    {
        int* pivotloc = partition(low, high);
        quicksort(low, pivotloc-1);
        quicksort(pivotloc+1, high);
    }
    return  true;
}
