/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// #include <vector>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        // time exceeded
        // if (n==1 || n==2)
        //     return n;
        // else
        // {
        //     return climbStairs(n-1) + climbStairs(n-2);
        // }
        if (n == 1 || n == 2)
            return n;
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }

    // // return how many ways
    // int climbRec(int n)
    // {
    //     if (n==1 || n==2)
    //         return n;
    //     else
    //     {
    //         return climbRec(n-1) + climbRec(n-2);
    //     }
    // }
};

