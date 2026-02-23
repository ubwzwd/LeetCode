/*
 * @lc app=leetcode id=3713 lang=cpp
 *
 * [3713] Longest Balanced Substring I
 */

// @lc code=start
class Solution {
public:
    int longestBalanced(string s) {
        if (s.size() <= 2) return s.size();
        int res = 2;
        for (int len = 3; len <= s.size(); len++) {
            vector<int> freq(26);
            for (int start = 0; start < s.size() - len + 1; start++) {
                bool isBalanced = true;
                if (start == 0) {
                    for (int i = 0; i < len; i++) freq[s[i] - 'a']++;
                } else {
                    freq[s[start - 1] - 'a']--;
                    freq[s[start + len - 1] - 'a']++;
                }
                int tempF = 0;
                for (int i = 0; i < 26; i++) {
                    if (freq[i] == 0) continue;
                    if (tempF == 0) tempF = freq[i];
                    if (tempF != freq[i]) {
                        isBalanced = false;
                        break;
                    }
                }
                if (isBalanced) {
                    res = len;
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end

