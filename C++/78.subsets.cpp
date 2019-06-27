/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */
#include <vector>
#include <algorithm>
using namespace std;


// backtracking
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res = {{}};

        if(nums.size() == 0)
            return res;

        vector<int> temp = {};

        Rec(0,temp, res, nums);

        return res;

    }

    void Rec(int n, vector<int>& temp, vector<vector<int>>& res, vector<int>& nums)
    {
        if(n >= nums.size())
            return;
        else
        {
            temp.push_back(nums[n]);
            res.push_back(temp);
            Rec(n+1, temp, res, nums);
            temp.pop_back();
            Rec(n+1, temp, res, nums);
        }
    }    
};

// // complete with bitwise operation.
// // treat the set as a integer. The first element is represented by b'0001, the second is b'0010
// // then the whole set of subsets is from 1 to 2^n
// // To find if each element exists in the i-th subset, just do the bitwise AND
// // 1<<nums[i] & i
// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         int len = nums.size();
//         if(len == 0)
//             return vector<vector<int>> {{}};
//         vector<vector<int>> res;
//         for(int i = 0; i < (1<<len); i++)
//         {
//             vector<int> temp {};
//             for(int j = 0; j < len; j++)
//             {
//                 if((1<<j)&i)
//                     temp.push_back(nums[j]);
//             }
//             res.push_back(temp);
//         }
//         return res;
//     }    
// };

