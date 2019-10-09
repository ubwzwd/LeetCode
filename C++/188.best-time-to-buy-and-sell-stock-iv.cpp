/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (26.93%)
 * Likes:    929
 * Dislikes: 60
 * Total Accepted:    100.3K
 * Total Submissions: 372.1K
 * Testcase Example:  '2\n[2,4,1]'
 *
 * Say you have an array for which the i-th element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most k
 * transactions.
 * 
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 * 
 * Example 1:
 * 
 * 
 * Input: [2,4,1], k = 2
 * Output: 2
 * Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit
 * = 4-2 = 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,6,5,0,3], k = 2
 * Output: 7
 * Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit
 * = 6-2 = 4.
 * Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 =
 * 3.
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if(len<=1 || k == 0) return 0;
        int max_profit = 0, temp_max = 0;
        // if k is too much
        if(k>len/2){
            for(int i = 1; i < len; i++){
                max_profit += max(prices[i]-prices[i-1], 0);
            }
            return max_profit;
        }
        // dp[i][j] means the max profit when complete i transaction at day j
        // so dp[0][j] are always 0 because we make no transaction, and dp[i][0] is also 0 because we cant't sell at the first day
        vector<vector<int>> dp(k+1, vector<int>(len, 0));
        // we get the max profit on day j when:
        // 1. the same with day j-1
        // 2. we do one more transaction, buying on day k and sell on day j.
        // dp[i][j] = max(dp[i][j-1], max(dp[i-1][k] + prices[j] - prices[k]))
        //          = max(dp[i][j-1], prices[j] + max(dp[i-1][k] - prices[k]))
        // goes from 1 transaction
        for(int i = 1; i < k+1; i++){
            temp_max = dp[i-1][0] - prices[0];
            for(int j = 1; j < len; j++){
                dp[i][j] = max(dp[i][j-1], prices[j] + temp_max);
                // update the temp_max for next day
                temp_max = max(temp_max, dp[i-1][j] - prices[j]);
                max_profit = max(max_profit, dp[i][j]);
            }
        }
        return max_profit;
    }
};
// @lc code=end

