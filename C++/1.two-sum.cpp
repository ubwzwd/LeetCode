/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
#include <unordered_map>
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> sumMap; // target - nums[i] -> i map
        for (int i = 0; i < nums.size(); i++) {
            if (sumMap.count(nums[i])) {
                int j = sumMap[nums[i]];
                if (i != j){
                    return vector<int> {i, j};
                }
            }
            sumMap[target - nums[i]] = i;
        }
        return vector<int>{-1, -1};
    }
};
// @lc code=end

