/*
 * @lc app=leetcode id=1984 lang=cpp
 *
 * [1984] Minimum Difference Between Highest and Lowest of K Scores
 */
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// @lc code=start
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
      sort(nums.begin(), nums.end());
      int minDiff = INT_MAX;
      for (int i = k - 1; i < nums.size(); i++) {
        minDiff = min(minDiff, nums[i] - nums[i - k + 1]);
      }
      return minDiff;
    }
};
// @lc code=end

