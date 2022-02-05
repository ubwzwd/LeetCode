/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 *
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
 *
 * algorithms
 * Hard (38.86%)
 * Likes:    1276
 * Dislikes: 59
 * Total Accepted:    83.8K
 * Total Submissions: 215.6K
 * Testcase Example:  '[5,2,6,1]'
 *
 * You are given an integer array nums and you have to return a new counts
 * array. The counts array has the property where counts[i] is the number of
 * smaller elements to the right of nums[i].
 * 
 * Example:
 * 
 * 
 * Input: [5,2,6,1]
 * Output: [2,1,1,0] 
 * Explanation:
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    // [start, stop], [start, mid], [mid+1, stop]
    void mergeCountSmaller(vector<pair<int, int>> &nums_index, int start, int stop, vector<int> &res)
    {
        if (stop == start)
            return;
        int mid = (stop - start) / 2 + start;
        int right = mid+1, left = start;
        int temp_cur = 0;
        mergeCountSmaller(nums_index, start, mid, res);
        mergeCountSmaller(nums_index, mid+1, stop, res);
        vector<pair<int,int>> temp(stop-start+1);
        while(left <= mid || right <= stop)
        {
            // if nums_index[left].first == nums_index[right].first, it shouldn't take into count
            if(left> mid || (right <= stop && nums_index[left].first > nums_index[right].first))
            {
                temp[temp_cur] = nums_index[right];
                right++;
                temp_cur++;
            }
            else
            {
                temp[temp_cur] = nums_index[left];
                res[nums_index[left].second] += right - mid - 1;
                left++;
                temp_cur++;
            }
        }
        // inplace_merge(nums_index.begin() + start, nums_index.begin() + mid, nums_index.begin() + end);
        for(int i = start; i <= stop; i++)
        {
            nums_index[i] = temp[i-start];
        }
    }

public:
    vector<int> countSmaller(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 0)
            return vector<int>{};
        vector<int> res(len, 0);
        vector<pair<int, int>> nums_index;
        for (int i = 0; i < len; i++)
            nums_index.push_back(make_pair(nums[i], i));
        mergeCountSmaller(nums_index, 0, len-1, res);
        return res;
    }
};
