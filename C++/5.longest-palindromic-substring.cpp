/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (27.99%)
 * Likes:    4483
 * Dislikes: 404
 * Total Accepted:    675.2K
 * Total Submissions: 2.4M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len <= 1) return s;
        int max_len = 1, max_start;
        int left, right;
        int i = 0;
        while(i < len){
            if(len - i < max_len/2) break;
            left = right = i;
            while(right < len-1 && s[right] == s[right+1]){
                right++;
            }
            i = right+1;
            while(right<len-1 && left>0 && s[left-1]==s[right+1]){
                left--;
                right++;
            }
            if(max_len < right-left+1){
                max_len = right - left + 1;
                max_start = left;
            }
        }
        return s.substr(max_start, max_len);
    }
};
// @lc code=end

