/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (50.33%)
 * Likes:    1993
 * Dislikes: 55
 * Total Accepted:    472.6K
 * Total Submissions: 924.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
 * 
 */
#include <vector>
#include <queue>
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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>>{};
        queue<pair<TreeNode*, int>> Q;
        Q.push(make_pair(root, 0));
        vector<vector<int>> res;
        TreeNode* cur_node = nullptr;
        int cur_layer = 0;
        while(!Q.empty()){
            cur_node = Q.front().first;
            cur_layer = Q.front().second;
            Q.pop();
            // first, push the cur_node into res
            if(cur_layer >= res.size()){
                res.push_back(vector<int>{cur_node->val});
            }
            else{
                res[cur_layer].push_back(cur_node->val);
            }
            // push the next layer into queue
            if(cur_node->left){
                Q.push(make_pair(cur_node->left, cur_layer+1));
            }
            if(cur_node->right){
                Q.push(make_pair(cur_node->right, cur_layer+1));
            }
        }
        return res;
    }
};
// @lc code=end

