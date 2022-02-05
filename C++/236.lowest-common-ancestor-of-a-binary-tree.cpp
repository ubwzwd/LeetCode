/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (39.12%)
 * Likes:    2254
 * Dislikes: 143
 * Total Accepted:    313K
 * Total Submissions: 800K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
 *
 * Given a binary tree, find the lowest common ancestor (LCA) of two given
 * nodes in the tree.
 * 
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes p and q as the lowest node in T that has both p
 * and q as descendants (where we allow a node to be a descendant of itself).”
 * 
 * Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * Output: 3
 * Explanation: The LCA of nodes 5 and 1 is 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * Output: 5
 * Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant
 * of itself according to the LCA definition.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All of the nodes' values will be unique.
 * p and q are different and both values will exist in the binary tree.
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
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_path = findPath(root, p);
        vector<TreeNode*> q_path = findPath(root, q);
        int path_len = min(p_path.size(), q_path.size());
        TreeNode* common_ancestor = root;
        for(int i = 0; i < path_len; i++)
        {
            if(p_path[i] == q_path[i])
                common_ancestor = p_path[i];
            else
                break;
        }
        return common_ancestor;
    }

private:
    vector<TreeNode*> findPath(TreeNode* root, TreeNode* target)
    {
        vector<TreeNode*> temp;
        vector<TreeNode*> res;
        int finish = 0;
        findPathRec(root, target, temp, res, finish);
        return res;
    }

    void findPathRec(TreeNode* node, TreeNode* target, vector<TreeNode*>& temp, vector<TreeNode*>& res, int& finish)
    {
        if(!node || finish)
            return;
        temp.push_back(node);
        if(target == node)
        {
            finish = 1;
            res = temp;
            return;
        }
        findPathRec(node->left, target, temp, res, finish);
        findPathRec(node->right, target, temp, res, finish);
        temp.pop_back();
    }
};

