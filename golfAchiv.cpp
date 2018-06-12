/*
 * Author: L.F.N   File Name: golfAchiv.cpp
 * Created Time: 2018年06月05日 星期二 08时30分03秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
using namespace std;

void input(int*, int*);
void show(int*, int);
float average(int*, int);

int main(int argc, char **argv)
{
    int array[10] =  {0};
    int count = 0;
    input(array, &count);
    show(array, count);
    float av = average(array, count);
    cout << av  << endl;

    return 0;
}

void input(int *array, int* n)
{
    cout << "input: ";
    int i = 0;
    while((i < 10) && (cin >> array[i]))
    {
        if (array[i] == -1)
        {
            array[i] = 0;
            break;
        }
        i ++;
    }
    *n = i;
}

void show(int* array, int n)
{
    cout << "\nshow: \n";
    for (int i = 0; i < n; i ++)
    {
        cout << array[i] << "\t";
    }
}

float average(int* array, int n)
{
    cout << "\naverage:\n";
    int sum = 0;
    for (int i = 0; i < n; i ++)
    {
        sum += array[i];
    }
    
    return 1.0*sum/n;
}
