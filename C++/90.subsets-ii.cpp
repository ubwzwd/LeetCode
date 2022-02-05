/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.size() == 0)
            return vector<vector<int>> {{}};
        // erase duplicate
        // sort first
        sort(nums.begin(), nums.end());
        // // using the unique function to put the duplicated element at the end of the vector, and return the position of the first duplicated element
        // vector<int>::iterator duplicate = unique(nums.begin(), nums.end());
        // // erase the duplicated element
        // nums.erase(duplicate, nums.end());

        vector<vector<int>> res {{}};
        vector<int> temp {};
        // use a set to store existing subsets, to avoid duplicates
        set<vector<int>> res_set;

        findSubsetRec(nums, 0, res, temp, res_set);

        return res;

    }

private:
    void findSubsetRec(vector<int>& nums, int position, vector<vector<int>>& res, vector<int>& temp, set<vector<int>>& res_set)
    {
        if (position >= nums.size())
            return;
        temp.push_back(nums[position]);
        if(res_set.find(temp) == res_set.end())
        {
            res.push_back(temp);
            res_set.insert(temp);
        }
        findSubsetRec(nums, position+1, res, temp, res_set);
        temp.pop_back();
        findSubsetRec(nums, position+1, res, temp, res_set);
    }
};

// int main()
// {
//     vector<int> nums {1,1,2,2};
//     Solution s;
//     vector<vector<int>> res = s.subsetsWithDup(nums);
//     cout<<res[7][0];
//     return 0;
// }

