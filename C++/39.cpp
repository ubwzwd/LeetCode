/*
Combinational Sum

Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

Example 2:
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {

        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res = dfs(candidates, target);
        return res;
    }

  private:
    vector<vector<int>> dfs(vector<int> candidate, int target)
    {
        vector<vector<int>> res;
        vector<int> temp;
        dfs_rec(candidate, target, res, temp);
        return res;
    }

    void dfs_rec(vector<int> candidate, int target, vector<vector<int>>& res, vector<int> temp)
    {
        if (target < 0)
            return;
        else if (target == 0)
        {
            res.push_back(temp);
            return;
        }
        else
        {
            for (int i = 0; i < candidate.size(); i++)
            {
                if (candidate[i] > target)
                    return;
                if (temp.size() == 0 || candidate[i] >= temp[temp.size() - 1])
                {
                    vector<int> temp2 = temp;
                    temp2.push_back(candidate[i]);
                    dfs_rec(candidate, target - candidate[i], res, temp2);
                }
            }
        }
        return;
    }
};

// ACCEPTED!