/*
 * @lc app=leetcode id=518 lang=java
 *
 * [518] Coin Change 2
 */

// @lc code=start
class Solution {
    // time complexity: O((amount/min(coins) ^ coins.length))
    // space complexity: O(coins.length)
    public int change(int amount, int[] coins) {
        if (amount == 0) return 1;
        return dfs(coins, 0, amount);
    }

    private int dfs(int[] coins, int index, int amountLeft) {
        if (amountLeft == 0) {
            return 1;
        }
        if (index >= coins.length) {
            return 0;
        }
        int res = 0;
        for (int i = 0; i <= (amountLeft / coins[index]); i++) {
            res += dfs(coins, index + 1, amountLeft - coins[index] * i);
        }
        return res;
    }
}
// @lc code=end

