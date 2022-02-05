/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (35.70%)
 * Likes:    1494
 * Dislikes: 82
 * Total Accepted:    208.4K
 * Total Submissions: 578.7K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of n positive integers and a positive integer s, find the
 * minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
 * one, return 0 instead.
 * 
 * Example: 
 * 
 * 
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: the subarray [4,3] has the minimal length under the problem
 * constraint.
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution of
 * which the time complexity is O(n log n). 
 * 
 */
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        if(!len) return 0;
        int res_len = INT_MAX, temp_val = 0;
        int l = 0, r = 0;
        while(r < len){
            temp_val+=nums[r];
            if(temp_val >= s){
                while(temp_val-nums[l] >= s){
                    temp_val-=nums[l];
                    l++;
                }
                res_len = min(res_len, r-l+1);
            }
            r++;
        }
        return (res_len==INT_MAX)? 0 : res_len;
    }
};
// @lc code=end

