/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (49.41%)
 * Likes:    1977
 * Dislikes: 144
 * Total Accepted:    344K
 * Total Submissions: 693K
 * Testcase Example:  '3\n2'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * How many possible unique paths are there?
 * 
 * 
 * Above is a 7 x 3 grid. How many possible unique paths are there?
 * 
 * Note: m and n will be at most 100.
 * 
 * Example 1:
 * 
 * 
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the
 * bottom-right corner:
 * 1. Right -> Right -> Down
 * 2. Right -> Down -> Right
 * 3. Down -> Right -> Right
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: m = 7, n = 3
 * Output: 28
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    // int uniquePaths(int m, int n) {
    //     // math solution
    //     // total (m+n-2), with (m-1) right and (n-1) down
    //     long res = 1;
    //     int j = 1;
    //     for(int i = m; i <= (m+n-2); i++){
    //         res *= i;
    //         res /= j;
    //         j++;
    //     }
    //     return res;
    // }

    // // dp way to do this
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m, vector<int>(n,1));
    //     // dp[i][j] = dp[i-1][j] + dp[i][j-1]
    //     for(int i = 1; i < m; i++){
    //         for(int j = 1; j < n; j++){
    //             dp[i][j] = dp[i-1][j] + dp[i][j-1];
    //         }
    //     }
    //     return dp[m-1][n-1];
    // }

    // another dp way to save memory
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        // dp[i][j] = dp[i-1][j] + dp[i][j-1]
        // if we calculate row by row
        // row 0 is all 1s
        // from row 1
        // dp[i] += dp[i-1]
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[j] += dp[j-1];
            }
        }
        return dp[n-1];
    }
};
// @lc code=end

