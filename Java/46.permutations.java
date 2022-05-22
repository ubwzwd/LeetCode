import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode id=46 lang=java
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        dfs(nums, 0, res);
        return res;
    }

    private void dfs(int[] nums, int index,  List<List<Integer>> res) {
        if (index == nums.length) {
            List<Integer> tempRes = new ArrayList<>();
            for (int i : nums) {
                tempRes.add(i);
            }
            res.add(tempRes);
        }

        for (int i = index; i < nums.length; i++) {
            swap(nums, index, i);
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

