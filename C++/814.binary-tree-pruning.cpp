/*
 * @lc app=leetcode id=814 lang=cpp
 *
 * [814] Binary Tree Pruning
 *
 * https://leetcode.com/problems/binary-tree-pruning/description/
 *
 * algorithms
 * Medium (72.50%)
 * Likes:    787
 * Dislikes: 30
 * Total Accepted:    51.7K
 * Total Submissions: 70.8K
 * Testcase Example:  '[1,null,0,0,1]'
 *
 * We are given the head node root of a binary tree, where additionally every
 * node's value is either a 0 or a 1.
 * 
 * Return the same tree where every subtree (of the given tree) not containing
 * a 1 has been removed.
 * 
 * (Recall that the subtree of a node X is X, plus every node that is a
 * descendant of X.)
 * 
 * 
 * Example 1:
 * Input: [1,null,0,0,1]
 * Output: [1,null,0,null,1]
 * ⁠
 * Explanation: 
 * Only the red nodes satisfy the property "every subtree not containing a 1".
 * The diagram on the right represents the answer.
 * 
 * 
 * 
 * 
 * 
 * Example 2:
 * Input: [1,0,1,0,0,0,1]
 * Output: [1,null,1,null,1]
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 3:
 * Input: [1,1,0,1,1,0,1,0]
 * Output: [1,1,0,1,1,null,1]
 * 
 * 
 * 
 * 
 * 
 * Note: 
 * 
 * 
 * The binary tree will have at most 100 nodes.
 * The value of each node will only be 0 or 1.
 * 
 * 
 */
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
    void deleteNode(TreeNode* v){
        if(v->left) deleteNode(v->left);
        if(v->right) deleteNode(v->right);
        delete v;
    }
    // check if the subtree should be removed
    // if so, return true and remove the subtree
    bool inOrderCheck(TreeNode* v){
        if(!v) return false;
        if(!v->left && !v->right) return v->val==0;
        bool leftRemovable = inOrderCheck(v->left);
        bool rightRemovable = inOrderCheck(v->right);
        if(leftRemovable) deleteNode(v->left);
        if(rightRemovable) deleteNode(v->right);
        if(leftRemovable && rightRemovable && v->val==0) return true;
        return false;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        return inOrderCheck(root)? nullptr : root;
    }
};
// @lc code=end

