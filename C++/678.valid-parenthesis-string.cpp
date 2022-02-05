/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 *
 * https://leetcode.com/problems/valid-parenthesis-string/description/
 *
 * algorithms
 * Medium (33.75%)
 * Likes:    860
 * Dislikes: 29
 * Total Accepted:    38.1K
 * Total Submissions: 112.9K
 * Testcase Example:  '"()"'
 *
 * 
 * Given a string containing only three types of characters: '(', ')' and '*',
 * write a function to check whether this string is valid. We define the
 * validity of a string by these rules:
 * 
 * Any left parenthesis '(' must have a corresponding right parenthesis ')'.
 * Any right parenthesis ')' must have a corresponding left parenthesis '('.
 * Left parenthesis '(' must go before the corresponding right parenthesis ')'.
 * '*' could be treated as a single right parenthesis ')' or a single left
 * parenthesis '(' or an empty string.
 * An empty string is also valid.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: "()"
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "(*)"
 * Output: True
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: "(*))"
 * Output: True
 * 
 * 
 * 
 * Note:
 * 
 * The string size will be in the range [1, 100].
 * 
 * 
 */
#include <string>
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool checkValidString(string s) {
        int len = s.size();
        if(len == 0) return true;
        // dp[i][j] = true means that s[i:j] is valid
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        // process the initial state(length = 2) 
        for(int i = 0; i < len; i++){
            if(s[i] == '*') dp[i][i] = true;
            if(i < len-1 &&
            (s[i] == '(' || s[i] == '*') &&
            (s[i+1] == ')' || s[i+1] == '*')
            ){
                dp[i][i+1] = true;
            }
        }
        // from state k to state k+1
        // suppose the length of the current substring is n+1 (n+1 starts from 3)
        for(int n = 2; n < len; n++){
            for(int i = 0; i < len-n; i++){
                // expand either side of the string of length n-1
                if(s[i] == '*' && dp[i+1][i+n] == true) dp[i][i+n] = true;
                else if (s[i] == '(' || s[i] == '*'){
                    for(int k = i+1; k <= i+n; k++){
                        // this time, s[i] must be the beginning of the parathensis or *
                        // and s[k] should be the pair
                        if((s[k] == ')' || s[k] == '*') &&
                            // and s[i+1, k-1] is valid
                            (k == i+1 || dp[i+1][k-1]) &&
                            // and s[k+1,i+n] is also valid, becasue s[i+1, i+n] is seperated by k
                            (k == i+n || dp[k+1][i+n])){
                                dp[i][i+n] = true;
                            }
                    }
                }
            }
        }
        return dp[0][len-1];
    }
};
// @lc code=end

