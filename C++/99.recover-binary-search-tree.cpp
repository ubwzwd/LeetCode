/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 *
 * https://leetcode.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Hard (36.69%)
 * Likes:    1166
 * Dislikes: 63
 * Total Accepted:    143.8K
 * Total Submissions: 385.2K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * Two elements of a binary search tree (BST) are swapped by mistake.
 * 
 * Recover the tree without changing its structure.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,null,null,2]
 * 
 * 1
 * /
 * 3
 * \
 * 2
 * 
 * Output: [3,1,null,null,2]
 * 
 * 3
 * /
 * 1
 * \
 * 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,1,4,null,null,2]
 * 
 * ⁠ 3
 * ⁠/ \
 * 1   4
 * /
 * 2
 * 
 * Output: [2,1,4,null,null,3]
 * 
 * ⁠ 2
 * ⁠/ \
 * 1   4
 * /
 * ⁠ 3
 * 
 * 
 * Follow up:
 * 
 * 
 * A solution using O(n) space is pretty straight forward.
 * Could you devise a constant space solution?
 * 
 * 
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
    TreeNode* front = nullptr;
    TreeNode* after = nullptr;
    TreeNode* prev = nullptr;
    void inOrder(TreeNode* node){
        if(!node) return;        
        inOrder(node->left);
        // do something here
        if(front && after && node->val > front->val) return;
        if(prev != nullptr){
            if(!front && node->val < prev->val){
                front = prev;
            }
            if(front!=nullptr && node->val < front->val){
                after = node;
            }
        }
        prev = node;
        inOrder(node->right);
    }
public:
    void recoverTree(TreeNode* root) {
        inOrder(root);
        int temp = front->val;
        front->val = after->val;
        after->val = temp;
        return;
    }
};
// @lc code=end

