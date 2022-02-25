import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
 * @lc app=leetcode id=90 lang=java
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {

    // time complexity: O(n * 2^n)
    // space complexity: O(2^n)

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        dfs(nums, 0, new ArrayList<>(), res);
        return res;
    }

    private void dfs(int[] nums, int index, ArrayList<Integer> prefix, List<List<Integer>> res) {
        if (index == nums.length) {
            List<Integer> newSubset = (ArrayList<Integer>) prefix.clone();
            res.add(newSubset);
            return;
        }

        int curVal = nums[index];
        int nextIndex = index;
        while(nextIndex < nums.length && nums[nextIndex] == curVal) {
            nextIndex++;
        }
        int curIndex = index;
        dfs(nums, nextIndex, prefix, res);
        while(curIndex < nextIndex) {
            prefix.add(curVal);
            dfs(nums, nextIndex, prefix, res);
            curIndex++;
        }
        while(curIndex > index) {
            prefix.remove(prefix.size() - 1);
            curIndex--;
        }
    }
}
// @lc code=end

