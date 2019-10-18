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
// #include <string>
// #include <iostream>
// #include <vector>
// #include <climits>
// using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Codec {
private:
    // void intToString(int num, string& s){
    //     string temp;
    //     while(
    // }

    void preOrder(TreeNode* node, string& s){
        if(!node) return;
        s.append(to_string(node->val));
        s.push_back(' ');
        preOrder(node->left, s);
        preOrder(node->right, s);
    }

    TreeNode* reconstruct(const string& s, int& pos, int mini, int maxi){
        if(pos >= s.size()) return nullptr;
        int num;
        int start = pos;
        while(s[pos] != ' '){
            pos++;
        }
        num = stoi(s.substr(start, (pos-start)));
        pos++;
        if(num > maxi || num < mini) {
            pos = start;
            return nullptr;
        }
        TreeNode* node = new TreeNode(num);
        node->left = reconstruct(s, pos, mini, num);
        node->right = reconstruct(s, pos, num, maxi);
        return node;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        preOrder(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return reconstruct(data, pos, INT_MIN, INT_MAX);
    }
};

// int main(){
//     string s{"1;2;3;"};
//     Codec c;
    
// }

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

