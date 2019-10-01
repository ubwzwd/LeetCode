/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 *
 * https://leetcode.com/problems/binary-search/description/
 *
 * algorithms
 * Easy (49.35%)
 * Likes:    325
 * Dislikes: 34
 * Total Accepted:    70.5K
 * Total Submissions: 142.9K
 * Testcase Example:  '[-1,0,3,5,9,12]\n9'
 *
 * Given a sorted (in ascending order) integer array nums of n elements and a
 * target value, write a function to search target in nums. If target exists,
 * then return its index, otherwise return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-1,0,3,5,9,12], target = 9
 * Output: 4
 * Explanation: 9 exists in nums and its index is 4
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [-1,0,3,5,9,12], target = 2
 * Output: -1
 * Explanation: 2 does not exist in nums so return -1
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * You may assume that all elements in nums are unique.
 * n will be in the range [1, 10000].
 * The value of each element in nums will be in the range [-9999, 9999].
 * 
 * 
 */
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0, end = nums.size()-1;
        int mid = 0;
        while(begin <= end){
            mid = (begin+end)>>1;
            if(target == nums[mid]) return mid;
            else if(target > nums[mid]){
                begin = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return -1;
    }
};

