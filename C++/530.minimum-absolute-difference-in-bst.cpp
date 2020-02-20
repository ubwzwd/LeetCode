/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
 *
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (51.93%)
 * Likes:    678
 * Dislikes: 58
 * Total Accepted:    76.5K
 * Total Submissions: 146.3K
 * Testcase Example:  '[1,null,3,2]'
 *
 * Given a binary search tree with non-negative values, find the minimum
 * absolute difference between values of any two nodes.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    3
 * ⁠   /
 * ⁠  2
 * 
 * Output:
 * 1
 * 
 * Explanation:
 * The minimum absolute difference is 1, which is the difference between 2 and
 * 1 (or between 2 and 3).
 * 
 * 
 * 
 * 
 * Note: There are at least two nodes in this BST.
 */
#include <iostream>
#include <vector>
#include <climits>
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
    TreeNode* prev = nullptr;
    int min_diff = INT_MAX;
    void inOrder(TreeNode* root){
        if(!root) return;
        inOrder(root->left);
        if(prev != nullptr) min_diff = min(min_diff, root->val - prev->val);
        prev = root;
        inOrder(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        // for a BST, the in order transmit can always give us the acceding vector
        inOrder(root);
        return min_diff;
    }
};
// @lc code=end

