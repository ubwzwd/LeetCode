/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 *
 * https://leetcode.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (63.11%)
 * Likes:    188
 * Dislikes: 149
 * Total Accepted:    34.6K
 * Total Submissions: 55.1K
 * Testcase Example:  '[5,2,3,1]'
 *
 * Given an array of integers nums, sort the array in ascending order.
 * 
 * 
 * Example 1:
 * Input: nums = [5,2,3,1]
 * Output: [1,2,3,5]
 * Example 2:
 * Input: nums = [5,1,1,2,0,0]
 * Output: [0,0,1,1,2,5]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 50000
 * -50000 <= nums[i] <= 50000
 * 
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
// class Solution {
//     void swap(int& a, int& b){
//         int c = a;
//         a = b;
//         b = c;
//     }

//     void quickSort(vector<int>& nums, int first, int last){
//         if(first >= last) return;
//         int p = first;
//         int pivot = nums[last];
//         for(int i = first; i < last; i++){
//             if(nums[i] < pivot){
//                 swap(nums[i], nums[p]);
//                 p++;
//             }
//         }
//         swap(nums[p], nums[last]);
//         quickSort(nums, first, p-1);
//         quickSort(nums,p+1, last);
//     }

// public:
//     vector<int> sortArray(vector<int>& nums) {
//         // sort(nums.begin(), nums.end());
//         if(nums.empty()) return nums;
//         // implement quick sort
//         quickSort(nums,0,nums.size()-1);
//         return nums;
//     }
// };

class Solution {
    // merge sort
public:
    vector<int> sortArray(vector<int>& nums) {
        if(nums.empty()) return {};
        
    }
};
// @lc code=end

