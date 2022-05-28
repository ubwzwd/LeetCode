import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/*
 * @lc app=leetcode id=47 lang=java
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {

    // time complexity: O(n! * n)
    // space complexity: O(n^2 + n + n! * n) = O(n! * n)

    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        dfs(nums, 0, res);
        return res;
    }

    private void dfs(int[] nums, int index, List<List<Integer>> res) {
        if (index == nums.length) {
            List<Integer> tempRes = new ArrayList<>();
            for (int i : nums){
                tempRes.add(i);
            }
            res.add(tempRes);
        }

        Set<Integer> set = new HashSet<>();
        for (int i = index; i < nums.length; i++) {
            if (set.contains(nums[i])) {
                continue;
            }
            swap(nums, index, i);
            set.add(nums[index]);
            dfs(nums, index + 1, res);
            swap(nums, index, i);
        }
    }

    private void swap(int[] nums, int x, int y) {
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }
}
// @lc code=end
