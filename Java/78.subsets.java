import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode id=78 lang=java
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {

    // time complexity: O(n * 2^n)
    // space complexity: O(2^n)

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        dfs(nums, 0, new ArrayList<>(), res);
        return res;
    }

    private void dfs(int[] nums, int index, List<Integer> prefix, List<List<Integer>> res) {
        if (index == nums.length) {
            List<Integer> newSubset = createSubset(prefix);
            res.add(newSubset);
            return;
        }
        // not add current element
        dfs(nums, index + 1, prefix, res);
        
        // add current element
        prefix.add(nums[index]);
        dfs(nums, index + 1, prefix, res);
        prefix.remove(prefix.size() - 1);
    }

    private List<Integer> createSubset(List<Integer> nums) {
        List<Integer> l = new ArrayList<>(nums.size());
        for (int i : nums) {
            l.add(i);
        }
        return l;
    }
}
// @lc code=end