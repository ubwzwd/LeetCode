/*
 * @lc app=leetcode id=5 lang=java
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
    public String longestPalindrome(String s) {
        boolean[][] isPalindrome = new boolean[s.length()][s.length()];
        for (int i = 0; i < s.length(); i++) {
            isPalindrome[i][i] = true;
        }
        int start = 0, end = 0, maxLen = 1;
        for (int i = s.length() - 2; i >= 0; i--) {
            for (int j = i + 1; j < s.length(); j++) {
                if (s.charAt(i) == s.charAt(j)) {
                    if (i == j - 1 || isPalindrome[i + 1][j - 1]) {
                        isPalindrome[i][j] = true;
                        if (j - i + 1 > maxLen) {
                            // if can update
                            start = i;
                            end = j;
                            maxLen = j - i + 1;
                        }
                    }
                }
            }
        }
        return s.substring(start, end + 1);
    }
}
// @lc code=end

