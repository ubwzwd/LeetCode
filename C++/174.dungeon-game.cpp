/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // m rows and n columns
        int m = dungeon.size();
        int n = dungeon[0].size();
        if(m == 0 || n == 0)
            return 0;
        int dp[m][n] {{0}};
        // initiate the last row and the last column
        // at the end, hp > 0
        dp[m-1][n-1] = max(-dungeon[m-1][n-1], 0) + 1;
        // should make sure that the hp should always > 0
        // inference from the right buttom is to make sure this
        // make sure that: dp[i][j] + dungeon[i][j+1] >= 1
        for (int i = n-2; i >= 0; i--)
            dp[m-1][i] = max(1, dp[m-1][i+1] - dungeon[m-1][i]);
        for (int i = m-2; i >= 0; i--)
            dp[i][n-1] = max(1, dp[i+1][n-1] - dungeon[i][n-1]);
        for(int i = m-2; i >= 0; i--)
        {
            for (int j = n-2; j >= 0; j--)
            {
                dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};

// int main()
// {
//     vector<vector<int>> nums {{-1,-1},{-1,-1}};
//     cout<<nums[1][1];
//     Solution s;
//     int res = s.calculateMinimumHP(nums);
//     cout<< res;
//     return 0;
// }

