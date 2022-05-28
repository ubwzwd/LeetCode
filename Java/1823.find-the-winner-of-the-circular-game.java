import java.util.ArrayDeque;
import java.util.Queue;

/*
 * @lc app=leetcode id=1823 lang=java
 *
 * [1823] Find the Winner of the Circular Game
 */

// @lc code=start
class Solution {
    public int findTheWinner(int n, int k) {
        Queue<Integer> queue = new ArrayDeque<>();
        for(int i = 1; i <= n; i++) {
            queue.offer(i);
        }
        while (queue.size() != 1) {
            int temp = k - 1;
            while(temp > 0) {
                int cur = queue.poll();
                queue.offer(cur);
                temp--;
            }
            queue.poll();
        }
        return queue.poll();
    }
}
// @lc code=end
