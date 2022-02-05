/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 *
 * https://leetcode.com/problems/n-th-tribonacci-number/description/
 *
 * algorithms
 * Easy (57.51%)
 * Likes:    150
 * Dislikes: 31
 * Total Accepted:    27K
 * Total Submissions: 47.6K
 * Testcase Example:  '4'
 *
 * The Tribonacci sequence Tn is defined as follows: 
 * 
 * T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
 * 
 * Given n, return the value of Tn.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4
 * Output: 4
 * Explanation:
 * T_3 = 0 + 1 + 1 = 2
 * T_4 = 1 + 1 + 2 = 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 25
 * Output: 1389537
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= n <= 37
 * The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31
 * - 1.
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n < 3) return 1;
        vector<int> tribonacci(n+1,0);
        tribonacci[1] = 1;
        tribonacci[2] = 1;
        for(int i = 3; i <= n; i++){
            tribonacci[i] = tribonacci[i-1]+tribonacci[i-2]+tribonacci[i-3];
        }
        return tribonacci[n];
    }
};
// @lc code=end

