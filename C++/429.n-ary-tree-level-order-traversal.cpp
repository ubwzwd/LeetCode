/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
#include <vector>
#include <queue>
using namespace std;

// class Node {
// public:
//     int val;
//     vector<Node*> children;

//     Node() {}

//     Node(int _val, vector<Node*> _children) {
//         val = _val;
//         children = _children;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> levelOrder(Node* root) {
//         vector<vector<int>> res;
//         vector<int> temp;
//         int cur_rank = 0;
//         queue<pair<Node*, int>> Q;
//         if(!root) return vector<vector<int>>{};
//         Q.push(make_pair(root, 0));
//         while (!Q.empty())
//         {
//             Node* node = Q.front().first;
//             int rank = Q.front().second;
//             if(cur_rank != rank){
//                 res.push_back(temp);
//                 temp.clear();
//                 cur_rank++;
//             }
//             temp.push_back(node->val);
//             for(int i = 0; i < node->children.size(); i++){
//                 Q.push(make_pair(node->children[i], rank+1));
//             }
//             Q.pop();
//         }
//         if(temp.size() != 0) res.push_back(temp);
//         return res;
//     }
// };

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return vector<vector<int>> {};
        vector<vector<int>> res;
        vector<int> temp;
        queue<Node*> Q;
        Q.push(root);
        while(!Q.empty()){
            // calculate the total number in this layer
            int n = Q.size();
            for(int i = 0; i < n; i++){
                Node* node = Q.front();
                Q.pop();
                temp.push_back(node->val);
                for(int j = 0; j < node->children.size(); j++){
                    Q.push(node->children[j]);
                }
            }
            res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};

