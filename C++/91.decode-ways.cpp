/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (22.96%)
 * Likes:    1763
 * Dislikes: 1996
 * Total Accepted:    304K
 * Total Submissions: 1.3M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 * 
 * Example 1:
 * 
 * 
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 * 
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
private:
    bool isValid(const char& a){
        return a!='0';
    }

    bool isValid(const char& a, const char& b){
        return a == '1' || (a == '2' && b <= '6');
    }
public:
    int numDecodings(string s) {
        // the same as step 1 or 2
        int len = s.size();
        if(len == 0 || !isValid(s[0])) return 0;
        if(len == 1 && isValid(s[0])) return 1;
        vector<int> dp(len, 0);
        dp[0] = 1;
        if(isValid(s[0], s[1])) dp[1]++;
        if(isValid(s[1])) dp[1]+=dp[0];
        for(int i = 2; i < len; i++){
            if(isValid(s[i])) dp[i] += dp[i-1];
            if(isValid(s[i-1], s[i])) dp[i] += dp[i-2];
        }
        return dp[len-1];
    }
};
// @lc code=end

