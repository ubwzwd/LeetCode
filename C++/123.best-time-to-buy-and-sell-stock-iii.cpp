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

#include <algorithm>
#include <climits>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    // this hold[i][j] means: the max profit after completing i transactions
    // when hold some stock in hand on day j
    vector<vector<int>> hold(3, vector<int>(prices.size()));
    // this unhold[i][j] means: the max profit after completing i transactions
    // and doesn't hold any stock in hand on day j
    vector<vector<int>> unhold(3, vector<int>(prices.size()));
    // hold[i][j] = max(hold[i][j-1] (meaning no action), unhold[i][j-1] -
    // prices[j] (meaning buy stock on day j) )
    // unhold[i][j] = max(unhold[i][j-1] (do nothing) , hold[i-1][j-1] +
    // prices[j](sell the stock at day j) )

    for (int i = 0; i < 3; i++) {
      hold[i][0] = -prices[0];
    }
    for (int i = 1; i < prices.size(); i++) {
      hold[0][i] = max(hold[0][i - 1], -prices[i]);
    }
    // unhold on day 0 is always 0
    for (int j = 1; j < prices.size(); j++) {
      for (int i = 1; i < 3; i++) {
        hold[i][j] = max(hold[i][j - 1], unhold[i][j - 1] - prices[j]);
        unhold[i][j] = max(unhold[i][j - 1], hold[i - 1][j - 1] + prices[j]);
      }
    }
    return max({unhold[0][prices.size() - 1], unhold[1][prices.size() - 1],
                unhold[2][prices.size() - 1]});
  }
};
// @lc code=end
