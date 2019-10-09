/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 *
 * algorithms
 * Hard (34.93%)
 * Likes:    1373
 * Dislikes: 57
 * Total Accepted:    169.6K
 * Total Submissions: 484.7K
 * Testcase Example:  '[3,3,5,0,0,3,1,4]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most two
 * transactions.
 * 
 * Note: You may not engage in multiple transactions at the same time (i.e.,
 * you must sell the stock before you buy again).
 * 
 * Example 1:
 * 
 * 
 * Input: [3,3,5,0,0,3,1,4]
 * Output: 6
 * Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit
 * = 3-0 = 3.
 * Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 =
 * 3.
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit
 * = 5-1 = 4.
 * Note that you cannot buy on day 1, buy on day 2 and sell them later, as you
 * are
 * engaging multiple transactions at the same time. You must sell before buying
 * again.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len<=1) return 0;
        int max_profit = INT_MIN, temp_max = 0;
        // dp[i][j] means the max profit when complete i transaction at day j
        // so dp[0][j] are always 0 because we make no transaction, and dp[i][0] is also 0 because we cant't sell at the first day
        vector<vector<int>> dp(3, vector<int>(len, 0));
        // we get the max profit on day j when:
        // 1. the same with day j-1
        // 2. we do one more transaction, buying on day k and sell on day j.
        // dp[i][j] = max(dp[i][j-1], max(dp[i-1][k] + prices[j] - prices[k]))
        //          = max(dp[i][j-1], prices[j] + max(dp[i-1][k] - prices[k]))
        // goes from 1 transaction
        for(int i = 1; i < 3; i++){
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

