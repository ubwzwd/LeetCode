/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 *
 * https://leetcode.com/problems/valid-parenthesis-string/description/
 *
 * algorithms
 * Medium (33.63%)
 * Likes:    860
 * Dislikes: 29
 * Total Accepted:    38K
 * Total Submissions: 112.6K
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
using namespace std;
// @lc code=start
// use the similiar algorithm without *
// class Solution {
// public:
//     bool checkValidString(string s) {
//         int len = s.size();
//         if(len == 0) return true;
//         int lower = 0, upper = 0;
//         for(int i = 0; i < len; i++){
//             if(s[i] == '('){
//                 lower++;
//                 upper++;
//             }
//             else if(s[i] == ')'){
//                 lower--;
//                 upper--;
//             }
//             else{
//                 lower--;
//                 upper++;
//             }
//             lower = lower<0? 0:lower;
//             if(upper < 0) return false;
//         }
//         return lower == 0;
//     }
// };

// try dp
class Solution {
public:
    bool checkValidString(string s) {
        int len = s.size();
        if(len == 0) return true;
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        for(int i = 0; i < len; i++){
            if(s[i] == '*') dp[i][i] = true;
            if(i < len-1 &&
                (s[i] == '(' || s[i] == '*')&&
                (s[i+1] == ')' || s[i+1] == '*'))
            {
                dp[i][i+1] = true;
            }
            
        }
    }
};
// @lc code=end

