/*
 * @lc app=leetcode id=33 lang=java
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
    public int search(int[] nums, int target) {
        int left = 0, right = nums.length;
        // search in [left, right)
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[left] <= target) {
                if (nums[mid] < target && nums[mid] >= nums[left]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            } else {
                // nums[left] > target
                if (nums[mid] < target || nums[mid] >= nums[left]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
        }
        return (left < nums.length && nums[left] == target) ? left : -1;
    }
}
// @lc code=end

