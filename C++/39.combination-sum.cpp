/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (50.87%)
 * Likes:    2463
 * Dislikes: 74
 * Total Accepted:    398.7K
 * Total Submissions: 783.7K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size() == 0) return vector<vector<int>> {};
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        combinationSumRec(candidates, target, 0, 0, res, temp);
        return res;
    }

    void combinationSumRec(vector<int>& candidates, int target, int sum, int index, vector<vector<int>>& res, vector<int>& temp){
        if(sum > target){
            return;
        }
        else if(sum == target){
            res.push_back(temp);
            return;
        }
        else{
            for(int i = index; i < candidates.size(); i++){
                if(candidates[i] + sum > target) return;
                temp.push_back(candidates[i]);
                combinationSumRec(candidates, target, sum + candidates[i], i, res, temp);
                temp.pop_back();
            }
        }
        return;
    }
};

