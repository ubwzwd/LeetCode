/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (44.90%)
 * Likes:    1608
 * Dislikes: 60
 * Total Accepted:    106.6K
 * Total Submissions: 237.2K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (ie, buy one and sell one share of the stock
 * multiple times) with the following restrictions:
 * 
 * 
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1
 * day)
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,0,2]
 * Output: 3 
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len<=1) return 0;
        // buy on that day or sell on that day
        int buy[len]{0}, sell[len]{0};
        // day 0 and 1 are the special case
        buy[0] = -prices[0];
        sell[1] = max(0, buy[0] + prices[1]);
        // either buy on 1st or 2nd day
        buy[1] = max(buy[0], -prices[1]);
        for(int i = 2; i < len; i++){
            // 1 day cooldown after sell
            buy[i] = max(buy[i-1], sell[i-2] - prices[i]);
            sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
        }
        return sell[len-1];
    }
};
// @lc code=end

