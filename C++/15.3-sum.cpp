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
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
private:
    void threeSumRec(vector<int>& nums, int i, vector<int> temp, vector<vector<int>>& res){
        if(i >= nums.size() || temp.size() >= 3) return;
        temp.push_back(nums[i]);
        int j = i+1;
        if(temp.size()==3 && temp[0]+temp[1]+temp[2] == 0){
            res.push_back(temp);
            while(j < nums.size() && nums[j] == nums[i]) j++;
        }
        for(j; j < nums.size(); j++){
            threeSumRec(nums, j, temp, res);
        }
    }

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        if(len<3) return vector<vector<int>> {};
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> res;
        for(int i = 0; i < len-2; i++){
            int l = i+1, r = len-1;
            while(l < r){
                if(nums[i] + nums[l] + nums[r] < 0) l++;
                else if(nums[i] + nums[l] + nums[r] > 0)    r--;
                else{
                    // == 0
                    res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l < r && nums[l] == nums[l-1]) l++;
                    while(l < r && nums[r] == nums[r+1]) r--;
                }
            }
            while(i < len-2 && nums[i] == nums[i+1]) i++;
        }
        return res;
    }
};
// @lc code=end

