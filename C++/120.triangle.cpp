/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0)
            return 0;
        // initialize the triangle to store the minimum path to each position
        vector<vector<int>> dp;
        for(int i = 0; i < triangle.size(); i++)
        {
            vector<int> temp(triangle[i].size(), 0);
            dp.push_back(temp);
        }

        // from top to buttom, so start from the buttom of the triangle
        // initialize the last line
        int len = dp.size();
        for(int i = 0; i < dp[len-1].size(); i++)
        {
            dp[len-1][i] = triangle[len-1][i];
        }
        // calculate the above line in each loop
        for(int i = len-2; i >=0; i--)
        {
            for (int j = 0; j < dp[i].size(); j++)
            {
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};

