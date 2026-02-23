/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
  int subarraySumBruteForce(vector<int> &nums, int k) {
    vector<int> prefix(nums.size() + 1);
    for (int i = 1; i < prefix.size(); i++) {
      prefix[i] = prefix[i - 1] + nums[i - 1];
    }
    int count = 0;
    for (int left = 1; left < prefix.size(); left++) {
      for (int right = left; right < prefix.size(); right++) {

        int sum = prefix[right] - prefix[left - 1];
        if (sum == k)
          count++;
      }
    }
    return count;
  }
    int subarraySum(vector<int> &nums, int k) {
      vector<int> prefix(nums.size() + 1);
      for (int i = 1; i < prefix.size(); i++) {
        prefix[i] = prefix[i - 1] + nums[i - 1];
      }
      unordered_map<int, int> prefixCount;
      prefixCount[0] = 1;
      int count = 0;
      for (int i = 1; i < prefix.size(); i++) {
        count += prefixCount[prefix[i] - k];
        prefixCount[prefix[i]]++;
      }
      return count;
    }
};

// @lc code=end

