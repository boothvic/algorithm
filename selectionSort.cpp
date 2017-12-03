/*
 * Author: Vic Lin   File Name: selectionSort.cpp
 * Created Time: 2017年10月13日 星期五 08时33分00秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
#include <random>

using namespace std;

void selectionSort(int arr[], int n);

int main(int argc, char **argv)
{
    int arr[15];
    int i;
    cout << "Original array" << endl;
    for (i = 0; i < 15; i++){
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    selectionSort(arr, 15);
    cout << "Sorted array" << endl;
    for (i = 0; i < 15; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

void selectionSort(int arr[], int n)
{
    int smallIndex; // 最小元素的下标
    int pass, j;
    int temp;

    // pass: 0~n-2
    for (pass = 0; pass < n-1; pass++){
        // 从下标pass开始扫描
        smallIndex = pass;
        // j遍历arr[pass+1] ~ arr[n-1]
        for (j = pass + 1; j < n; j++){
            //如果找到更小的元素，将该位置赋值给smallIndex
            if (arr[j] < arr[smallIndex])
                smallIndex = j;
        }
        //若smallIndex和pass不在同一位置，交换最小项arr[pass]
        if (smallIndex != pass){
            temp = arr[pass];
            arr[pass] = arr[smallIndex];
            arr[smallIndex] = temp;
        }
    }
}
