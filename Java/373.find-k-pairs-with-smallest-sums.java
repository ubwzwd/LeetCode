import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

/*
 * @lc app=leetcode id=373 lang=java
 *
 * [373] Find K Pairs with Smallest Sums
 */

// @lc code=start
class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        Queue<int[]> q = new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] p1, int[] p2) {
                if ((p1[0] + p1[1]) == (p2[0] + p2[1])) return 0;
                return (p1[0] + p1[1]) < (p2[0] + p2[1]) ? -1 : 1;
            }
        });

        List<List<Integer>> res = new ArrayList<>();

        for (int i = 0; i < Math.min(nums1.length, k); i++) {
            q.offer(new int[]{nums1[i], nums2[0], 0});
        }

        while(k > 0 && !q.isEmpty()) {
            k--;
            int[] cur = q.poll();
            res.add(Arrays.asList(cur[0], cur[1]));
            if (cur[2] == nums2.length - 1) continue;
            q.offer(new int[] {cur[0], nums2[cur[2] + 1], cur[2] + 1});
        }

        return res;
    }
}
// @lc code=end

