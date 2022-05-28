/*
 * @lc app=leetcode id=687 lang=java
 *
 * [687] Longest Univalue Path
 */

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    public int longestUnivaluePath(TreeNode root) {
        int[] res = postOrder(root);
        return Math.max(res[0], res[1]);
    }

    private int[] postOrder(TreeNode node) {
        // return 2, the longest path under this node, the longest pass which ends at this current
        if (node == null) {
            return new int[] {0, 0};
        }
        int[] leftRes = postOrder(node.left);
        int[] rightRes = postOrder(node.right);
        int curLeft = (node.left != null && node.left.val == node.val) ? leftRes[1] + 1 : 0;
        int curRight = (node.right != null && node.right.val == node.val) ? rightRes[1] + 1 : 0;
        int curLongest = curLeft + curRight;
        int longest1 = Math.max(leftRes[0], Math.max(rightRes[0], curLongest));
        int longest2 = Math.max(curLeft, curRight);
        return new int[] {longest1, longest2};
    }
}
// @lc code=end

