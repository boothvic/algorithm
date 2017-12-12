/*
 * Author: Vic Lin   File Name: reverse.cpp
 * Created Time: 2017年12月12日 星期二 20时04分29秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
using namespace std;

class Solution
{
public:
    int reverse(int x) {
        int ans = 0;
        while (x) {
            ans = x % 10 + ans * 10;
            x /= 10;
        }
        return ans;
    }

};

int main(int argc, char **argv)
{
    Solution s;
    int num; 
    cout << "Enter an integer: ";
    cin >> num;
    int res = s.reverse(num);
    cout << res << endl;
    return 0;
}
