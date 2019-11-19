/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.85%)
 * Likes:    4890
 * Dislikes: 583
 * Total Accepted:    701.9K
 * Total Submissions: 2.8M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
    void threeSumRec(vector<int>& nums, int i, vector<int>& temp, vector<vector<int>>& res){
        if(i >= nums.size() || temp.size() >= 3) return;
        temp.push_back(nums[i]);
        if(temp.size()==3 && temp[0]+temp[1]+temp[2] == 0){
            res.push_back(temp);
            temp.pop_back();
        }
        threeSumRec(nums, i+1, temp, res);
        temp.pop_back();
    }

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        if(len<3) return vector<vector<int>> {};
        vector<int> temp;
        vector<vector<int>> res;
        threeSumRec(nums, 0, temp, res);
        return res;
    }
};
// @lc code=end

