/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (59.84%)
 * Likes:    2413
 * Dislikes: 99
 * Total Accepted:    615.2K
 * Total Submissions: 1M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,3,2]
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 * 
 */
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void inOrder(TreeNode* node, vector<int>& res){
        if(!node) return;
        inOrder(node->left, res);
        res.emplace_back(node->val);
        inOrder(node->right, res);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        inOrder(root, res);
        return res;
    }
};
// @lc code=end

