/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */
#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        for(int i = 0; i <= amount; i++)
        {
            dp[i] = -1;
        }
        dp[0] = 0;
        // 所有有面值的值全为1，只需要1张
        for (int i = 0; i < coins.size(); i++)
        {
            if (coins[i] <= amount)
                dp[coins[i]] = 1;
        }
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                // if dp[i] can be combined by dp[i-coins[j] and coins[j]
                if (i >= coins[j] && dp[i-coins[j]] != -1)
                {
                    if (dp[i] == -1 || dp[i] > dp[i-coins[j]]+1)
                        dp[i] = dp[i-coins[j]]+1;
                }
            }
        }
        return dp[amount];
    }
};

