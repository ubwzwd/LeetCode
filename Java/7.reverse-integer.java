/*
 * @lc app=leetcode id=7 lang=java
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
    public int reverse(int x) {
        int res = 0;
        while (x != 0) {
            if (
                res < Integer.MIN_VALUE / 10 || 
                res > Integer.MAX_VALUE / 10 ||
                (res == Integer.MIN_VALUE && (x % 10) < (Integer.MIN_VALUE % 10)) ||
                (res == Integer.MAX_VALUE && (x % 10) > (Integer.MAX_VALUE % 10))
            ) {
                return 0;
            }
            res *= 10;
            res += x % 10;
            x /= 10;
        }
        return res;
    }
}
// @lc code=end

