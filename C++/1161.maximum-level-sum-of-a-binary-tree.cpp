/*
 * @lc app=leetcode id=1161 lang=cpp
 *
 * [1161] Maximum Level Sum of a Binary Tree
 */
#include <climits>
#include <queue>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  int maxLevelSum(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    int maxSum = INT_MIN;
    int maxLevel = 0;
    int curLevel = 1;
    while (!q.empty()) {
      int levelSize = q.size();
      int curSum = 0;
      for (int i = 0; i < levelSize; i++) {
        auto node = q.front();
        q.pop();
        curSum += node->val;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      if (curSum > maxSum) {
        maxSum = curSum;
        maxLevel = curLevel;
      }
      curLevel++;
    }
    return maxLevel;
  }
};
// @lc code=end
