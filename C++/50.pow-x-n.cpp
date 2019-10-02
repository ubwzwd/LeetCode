/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (28.46%)
 * Likes:    951
 * Dislikes: 2337
 * Total Accepted:    355.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (x^n).
 * 
 * Example 1:
 * 
 * 
 * Input: 2.00000, 10
 * Output: 1024.00000
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2.10000, 3
 * Output: 9.26100
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 
 * Note:
 * 
 * 
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
 * 
 * 
 */
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0) return x;
        if(n == 0) return 1;
        else if(n == 1) return x;
        // in case that n = INT_MIN, then -n is out of range
        int t = n/2;
        if(n < 0){
            x = 1/x;
            t = -t;
        }
        double res = myPow(x,t);
        if(n%2 == 0) return res*res;
        else return res*res*x;
    }
};

