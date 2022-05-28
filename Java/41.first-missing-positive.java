/*
 * @lc app=leetcode id=41 lang=java
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution {

    // Solution:
    // To make use of the index. We sum we have n numbers
    // 0. Traverse the array to check if i is missing
    // 1. mark all the negtive numbers as 1
    // 2. mark numbers > n as 1, because with at most n numbers, the first missing one must be <= n, so > n is meaningless, just mark is as 1 (we are sure we have 1 alr)
    // Now every element in the array is in [1, n]
    // 3. if i is found in the array, we make nums[i] negative
    // 4. if i == n, since we don't have nums[n], we use nums[0]

    public int firstMissingPositive(int[] nums) {
        int n = nums.length;

        boolean isOneExists = false;
        for (int i : nums) {
            if (i == 1) {
                isOneExists = true;
                break;
            }
        }

        if (!isOneExists) {
            return 1;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) nums[i] = 1;
            if (nums[i] > n) nums[i] = 1;
        }

        for (int i = 0; i < n; i++) {
            int index = (Math.abs(nums[i]) == n) ? 0 : Math.abs(nums[i]);
            if (nums[index] > 0) nums[index] = -nums[index];
        }
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) return i;
        }
        return (nums[0] > 0) ? n : n + 1;
    }
}
// @lc code=end

