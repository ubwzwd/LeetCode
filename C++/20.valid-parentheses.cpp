/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (37.32%)
 * Likes:    3685
 * Dislikes: 177
 * Total Accepted:    768.9K
 * Total Submissions: 2M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
#include <string>
#include <vector>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        if(len == 0) return true;
        if(len%2) return false;
        int count[3] = {0,0,0};
        stack<char> sta;
        for(int i = 0; i < len; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                sta.push(s[i]);
            }
            else{
                if(sta.empty() || (sta.top() == '(' && s[i] != ')') || (sta.top() == '[' && s[i] != ']') || (sta.top() == '{' && s[i] != '}')){
                    return false;
                }
                sta.pop();
            }
        }
        return sta.empty() ? true : false;
    }
};
// @lc code=end

