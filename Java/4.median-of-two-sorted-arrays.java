/*
 * @lc app=leetcode id=4 lang=java
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        double res = 0;
        // letNumber if the sum of elements in the left parts
        // if we have x elements in nums1 left part, we will have (leftNumber - x) elements in nums2 left part
        int leftNumber = (nums1.length + nums2.length + 1) / 2;
        // make sure that nums1 will always be shorter
        if (nums1.length > nums2.length) {
            int[] temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }
        // we search by nums1
        // we want to find 2 indices, idx1 in nums1, idx2 in nums2
        // where:
        // idx1 and idx2 are the beginning number of the right parts
        // which means, (idx1 + idx2) == leftNumber
        // and max(nums1[idx1 - 1], nums2[idx2 - 1]) <= min(nums1[idx1], nums2[idx2])
        int left = 0, right = nums1.length;
        int idx1 = 0, idx2 = 0;
        while (left < right) {
            // idx1 in (left, right] to ensure idx1 >= 0 (we need to check idx1 - 1)
            idx1 = (left + right + 1) / 2;
            idx2 = leftNumber - idx1;
            // now to decide next step
            // if we have more elements than expected in the left part of nums1
            // which means, nums1[idx1 - 1] > nums2[idx2]
            if (nums1[idx1 - 1] > nums2[idx2]) {
                right = idx1 - 1;
            } else {
                left = idx1;
            }
        }
        idx1 = left;
        idx2 = leftNumber - idx1;
        int left1 = idx1 == 0 ? Integer.MIN_VALUE : nums1[idx1 - 1];
        int right1 = idx1 == nums1.length ? Integer.MAX_VALUE : nums1[idx1];
        int left2 = idx2 == 0 ? Integer.MIN_VALUE : nums2[idx2 - 1];
        int right2 = idx2 == nums2.length ? Integer.MAX_VALUE : nums2[idx2];
        if ((nums1.length + nums2.length) % 2 == 0) {
            return ((double)(Math.max(left1, left2) + Math.min(right1, right2)) / 2);
        } else {
            return Math.max(left1, left2);
        }
    }
}
// @lc code=end
