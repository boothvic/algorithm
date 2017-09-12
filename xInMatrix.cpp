/*
 * Author: Vic Lin   File Name: isElementInMatrix.cpp
 * Created Time: 2017年09月11日 星期一 16时04分40秒
 *
 * Cpp source code - replace this with a description
 * of the code and write the code below this text
 *
 */


#include <iostream>
using namespace std;

const int N = 3;
const int M = 3;

bool findElement(int ** matrix,int n, int m, int element)
{
    bool found = false;

    int i, j;
    i = n -1;
    j = m -1;
    while (i >= 0, j >= 0){
        if (element == *((int*)matrix+i*n+j)){
            found = true;
            break;
        }
        else if (element > *((int*)matrix+i*n+j))
            --i;
        else
            --j;
    }
    return found;
}

bool findValue(int (*matrix)[M],int n, int element)
{
    bool found = false;

    int i, j;
    i = n -1;
    j = M -1;
    while (i >= 0, j >= 0){
        if (element == matrix[i][j]){
            found = true;
            break;
        }
        else if (element > matrix[i][j])
            --i;
        else
            --j;
    }
    return found;
}

int main(int argc, char * argv[])
{
    int matrixA[][M] = {5,13,20,3,6,15,2,4,7};
    cout << findElement((int **)matrixA,N,M,5) << endl;
    cout << findValue(matrixA,N,22) << endl;
    return 0;
}
