/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        TreeNode *last = nullptr;
        flattenRec(root, last);
    }

private:
    void flattenRec(TreeNode *node, TreeNode *&last)
    {
        if (!node)
            return;
        if (!node->left && !node->right)
        {
            last = node;
            return;
        }
        TreeNode *left = node->left;
        TreeNode *right = node->right;
        TreeNode *left_last = nullptr;
        TreeNode *right_last = nullptr;
        if (left)
        {
            flattenRec(left, left_last);
            node->left = nullptr;
            node->right = left;
            last = left_last;
        }
        if (right)
        {
            flattenRec(right, right_last);
            if (left_last)
                last->right = right;
            last = right_last;
        }
    }
};

int main()
{
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(5);
    TreeNode d(3);
    TreeNode e(4);
    TreeNode f(6);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    Solution solve;
    solve.flatten(&a);
    TreeNode *head = &a;
    while (head)
    {
        if (head->left)
            cout << "Error\n";
        cout << head->val << endl;
        head = head->right;
    }
    return 0;
}
