/*
 * @lc app=leetcode id=280 lang=cpp
 *
 * [280] Wiggle Sort
 *
 * https://leetcode.com/problems/wiggle-sort/description/
 *
 * algorithms
 * Medium (61.75%)
 * Likes:    478
 * Dislikes: 49
 * Total Accepted:    74.1K
 * Total Submissions: 119.5K
 * Testcase Example:  '[3,5,2,1,6,4]'
 *
 * Given an unsorted array nums, reorder it in-place such that nums[0] <=
 * nums[1] >= nums[2] <= nums[3]....
 * 
 * Example:
 * 
 * 
 * Input: nums = [3,5,2,1,6,4]
 * Output: One possible answer is [3,5,1,6,2,4]
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
    void swap(int& a, int& b){
        int c = a;
        a = b;
        b = c;
    }

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
//     void wiggleSort(vector<int>& nums) {
//         if(nums.size() <= 1) return;
//         quickSort(nums, 0, nums.size()-1);
//         int i = 1;
//         if(nums.size() >= 3){
//             while(i<nums.size()-1){
//                 swap(nums[i], nums[i+1]);
//                 i += 2;
//             }
//         }
//     }

public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size()<=1) return;
        for(int i = 0; i < nums.size()-1; i++){
            if((i%2==0 && nums[i]>nums[i+1]) || (i%2==1 && nums[i]<nums[i+1]))
                swap(nums[i], nums[i+1]);
        }
    }
};
// @lc code=end

