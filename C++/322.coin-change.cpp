/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  int coinChangeDFS(vector<int> &coins, int amount, int sum, int count) {
    if (sum == amount)
      return count;
    if (sum > amount) {
      return -1;
    }
    int res = INT_MAX;
    for (auto i : coins) {
      if (INT_MAX - i < sum)
        continue;
      int subRes = coinChangeDFS(coins, amount, sum + i, count + 1);
      if (subRes > 0)
        res = min(res, subRes);
    }
    return res == INT_MAX ? -1 : res;
  }

  int coinChangeDFSWithMemory(vector<int> &coins, vector<int> &countMap,
                              int amount, int rest) {
    if (rest == 0)
      return 0;
    if (rest < 0) {
      return -1;
    }
    if (countMap[rest] < INT_MAX)
      return countMap[rest];
    int minSubCount = INT_MAX;
    for (auto i : coins) {
      int subCount = coinChangeDFSWithMemory(coins, countMap, amount, rest - i);
      if (subCount >= 0) {
        minSubCount = min(minSubCount, subCount);
      }
    }
    countMap[rest] = minSubCount < INT_MAX ? minSubCount + 1 : -1;
    return countMap[rest];
  }

  int coinChangeDP(vector<int> &coins, int amount) {
    // coins[i] refers to min number of coins to get to total amount i
    // then we should return coins[amount] as the result
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
      int minCount = INT_MAX;
      for (auto j : coins) {
        // will use coin j this time and if it's valid
        if (i - j >= 0 && dp[i - j] >= 0 && dp[i - j] < INT_MAX) {
          minCount = min(minCount, dp[i - j] + 1);
        }
      }
      dp[i] = minCount == INT_MAX ? -1 : minCount;
    }
    return dp[amount];
  }

public:
  int coinChange(vector<int> &coins, int amount) {
    // vector<int> countMap(amount + 1,
    //                      INT_MAX); // countMap[i] stores the min number of
    //                                // coins required to get to i
    return coinChangeDP(coins, amount);
  }
};
