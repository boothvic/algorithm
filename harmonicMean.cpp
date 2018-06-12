/*
 * Author: L.F.N   File Name: harmonicMean.cpp
 * Created Time: 2018年06月05日 星期二 08时05分22秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
using namespace std;

float harmonicMean(float, float);

int main(int argc, char **argv)
{
    cout << "input: ";
    float a, b;
    cin >> a >> b;
    while ((a !=0) && (b !=0))
    {
        float result = harmonicMean(a, b);
        cout << "output: " << result << endl;
        cout << "input: ";
        cin >> a >> b;
    }

    return 0;
}

float harmonicMean(float x, float y)
{
    return 2.0*x*y/(x+y);
}
