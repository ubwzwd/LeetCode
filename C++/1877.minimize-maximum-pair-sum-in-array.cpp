/*
 * @lc app=leetcode id=1877 lang=cpp
 *
 * [1877] Minimize Maximum Pair Sum in Array
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int minPairSum(vector<int>& nums) {
      sort(nums.begin(), nums.end());

      int maxSum = 0;
      int n = nums.size();
      for (int i = 0; i < n / 2; i++) {
        maxSum = max(maxSum, nums[i] + nums[n-i-1]);
      }
      return maxSum;
    }
};
// @lc code=end

