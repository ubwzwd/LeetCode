/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (49.18%)
 * Likes:    1250
 * Dislikes: 64
 * Total Accepted:    190K
 * Total Submissions: 385.1K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 * Explanation:
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
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
#include <vector>
#include <queue>

using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        int layer = 0;
        queue<pair<int, int>> Q;
        inOrderTraversal(root, Q, layer);
        while(!Q.empty()){
            if(res.size() <= Q.front().second){
                res.push_back(Q.front().first);
                Q.pop();
            }
            else{
                res[Q.front().second] = Q.front().first;
                Q.pop();
            }
        }
        return res;
    }

private:
    void inOrderTraversal(TreeNode* node, queue<pair<int, int>>& Q, int layer){
        if(!node)
            return;
        // first is the value and second is the layer number
        Q.push(make_pair(node->val, layer));
        inOrderTraversal(node->left, Q, layer+1);
        inOrderTraversal(node->right, Q, layer+1);
        return;
    }
};

