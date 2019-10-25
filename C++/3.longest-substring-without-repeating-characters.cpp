/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.91%)
 * Likes:    6714
 * Dislikes: 395
 * Total Accepted:    1.2M
 * Total Submissions: 4M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0, left = 0;
        // stores the latest position of each element
        vector<int> hash_map(256, -1);
        for(int i = 0; i < s.size(); i++){
            // this element appears for the first time or last position is not in this sliding window
            if(hash_map[s[i]] == -1 || hash_map[s[i]] < left)
                max_length = max(max_length, i - left + 1);
            else
                left = hash_map[s[i]] + 1;
            hash_map[s[i]] = i;
        }
        return max_length;
    }
};
// @lc code=end

