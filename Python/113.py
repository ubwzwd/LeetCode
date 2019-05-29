'''
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

import copy

class Solution:
    def pathSum(self, root: TreeNode, sum: int):
        # res stores the list
        res = []
        path = []
        path_sum = 0
        self.preOrder(root, sum, path, path_sum, res)
        return res

    def preOrder(self, root, sum, path, path_sum, res):
        self.preOrderRec(root, sum, path, path_sum, res)
        
    def preOrderRec(self, node: TreeNode, sum, path, path_sum, res):
        if not node:
            return
        else:
            path_sum+=node.val
            path.extend([node.val])
            if not node.left and not node.right and path_sum == sum:
                temp_res = copy.deepcopy(path)
                res.append(temp_res)
            self.preOrderRec(node.left, sum, path, path_sum, res)
            self.preOrderRec(node.right, sum, path, path_sum, res)
            path_sum -= node.val
            path.pop()
            

a = TreeNode(5)
b = TreeNode(4)
c = TreeNode(8)
d = TreeNode(11)
e = TreeNode(13)
f = TreeNode(4)
g = TreeNode(7)
h = TreeNode(2)
i = TreeNode(5)
j = TreeNode(1)
a.left = b
a.right = c
b.left = d
d.left = g
d.right = h
c.left = e
c.right = f
f.left = i
f.right = j
res = Solution()
result = res.pathSum(a, 22)
print(result)
        