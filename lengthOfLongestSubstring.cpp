/*
 * Author: Vic Lin   File Name: lengthOfLongestSubstring.cpp
 * Created Time: 2017年12月11日 星期一 20时19分47秒
 * Github: https://github.com/boothvic
 *
 * Code description
 *
 */


#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, left = 0;
        map<char, int> mp;
        map<char, int>::iterator it;
        for (int i = 0; i < s.size(); i++) {
            it = mp.find(s[i]);
            if (it != mp.end())
                left = max(left, mp.at(s[i]) + 1);
            ans = max(ans, i-left+1);
            mp[s[i]] = i;
        }
        return ans;
    }
};

int main(int argc, char **argv)
{
    string str = "pwwkew";
    Solution s;
    int res = s.lengthOfLongestSubstring(str);
    cout << res << endl;
    return 0;
}
