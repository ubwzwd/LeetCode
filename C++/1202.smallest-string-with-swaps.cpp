/*
 * @lc app=leetcode id=1202 lang=cpp
 *
 * [1202] Smallest String With Swaps
 */
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
  vector<int> root;

  int find(int x) {
    if (root[x] != x) {
      root[x] = find(root[x]);
    }
    return root[x];
  }

  void unionNode(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
      root[rootX] = rootY;
    }
    return;
  }

  void sortInGroup(string &result, const string &s, vector<int> &indices) {
    vector<char> temp;
    for (auto &i : indices)
      temp.push_back(s[i]);
    sort(temp.begin(), temp.end());
    sort(indices.begin(), indices.end());

    for (int i = 0; i < indices.size(); i++) {
      result[indices[i]] = temp[i];
    }
  }

public:
  string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
    // init root
    root.resize(s.size());
    for (int i = 0; i < s.size(); i++) {
      root[i] = i;
    }

    for (vector<int> &pair : pairs) {
      unionNode(pair[0], pair[1]);
    }

    // index of root -> list of index in the group
    unordered_map<int, vector<int>> groups;
    for (int i = 0; i < root.size(); i++) {
      groups[find(i)].push_back(i);
    }

    // next is to sort each group as a string, then combine them together
    string result(s);
    for (auto &pair : groups) {
      sortInGroup(result, s, pair.second);
    }
    return result;
  }
};
// @lc code=end
