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
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        // the first is original one, second is the copy
        unordered_map<Node*, Node*> ori_copy;
        // copy is the root of the new graph
        Node* copy = new Node(node->val, {});
        ori_copy[node] = copy;
        queue<Node*> Q;
        Q.push(node);
        while(!Q.empty()){
            Node* cur = Q.front();
            Q.pop();
            for(int i = 0; i < cur->neighbors.size(); i++){
                // that means this node has not been copied
                if(ori_copy.find(cur->neighbors[i]) == ori_copy.end()){
                    ori_copy[cur->neighbors[i]] = new Node(cur->neighbors[i]->val, {});
                    Q.push(cur->neighbors[i]);
                }
                ori_copy[cur]->neighbors.push_back(ori_copy[cur->neighbors[i]]);
            }
        }
        return copy;
    }
};

