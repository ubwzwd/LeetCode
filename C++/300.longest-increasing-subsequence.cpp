/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // this is a special question
        // the traditional sub-structure is not working, that says, if we consider the longest subsequence at [i], there's no relation ship between [i] and [i+1]
        // This way, we choose the length of subsequence ending at [i] as the sub-structure
        // The consider [i+1]
        // Do loop j from 0 to i, if nums[j] < nums[i+1], dp[i+1] = max(dp[i+1], dp[j]+1)
        // the boundary condition is dp[0] = 1
        if (nums.size() == 0)
            return 0;
        int len = nums.size();
        int dp[len];
        for(int i = 0; i < len; i++)
        {
            dp[i] = 1;
        }
        int LIS = 1;
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j] && dp[i] <= dp[j])
                {
                    dp[i] = dp[j]+1;
                }
            }
            if (LIS < dp[i])
                LIS = dp[i];
        }
        return LIS;
    }
};

// int main()
// {
//     vector<int> nums {10,9,2,5,3,7,101,18};
//     Solution a;
//     int lis = a.lengthOfLIS(nums);
//     cout<< lis;
//     return 0;
// }

