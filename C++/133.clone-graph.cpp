#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};
/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
// #include <vector>
// #include <unordered_map>
// #include <queue>
// using namespace std;
// class Node {
// public:
//     int val;
//     vector<Node*> neighbors;

//     Node() {}

//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

// @lc code=start
class Solution {
public:
  Node *cloneGraph(Node *node) {
    if (node == nullptr)
      return nullptr;
    Node *root = new Node(node->val);
    queue<pair<Node *, Node *>> q;
    unordered_map<Node *, Node *> old_to_new;
    q.push({node, root});
    old_to_new.insert({node, root});
    while (!q.empty()) {
      auto [old_node, new_node] = q.front();
      q.pop();
      for (auto neighbor : old_node->neighbors) {
        if (old_to_new.count(neighbor)) {
          new_node->neighbors.push_back(old_to_new[neighbor]);
        } else {
          Node *newN = new Node(neighbor->val);
          old_to_new.insert({neighbor, newN});
          new_node->neighbors.push_back(newN);
          q.push({neighbor, newN});
        }
      }
    }
    return root;
  }
};
// @lc code=end