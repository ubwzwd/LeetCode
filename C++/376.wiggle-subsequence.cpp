/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> def {};
        if (nums.size() == 1)
            return 1;
        else if(nums.size()==0)
            return 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i-1]>nums[i])
                def.push_back(-1);
            else if (nums[i-1] < nums[i])
                def.push_back(1);
            else
                def.push_back(0);
        }
        int flag = 0;
        int len = 1;
        for (auto a : def)
        {
            if(a==flag || a==0)
                continue;
            else
            {
                flag = a;
                len++;
            }
        }
        return len;
    }
};


// int main()
// {
//     vector<int> v = {1,7,4,9,2,5};
//     Solution s;
//     int res = s.wiggleMaxLength(v);
//     cout<<res;
//     return 0;
// }
