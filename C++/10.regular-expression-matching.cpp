/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (25.74%)
 * Likes:    3148
 * Dislikes: 586
 * Total Accepted:    348K
 * Total Submissions: 1.3M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement regular expression
 * matching with support for '.' and '*'.
 * 
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * 
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like . or *.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore,
 * it matches "aab".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 * 
 * 
 */
#include <string>
#include <vector>
using namespace std;

// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         if(p.empty()) return s.empty();
//         int j = 0; // the index for p
//         bool first_match = (!s.empty() && (p[0] == s[0] || p[0] == '.'));
//         if(p.size()>=2 && p[1] == '*'){
//             // * represents 0 time, or at least 1 time
//             return isMatch(s, p.substr(2)) || (first_match &&isMatch(s.substr(1), p));
//         }
//         else{
//             return first_match && isMatch(s.substr(1), p.substr(1));
//         }
//         return true;
//     }
// };

// @lc code=start

// buttom up
class Solution {
private:
    void rec(string& s, string& p, int i, int j, vector<vector<bool>>& dp){
        /*
        i is the index for s, and j is for p
        */
        if(i == s.size() || j == p.size()) return;
        if(p[j] != '*' ){
            dp[i+1][j+1] = dp[i][j];
        }
        // p[j] == '*'
        else {
            // '.*' represents 0 or at leat 1 character
            dp[i+1][j+1] = dp[i+1][j-1] || ((s[i] == p[j-1] || p[j-1] == '.') && dp[i][j+1]);
        }
        rec(s,p,i,j+1, dp);
        rec(s,p,i+1,j, dp);
        rec(s,p,i+1,j+1, dp);
    }

public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        // dp[i+1][j+1] = true means that s[:i] and p[:j] match
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
        rec(s,p,0,0,dp);
        return dp[s.size()][p.size()];
    }
};
// @lc code=end