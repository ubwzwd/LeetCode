import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode id=22 lang=java
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
    public List<String> generateParenthesis(int n) {
        // time complexity: O(2 ^ (2n))
        // space complexity: O(2n * 4 ^ n)
        List<String> res = new ArrayList<>();
        this.dfs(n, n, new StringBuilder(), res);
        return res;
    }

    private void dfs(int left, int right, StringBuilder sb, List<String> res) {
        if (left == 0 && right == 0) {
            res.add(sb.toString());
            return;
        }

        // check if we can add left parenthesis
        if (left > 0) {
            sb.append('(');
            dfs(left - 1, right, sb, res);
            sb.deleteCharAt(sb.length() - 1);
        }

        // check if we can add right parenthesis
        if (left < right) {
            sb.append(')');
            dfs(left, right - 1, sb, res);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}
// @lc code=end

