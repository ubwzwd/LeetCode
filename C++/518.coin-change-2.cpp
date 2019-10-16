/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 *
 * https://leetcode.com/problems/coin-change-2/description/
 *
 * algorithms
 * Medium (44.35%)
 * Likes:    975
 * Dislikes: 40
 * Total Accepted:    59.3K
 * Total Submissions: 133.2K
 * Testcase Example:  '5\n[1,2,5]'
 *
 * You are given coins of different denominations and a total amount of money.
 * Write a function to compute the number of combinations that make up that
 * amount. You may assume that you have infinite number of each kind of
 * coin.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: amount = 5, coins = [1, 2, 5]
 * Output: 4
 * Explanation: there are four ways to make up the amount:
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: amount = 3, coins = [2]
 * Output: 0
 * Explanation: the amount of 3 cannot be made up just with coins of 2.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: amount = 10, coins = [10] 
 * Output: 1
 * 
 * 
 * 
 * 
 * Note:
 * 
 * You can assume that
 * 
 * 
 * 0 <= amount <= 5000
 * 1 <= coin <= 5000
 * the number of coins is less than 500
 * the answer is guaranteed to fit into signed 32-bit integer
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    // *************This is the wrong way to consider this problem************
    // int change(int amount, vector<int>& coins) {
    //     if(amount == 0 || coins.empty()) return 0;
    //     vector<int> combinations(amount+1, 0);
    //     for(int i = 0; i < coins.size(); i++){
    //         if(coins[i] <= amount) combinations[coins[i]]++;
    //     }
    //     for(int i = 1; i <= amount; i++){
    //         for(int j = 0; j < coins.size(); j++){
    //             if(i >= coins[j])
    //                 combinations[i] += combinations[i-coins[j]];
    //         }
    //     }
    //     return combinations[amount];
    // }
    
    // // now consider base on what type of coin we would use
    // int change(int amount, vector<int>& coins) {
    //     if(amount == 0) return 1;
    //     if(coins.empty()) return 0;        
    //     // dp[i][j] is when we choose to use the first i coins, the ways to make up to amount j
    //     vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, 0));
    //     // initialization
    //     // when the amount we want to make is 0, there is always 1 way to make, that is to choose no coin
    //     // and for dp[0][i], we can always have 0 ways because we don't have any coin
    //     for(int i = 0; i <= coins.size(); i++){
    //         dp[i][0] = 1;
    //     }
    //     // not that i = 0 is when we use the first coin, that is coins[0]
    //     for(int i = 1; i <= coins.size(); i++){
    //         // j is the amount we want to make
    //         for(int j = 1; j <= amount; j++){
    //             // if j is not less than coins[i-1], we can at least consider to use the new coin
    //             if(j >= coins[i-1]){
    //                 // dp[i-1][j] means that we choose not to use the new coin, and dp[i][j-1] means that we use 1 new coin and j-coins[i] is what left
    //                 dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
    //             }
    //             // if j is less than coins[i], we can't use the new coin, so it is still the same with only using the first i-1 kind of coins
    //             else
    //                 dp[i][j] = dp[i-1][j];
    //         }
    //     }
    //     return dp[coins.size()][amount];
    // }

    // now consider the relationship between dp[i][j] and dp[i-1][j]
    // dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]]
    // so we may reduce the dp matrix to a vector, because we don't need to keep other situations
    int change(int amount, vector<int>& coins){
        if(amount == 0) return 1;
        if(coins.empty()) return 0;
        vector<int> dp(amount+1, 0);
        // amount is 0, always a way to make
        dp[0] = 1;
        for(int i = 0; i < coins.size(); i++){
            // there is no need to update the amount that is less than the amount of new coin
            for(int j = coins[i]; j <= amount; j++){
                // dp[j] = dp[j] + dp[j-coins[i]] if simplified from
                // dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]]
                dp[j] += dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};
// @lc code=end

