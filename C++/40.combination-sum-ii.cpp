/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (43.59%)
 * Likes:    1077
 * Dislikes: 50
 * Total Accepted:    251.8K
 * Total Submissions: 577.7K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
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
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.size() == 0) return vector<vector<int>> {};
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        combinationSum2Rec(candidates, target, 0, 0, res, temp);
        return res;
    }

    void combinationSum2Rec(vector<int>& candidates, int target, int sum, int index, vector<vector<int>>& res, vector<int>& temp){
        // sum += candidates[index];
        if(sum > target){
            return;
        }
        else if(sum == target){
            res.push_back(temp);
            return;
        }
        else{
            for(int i = index; i < candidates.size(); i++){
                // *************remove the following duplicates**************
                if(i > index && candidates[i] == candidates[i-1]) continue;
                if(candidates[i] + sum > target) return;
                temp.push_back(candidates[i]);
                combinationSum2Rec(candidates, target, sum + candidates[i], i+1, res, temp);
                temp.pop_back();
            }
        }
        return;
    }
};

