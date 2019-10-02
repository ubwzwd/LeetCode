/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (57.60%)
 * Likes:    2462
 * Dislikes: 78
 * Total Accepted:    440.4K
 * Total Submissions: 764.6K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0) return vector<vector<int>>{};
        vector<vector<int>> res;
        vector<int> temp;
        permuteRec(nums, res, temp);
        return res;
    }

    void permuteRec(vector<int>& nums, vector<vector<int>>& res, vector<int>& temp){
        if(temp.size() == nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(find(temp.begin(), temp.end(), nums[i]) == temp.end()){
                temp.push_back(nums[i]);
                permuteRec(nums, res, temp);
                temp.pop_back();
            }
        }
        return;
    }
};

