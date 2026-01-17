/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class TrieNode {
private:
  vector<TrieNode *> links;
  bool isEnd;

public:
  TrieNode() : links(vector<TrieNode *>(26)), isEnd(false) {};
  ~TrieNode() {
    for (auto &node : links) {
      if (node)
        delete node;
    }
  }

  bool containsKey(char c) { return links[c - 'a'] != nullptr; }

  TrieNode *get(char c) { return links[c - 'a']; }

  void put(char c, TrieNode *node) { links[c - 'a'] = node; }
  void setEnd() { isEnd = true; }
  bool isEndOfWord() { return isEnd; }
};

class Trie {
private:
  TrieNode *root;

public:
  Trie() : root(new TrieNode()) {}
  ~Trie() { delete root; }

  void insert(string word) {
    // do char by char
    TrieNode *cur = root;
    for (auto &c : word) {
      if (!cur->containsKey(c)) {
        // no existing char in this layer, insert
        cur->put(c, new TrieNode());
      }
      cur = cur->get(c);
    }
    cur->setEnd();
  }

  bool search(string word) {
    TrieNode *cur = root;
    for (auto &c : word) {
      if (!cur->containsKey(c))
        return false;
      cur = cur->get(c);
    }
    return cur->isEndOfWord();
  }

  bool startsWith(string prefix) {
    TrieNode *cur = root;
    for (auto &c : prefix) {
      if (!cur->containsKey(c))
        return false;
      cur = cur->get(c);
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
