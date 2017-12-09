/*
 * Author: Vic Lin   File Name: twoSum.cpp
 * Created Time: 2017年12月03日 星期日 14时47分23秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> vi;

public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i=0; i < nums.size(); i++)
            for (int j=i+1; j < nums.size(); j++)
                if (nums[i]+nums[j] == target) {
                    vi.push_back(i);
                    vi.push_back(j);
                }
        return vi;
    }
};


int main(int argc, char **argv)
{
    int a[] = {2, 5, 7, 9, 13};
    vector<int> arr;
    for (int i = 0; i < 5; i++){
        arr.push_back(a[i]);
        cout << arr[i] <<endl;
    }
    Solution s;
    vector<int> t = s.twoSum(arr, 9);
    for (int i = 0; i < t.size(); i++)
        cout << t[i] << "\t";

    return 0;
}
