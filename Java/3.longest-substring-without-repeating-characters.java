import java.util.HashSet;
import java.util.Set;

/*
 * @lc app=leetcode id=3 lang=java
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s == null || s.length() == 0) return 0;
        Set<Character> set = new HashSet<>();
        int start = 0;
        int end = 0;
        // cur substr: [start, end]
        int maxLen = 0;
        while (end < s.length()) {
            while (set.contains(s.charAt(end))) {
                set.remove(s.charAt(start));
                start++;
            }
            set.add(s.charAt(end));
            maxLen = Math.max(maxLen, end - start + 1);
            end++;
        }
        return maxLen;
    }
}
// @lc code=end

