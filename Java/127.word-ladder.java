import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.List;
import java.util.Queue;
import java.util.Set;

/*
 * @lc app=leetcode id=127 lang=java
 *
 * [127] Word Ladder
 */

// @lc code=start
class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        
        Set<String> set = new HashSet<>();

        for (String s : wordList) {
            set.add(s);
        }

        if (!set.contains(endWord)) return 0;

        Queue<String> q = new ArrayDeque<>();

        q.offer(beginWord);

        int step = 0;

        while(!q.isEmpty()) {
            step++;
            for (int i = q.size(); i > 0; i--) {
                String curStr = q.poll();
                char[] curCharArray = curStr.toCharArray();
                for (int j = 0; j < curStr.length(); j++) {
                    char c = curStr.charAt(j);
                    for (char k = 'a'; k <= 'z'; k++) {
                        curCharArray[j] = k;
                        String newStr = String.valueOf(curCharArray);
                        if (newStr.equals(endWord)) return step + 1;
                        if (!set.contains(newStr)) continue;
                        set.remove(newStr);
                        q.offer(newStr);
                    }
                    curCharArray[j] = c;
                }
            }
        }
        return 0;
    }
}
// @lc code=end

