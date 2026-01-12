/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> seen;
        int maxLen = 0;
        int left = 0, right = 0; // [left, right)
        while (right < s.size())
        {
            while (seen.count(s[right]))
            {
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            right++;
            maxLen = max(maxLen, right - left);
        }
        return maxLen;
    }
};
// @lc code=end
