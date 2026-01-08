/*
 * @lc app=leetcode id=1101 lang=cpp
 *
 * [1101] The Earliest Moment When Everyone Become Friends
 */
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
  vector<int> root;
  void quickSort(vector<vector<int>> &logs, int left, int right) {
    if (left >= right)
      return;
    vector<int> &pivot = logs[right];
    // [left, i) <= pivot, [i, j) > pivot, [j, right) not visited yet
    int i = left, j = left;
    while (j < right) {
      // check item j.
      // if item j <= pivot, swap j and i, i++, j++
      // if item j > pivot, no need swap, j++
      if (logs[j][0] <= pivot[0]) {
        // swap
        swapVector(logs[j], logs[i]);
        i++;
      }
      j++;
    }
    // now [left, i) <= pivot, [i, right) > pivot, swap i and pivot
    swapVector(logs[i], pivot);
    quickSort(logs, left, i - 1);
    quickSort(logs, i + 1, right);
    return;
  }

  void swapVector(vector<int> &v1, vector<int> &v2) {
    for (int i = 0; i < v1.size(); i++) {
      int temp = v1[i];
      v1[i] = v2[i];
      v2[i] = temp;
    }
  }

  int find(int x) {
    if (root[x] != x) {
      root[x] = find(root[x]);
    }
    return root[x];
  }

  int unionWithConnectionCheck(vector<vector<int>> &logs) {
    int counts = root.size();
    for (auto &log : logs) {
      // union first
      int rootX = find(log[1]);
      int rootY = find(log[2]);
      if (rootX != rootY) {
        root[rootX] = rootY;
        counts--;
      }
      // then check if all the n people are connected
      if (counts == 1) {
        return log[0];
      }
    }
    return -1;
  }

public:
  int earliestAcq(vector<vector<int>> &logs, int n) {
    quickSort(logs, 0, logs.size() - 1);
    root = vector<int>(n);
    for (int i = 0; i < n; i++) {
      root[i] = i;
    }
    return unionWithConnectionCheck(logs);
  }
};
// @lc code=end
