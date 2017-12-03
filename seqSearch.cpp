/*
 * Author: Vic Lin   File Name: seqSearch.cpp
 * Created Time: 2017年10月13日 星期五 09时01分35秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
#include <random>
using namespace std;

int seqSearch(const int arr[], int first, int last, int target);

int main(int argc, char **argv)
{
    int arr[15];
    int i, index;
    cout << "Original array" << endl;
    for (i = 0; i < 15; i++){
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    index = seqSearch(arr, 0, 15, 88);
    cout << index;
    cout << endl;
    return 0;
}

int seqSearch(const int arr[], int first, int last, int target)
{
    int i = first;
    // first <= i < last
    while (i != last && arr[i] != target)
        ++i;
    return i; //若匹配返回i, 否则 返回i = last
}
