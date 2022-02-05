/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Medium (32.90%)
 * Likes:    949
 * Dislikes: 399
 * Total Accepted:    208.3K
 * Total Submissions: 633.1K
 * Testcase Example:  '[2,5,6,0,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return true,
 * otherwise return false.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,5,6,0,0,1,2], target = 0
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,5,6,0,0,1,2], target = 3
 * Output: false
 * 
 * Follow up:
 * 
 * 
 * This is a follow up problem to Search in Rotated Sorted Array, where nums
 * may contain duplicates.
 * Would this affect the run-time complexity? How and why?
 * 
 * 
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        int left = 0, right = nums.size()-1;
        if(right == 0) return nums[0] == target;
        int mid = left+(right-left)/2;
        while(left < right){
            // avoid duplicate
            if(left<right && nums[left] == nums[left+1]){
                left++;
                continue;
            }
            if(right > left && nums[right] == nums[right-1]){
                right--;
                continue;
            }            
            mid = left+(right-left)/2;
            cout << mid << ' ' << nums[mid] << ' ' << target << endl;
            if(nums[mid] == target) return true;
            if((nums[mid] >= nums[left]) == (target >= nums[left])){
                // mid and target are in the same part
                if(nums[mid] < target) left = mid+1;
                else right = mid;
            }
            else{
                // mid and target are in the different part
                if(nums[mid] > target) left = mid+1;
                else right = mid;
            }            
        }
        return nums[left] == target;
    }
};
// @lc code=end

