/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (43.81%)
 * Likes:    1707
 * Dislikes: 224
 * Total Accepted:    258.6K
 * Total Submissions: 590.1K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * Given a binary tree, flatten it to a linked list in-place.
 * 
 * For example, given the following tree:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 
 * The flattened tree should look like:
 * 
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        // the last node stores the last element of the branch
        TreeNode* last = root;
        flattenRec(root, last);
    }

private:
    void flattenRec(TreeNode* node, TreeNode* last)
    {
        if(!node)
            return;
        if(!node->left && !node->right)
        {
            last = node;
            return;
        }
        // back up the two trees
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        if(left)
        {            
            TreeNode* left_last = left;
            flattenRec(left, left_last);
            last = left_last;
            node->right = left;
            node->left = nullptr;
        }
        if(right)
        {
            TreeNode* right_last = right;
            flattenRec(right, right_last);
            last->right = right;
            last = right_last;            
        }
    }
};

