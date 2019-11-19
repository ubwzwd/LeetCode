/*
 * @lc app=leetcode id=324 lang=cpp
 *
 * [324] Wiggle Sort II
 *
 * https://leetcode.com/problems/wiggle-sort-ii/description/
 *
 * algorithms
 * Medium (28.53%)
 * Likes:    764
 * Dislikes: 428
 * Total Accepted:    69.8K
 * Total Submissions: 242.2K
 * Testcase Example:  '[1,5,1,1,6,4]'
 *
 * Given an unsorted array nums, reorder it such that nums[0] < nums[1] >
 * nums[2] < nums[3]....
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1, 5, 1, 1, 6, 4]
 * Output: One possible answer is [1, 4, 1, 5, 1, 6].
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1, 3, 2, 2, 3, 1]
 * Output: One possible answer is [2, 3, 1, 3, 1, 2].
 * 
 * Note:
 * You may assume all input has valid answer.
 * 
 * Follow Up:
 * Can you do it in O(n) time and/or in-place with O(1) extra space?
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

    void quickSort(vector<int>& nums, int first, int last){
        if(first >= last) return;
        int p = first;
        int pivot = nums[last];
        for(int i = first; i < last; i++){
            if(nums[i] < pivot){
                swap(nums[i], nums[p]);
                p++;
            }
        }
        swap(nums[p], nums[last]);
        quickSort(nums, first, p-1);
        quickSort(nums,p+1, last);
    }
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return;
        quickSort(nums, 0, n-1);
        if(n == 2) return;
        vector<int> temp = nums;
        if(n%2){
            nums[0] = temp[n/2];
            nums[1] = temp[n-1];
            for(int i = 0; i < n/2-1; i++){
                nums[3+2*i] = temp[i+n/2+1];
                nums[2+2*i] = temp[i];
            }
            nums[n-1] = temp[n/2-1];
        }
        else{
            for(int i = 0; i < n/2; i++){
                nums[2*i] = temp[i];
                nums[2*i+1] = temp[i+n/2];
            }
        }
    }
};
// @lc code=end


