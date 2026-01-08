/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (43.05%)
 * Likes:    3236
 * Dislikes: 116
 * Total Accepted:    435.9K
 * Total Submissions: 1M
 * Testcase Example:
 * '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 *
 * Example 1:
 *
 *
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 *
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 *
 * Output: 3
 *
 */

// @lc code=start
#include <queue>
#include <vector>

using namespace std;
class Solution {
private:
  int dx[4]{1, 0, -1, 0};
  int dy[4]{0, 1, 0, -1};

  void dfs(vector<vector<char>> &grid, vector<vector<int>> &visited, int x,
           int y) {
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() ||
        visited[x][y] == 1 || grid[x][y] == '0') {
      return;
    }
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
      dfs(grid, visited, x + dx[i], y + dy[i]);
    }
    return;
  }

public:
  int numIslands_initialBFSVersion(vector<vector<char>> &grid) {
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size()));
    int res = 0;

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        // if it's visited already or it's not island
        if (grid[i][j] == '0' || visited[i][j] == 1)
          continue;

        // if we find a new island
        queue<vector<int>> q;
        q.push(vector<int>{i, j});
        visited[i][j] = 1;
        while (!q.empty()) {
          vector<int> &cur = q.front();
          // check all the neighbours of this node, if it's island, push into
          // queue
          for (int k = 0; k < 4; k++) {
            int x = cur[0] + dx[k];
            int y = cur[1] + dy[k];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() &&
                grid[x][y] == '1' && visited[x][y] == 0) {
              visited[x][y] = 1;
              q.push(vector<int>{x, y});
            }
          }

          q.pop();
        }
        // now all the neighbours are visited
        res++;
      }
    }
    return res;
  }

  // optimised BFS
  int numIslands_BFS_with_in_place_status_change(vector<vector<char>> &grid) {
    int res = 0;

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        // if it's visited already or it's not island
        if (grid[i][j] == '0')
          continue;

        // if we find a new island
        queue<vector<int>> q;
        q.push(vector<int>{i, j});
        grid[i][j] = '0';
        while (!q.empty()) {
          vector<int> &cur = q.front();
          // check all the neighbours of this node, if it's island, push into
          // queue
          for (int k = 0; k < 4; k++) {
            int x = cur[0] + dx[k];
            int y = cur[1] + dy[k];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() &&
                grid[x][y] == '1') {
              grid[x][y] = '0';
              q.push(vector<int>{x, y});
            }
          }

          q.pop();
        }
        // now all the neighbours are visited
        res++;
      }
    }
    return res;
  }

  // DFS
  int numIslands(vector<vector<char>> &grid) {
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size()));
    int res = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == '1' && visited[i][j] == 0) {
          dfs(grid, visited, i, j);
          res++;
        }
      }
    }
    return res;
  }
};
// @lc code=end
