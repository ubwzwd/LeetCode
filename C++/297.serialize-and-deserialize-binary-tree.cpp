/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (42.82%)
 * Likes:    2192
 * Dislikes: 111
 * Total Accepted:    246.2K
 * Total Submissions: 558.7K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 * 
 * Example: 
 * 
 * 
 * You may serialize the following tree:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 * 
 * as "[1,2,3,null,null,4,5]"
 * 
 * 
 * Clarification: The above format is the same as how LeetCode serializes a
 * binary tree. You do not necessarily need to follow this format, so please be
 * creative and come up with different approaches yourself.
 * 
 * Note: Do not use class member/global/static variables to store states. Your
 * serialize and deserialize algorithms should be stateless.
 * 
 */
#include <string>
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
class Codec {
    // void serializeRec(TreeNode* node, string& res){
    //     if(!node) {
    //         res.append("null");
    //         return;
    //     }
    //     res.append(node->val);
    //     res.push_back(',');
    //     serializeRec(node->left, res);
    //     res.push_back(',');
    //     serializeRec(node->left);
    // }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return string{""};
        string res{""};
        queue<TreeNode*> Q;
        Q.push(root);
        TreeNode* node = nullptr;
        while(!Q.empty()){
            node = Q.front();
            Q.pop();
            if(!node){
                res.append(to_string(node->val));
            }
            else{
                res.append("#");
            }
            res.push_back(' ');
        }
        int i = res.size()-1;
        for(i; i >= 0; i--){
            if(res[i] >='0' && res[i] <='9'){
                break;
            }
            else{
                res.pop_back();
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        // now try to split the string
        int i = 0;
        int pos = 0;
        vector<string> node_val;
        while(i < data.size()){
            pos = i;
            while(i < data.size() && data[i] != ' '){
                i++;
            }
            string temp = data.substr(pos, i-pos);
            node_val.push_back(temp);
            i++;
        }
        TreeNode* root = new TreeNode(stoi(node_val[0]));
        queue<TreeNode*> child, parent;
        child.push(root);
        for(int i = 1; i < node_val.size(); i++){
            if(node_val[i] != "n")
                TreeNode* temp = new TreeNode(stoi(node_val[i]));
            else TreeNode* temp = nullptr;
            child.push(temp);
        }
        while(!child.empty()){
            
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end

