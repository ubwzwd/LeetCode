/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> countSmaller(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return vector<int> {};
        vector<int> res(len, 0);
        vector<pair<int, int>> nums_index;
        for(int i=0; i < len; i++)
            nums_index.push_back(make_pair(nums[i], i));
        mergeCountSmaller(nums_index, 0, len, res);
        return res;
    }

private:
    void mergeCountSmaller(vector<pair<int, int>>& nums_index, int start, int end, vector<int>& res)
    {
        if(end - start <= 0)
            return;
        int mid = (end - start)/2 + start;
        int left = start;
        int right = mid;
        mergeCountSmaller(nums_index, start, mid, res);
        mergeCountSmaller(nums_index, mid, end, res);
        for(int i = start; i < mid; i++)
        {
            while(nums_index[right].first < nums_index[i].first && right <= end)
                right++;
            res[nums_index[i].second]+= right - mid;
        }
        inplace_merge(nums_index.begin()+start, nums_index.begin()+mid, nums_index.begin()+end);
    }
};