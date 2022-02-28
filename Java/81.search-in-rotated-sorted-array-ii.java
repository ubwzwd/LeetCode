/*
 * @lc app=leetcode id=81 lang=java
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
    public boolean search(int[] nums, int target) {
        // search in [left, right]
        int left = 0, right = nums.length - 1, mid = 0;

        while (left < right - 1) {
            // will eject 2 numbers, left = right - 1
            // consider duplicates here
            while (left < right - 1 && nums[left] == nums[left + 1]) {
                left++;
            }
            while (left < right - 1 && nums[right] == nums[right - 1]) {
                right--;
            }
            if (left >= right - 1) break;

            mid = (left + right) / 2;
            if(nums[mid] == target) return true;
            else if (nums[mid] >= nums[left]) {
                if (nums[mid] > target && nums[left] <= target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && nums[right] >= target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        if (nums[left] == target || nums[right] == target) return true;
        return false;
    }
}
// @lc code=end

