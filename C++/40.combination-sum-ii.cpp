/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.size() == 0)
            return vector<vector<int>> {{}};
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        set<vector<int>> res_set;
        combinationSum2Rec(candidates, 0, target, res, temp, res_set);

        return res;
    }

private:
    void combinationSum2Rec(vector<int>& candidates, int position, int target, vector<vector<int>>& res, vector<int> temp, set<vector<int>>& res_set)
    {
        if(position >= candidates.size() || target < candidates[position])
            return;
        temp.push_back(candidates[position]);
        int new_target = target - candidates[position];
        if(new_target == 0)
        {
            if(res_set.find(temp) == res_set.end())
            {
                res.push_back(temp);
                res_set.insert(temp);
            }
            return;
        }
        else
        {
            combinationSum2Rec(candidates, position+1, new_target, res, temp, res_set);
            temp.pop_back();
            combinationSum2Rec(candidates, position+1, target, res, temp, res_set);
        }
        
    }
};

