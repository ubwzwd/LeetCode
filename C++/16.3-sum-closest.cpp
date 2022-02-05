/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.75%)
 * Likes:    1465
 * Dislikes: 107
 * Total Accepted:    399K
 * Total Submissions: 873.1K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int len = nums.size();
        if (len < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int res = INT_MIN, diff = INT_MAX;
        int l = 1, r = len - 1;
        for (int i = 0; i < len - 2; i++)
        {
            l = i + 1;
            r = len - 1;
            while (l < r)
            {
                if (abs(nums[i] + nums[l] + nums[r] - target) < diff)
                {
                    diff = abs(nums[i] + nums[l] + nums[r] - target);
                    res = nums[i] + nums[l] + nums[r];
                }
                if (nums[i] + nums[l] + nums[r] > target)
                    r--;
                else if (nums[i] + nums[l] + nums[r] < target)
                    l++;
                else
                    return target;
            }
        }
        return res;
    }
};
// @lc code=end
