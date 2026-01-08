/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */
#include <climits>
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    // init a graph
    vector<vector<vector<int>>> graph(n + 1);
    for (auto &time : times) {
      graph[time[0]].push_back(vector<int>{time[1], time[2]});
    }

    // create a min heap
    auto comp = [](vector<int> &a, vector<int> &b) { return a[1] > b[1]; };
    priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> minHeap(
        comp);

    vector<int> distance(n + 1);
    for (auto &i : distance) {
      i = INT_MAX;
    }

    vector<bool> visited(n + 1);

    // start from source node
    distance[k] = 0;
    minHeap.push({k, 0});
    while (minHeap.size() > 0) {
      auto curNode = minHeap.top();
      minHeap.pop();
      // update curNode distance
      if (visited[curNode[0]])
        continue;
      distance[curNode[0]] = min(distance[curNode[0]], curNode[1]);
      visited[curNode[0]] = true;
      // push adjancent nodes into heap
      for (auto &neighbour : graph[curNode[0]]) {
        if (visited[neighbour[0]] != true &&
            distance[neighbour[0]] > curNode[1] + neighbour[1]) {
          minHeap.push(vector<int>{neighbour[0], curNode[1] + neighbour[1]});
        }
      }
    }

    int maxDis = -1;
    for (int i = 1; i < distance.size(); i++) {
      if (distance[i] == INT_MAX) {
        return -1;
      }
      maxDis = max(maxDis, distance[i]);
    }
    return maxDis;
  }
};
// @lc code=end
