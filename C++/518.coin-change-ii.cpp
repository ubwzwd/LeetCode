/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
 */
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
  int changeDP(int amount, vector<int> &coins) {

    // dp[i] meaning there are i combinations to get to amount i
    vector<unsigned long long> dp(amount + 1, 0);
    dp[0] = 1;
    for (auto coin : coins) {
      for (int i = coin; i <= amount; i++) {
        dp[i] += dp[i - coin];
      }
    }
    return dp[amount] <= INT_MAX ? dp[amount] : -1;
  }

public:
  int change(int amount, vector<int> &coins) { return changeDP(amount, coins); }
};
// @lc code=end
