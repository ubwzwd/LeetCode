/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */
#include <vector>
using namespace std;
class Solution {
public:

    // // time limit exceeded
    // vector<int> countSmaller(vector<int>& nums) {
    //     int len = nums.size();
    //     vector<int> res(len);
    //     for(int i=0; i<len; i++)
    //     {
    //         for(int j = i+1; j<len; j++)
    //         {
    //             if(nums[j] < nums[i])
    //                 res[i]++;
    //         }
    //     }
    //     return res;
    // }

    // using insert sort
    vector<int> countSmaller(vector<int>& nums)
    {   
        int len = nums.size();
        if(len == 0)
            return vector<int> {};
        vector<int> res(len);
        vector<int> temp{nums[len-1]};
        // begin from the last line
        for(int i = len-2; i>=0; i--)
        {
            int left = 0, right = temp.size();
            while(left < right)
            {
                int mid = left + (right-left)/2;
                if(temp[mid] >= nums[i])
                    right = mid;
                else left = mid+1;
            }
            res[i] = right;
            temp.insert(temp.begin()+right, nums[i]);
        }
        return res;
    }
};

