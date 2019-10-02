/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
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
#include <string>
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
private:
    void intToString(int num, string& s){
        string temp;
        while(num){
            temp+=num%10+'0';
            num = num/10;
        }
        // inverse the string
        for(int i = temp.size()-1; i >= 0; i++){
            s += temp[i];
        }
        s+=';';
    }
    // BFS
    void preOrder(TreeNode* node, string& s){
        if(!node) return;
        intToString(node->val, s);
        preOrder(node->left, s);
        preOrder(node->right, s);
    }

    void BSTInsert(TreeNode* node, int num){
        if(num < node->val){
            if(node->left){
                BSTInsert(node->left, num);
            }
            else{
                TreeNode* temp = new TreeNode(num);
                node->left = temp;
            }
        }
        else{
            if(node->right){
                BSTInsert(node->right, num);
            }
            else{
                TreeNode* temp = new TreeNode(num);
                node->right = temp;
            }
        }
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // use pre-order to generate a string
        string tree_string;
        preOrder(root, tree_string);
        return tree_string;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;
        vector<int> node_vec;
        int val;
        for(int i = 0; i < data.size(); i++){
            if(data[i] != ';'){
                val = val*10 + int(data[i]) - 48;
            }
            else{
                node_vec.push_back(val);
                val = 0;
            }
        }
        if(node_vec.size() == 0) return nullptr;
        // construct the root
        TreeNode* root = new TreeNode(node_vec[0]);
        for(int i = 1; i < node_vec.size(); i++){
            // insert
            BSTInsert(root, node_vec[i]);
        }
        return root;
    }
};

// int main(){
//     string s{"1;2;3;"};
//     Codec c;
    
// }

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

