/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (32.05%)
 * Likes:    3079
 * Dislikes: 219
 * Total Accepted:    300.5K
 * Total Submissions: 922.6K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * Example:
 * 
 * 
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * 
 * 
 * Note:
 * 
 * 
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 * 
 * 
 */
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>
using namespace std;

// @lc code=start
class Solution
{
    bool stillLeft(string &t, vector<int> &hash_table)
    {
        for (auto i : t)
        {
            if (hash_table[i] > 0)
                return true;
        }
        return false;
    }

public:
    string minWindow(string s, string t)
    {
        if (s.empty() || t.empty())
            return "";
        int hash_s[256] = {0};
        int hash_t[256] = {0};
        for (auto i : t)
        {
            hash_t[i]++;
        }
        int res_len = INT_MAX, res_start = 0;
        int r = 0, l = 0, num_include = 0;
        while (r < s.size())
        {
            hash_s[s[r]]++;
            // if not all the s[r] in t are included, we have one more in s, so one more included in t
            if(hash_s[s[r]] <= hash_t[s[r]]) num_include++;
            // if all in t has been included in this substring
            while(num_include == t.size()){
                if(res_len > r-l+1){
                    res_len = r-l+1;
                    res_start = l;
                }
                // l++, because the shortest substring starting at l has already been found
                hash_s[s[l]]--;
                if(hash_s[s[l]] < hash_t[s[l]]) num_include--;
                l++;
            }
            r++;
        }
        return (res_len == INT_MAX)? "" : s.substr(res_start, res_len);
    }
};
// @lc code=end
