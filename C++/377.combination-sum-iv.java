/*
 * @lc app=leetcode id=377 lang=java
 *
 * [377] Combination Sum IV
 *
 * https://leetcode.com/problems/combination-sum-iv/description/
 *
 * algorithms
 * Medium (43.96%)
 * Likes:    972
 * Dislikes: 116
 * Total Accepted:    98K
 * Total Submissions: 222.5K
 * Testcase Example:  '[1,2,3]\n4'
 *
 * Given an integer array with all positive numbers and no duplicates, find the
 * number of possible combinations that add up to a positive integer target.
 * 
 * Example:
 * 
 * 
 * nums = [1, 2, 3]
 * target = 4
 * 
 * The possible combination ways are:
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 * 
 * Note that different sequences are counted as different combinations.
 * 
 * Therefore the output is 7.
 * 
 * 
 * 
 * 
 * Follow up:
 * What if negative numbers are allowed in the given array?
 * How does it change the problem?
 * What limitation we need to add to the question to allow negative numbers?
 * 
 * Credits:
 * Special thanks to @pbrother for adding this problem and creating all test
 * cases.
 * 
 */

import java.util.*;

// @lc code=start
class Solution {
    private int[] dp;

    public int combinationSum4(int[] nums, int target) {
        dp = new int[target+1];
        Arrays.fill(dp, -1);
        dp[0] = 1;
        return combinationSum4Rec(nums, target);
    }

    private int combinationSum4Rec(int[] nums, int target){
        if(dp[target] != -1){
            return dp[target];
        }
        // from top to down
        int res = 0;
        for(int i = 0; i < nums.length; i++){
            if(target >= nums[i]){
                res += combinationSum4Rec(nums, target - nums[i]);
            }
        }
        dp[target] = res;
        return res;
    }
}
// @lc code=end

