/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (55.15%)
 * Likes:    2412
 * Dislikes: 200
 * Total Accepted:    500.1K
 * Total Submissions: 897.8K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;
// @lc code=start
class Solution {
    int count(int num, vector<int>& nums, int left, int right){
        int res = 0;
        for(int i = left; i < right; i++){
            if(nums[i] == num) res++;
        }
        return res;
    }
    // [left, right)
    int majorityElementRec(vector<int>& nums, int left, int right){
        if(right-left == 1) return nums[left];
        int mid = left+(right-left)/2;
        int leftRes = majorityElementRec(nums, left, mid);
        int rightRes = majorityElementRec(nums, mid, right);
        if(leftRes == rightRes) return leftRes;
        int leftCount = count(leftRes, nums, left, right);
        int rightCount = count(rightRes, nums, left, right);
        return leftCount>rightCount? leftRes : rightRes;
    }
public:
    int majorityElement(vector<int>& nums) {
        return majorityElementRec(nums, 0, nums.size());
    }
};
// @lc code=end

