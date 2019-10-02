/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (42.32%)
 * Likes:    1260
 * Dislikes: 46
 * Total Accepted:    275.3K
 * Total Submissions: 650.5K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size() == 0) return vector<vector<int>> {};
        vector<vector<int>> res;
        vector<int> temp;
        vector<int> temp_index;
        permuteUniqueRec(nums, res, temp, temp_index);
        return res;
    }

    void permuteUniqueRec(vector<int>& nums, vector<vector<int>>& res, vector<int>& temp, vector<int>& temp_index){
        if(temp.size() == nums.size()){
            if(find(res.begin(), res.end(), temp) == res.end())
                res.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(find(temp_index.begin(), temp_index.end(), i) == temp_index.end()){
                temp.push_back(nums[i]);
                temp_index.push_back(i);
                permuteUniqueRec(nums, res, temp, temp_index);
                temp.pop_back();
                temp_index.pop_back();
            }
        }
        return;
    }
};

