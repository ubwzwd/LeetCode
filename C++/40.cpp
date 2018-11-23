/*
Combinational Sum II

Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.
Each number in candidates may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
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
        dfs_rec(candidate, target, 0, candidate.size() - 1, temp, res);
        return res;
    }

    void dfs_rec(vector<int> candidate, int target, int begin, int end, vector<int> temp, vector<vector<int>> &res)
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
            for (int i = begin; i < candidate.size(); i++)
            {
                if (candidate[i] > target)
                    return;
                if (i > begin && candidate[i] == candidate[i - 1])
                    continue;
                if (temp.size() == 0 || candidate[i] >= temp[temp.size() - 1])
                {
                    vector<int> temp2 = temp;
                    temp2.push_back(candidate[i]);
                    dfs_rec(candidate, target - candidate[i], i + 1, candidate.size() - 1, temp2, res);
                }
            }
        }
        return;
    }
};

// ACCEPTED!   8ms