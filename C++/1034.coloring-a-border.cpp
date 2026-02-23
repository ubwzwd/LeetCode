/*
 * @lc app=leetcode id=1034 lang=cpp
 *
 * [1034] Coloring A Border
 */
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
  int dx[4]{0, 0, 1, -1};
  int dy[4]{1, -1, 0, 0};

public:
  vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col,
                                  int color) {
    vector<pair<int, int>> connected;
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size()));
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = 1;
    connected.push_back({row, col});
    while (!q.empty()) {
      int size = q.size();
      while (size > 0) {
        size--;
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
          int nx = x + dx[i];
          int ny = y + dy[i];
          if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() &&
              grid[nx][ny] == grid[x][y] && visited[nx][ny] == 0) {
            q.push({nx, ny});
            visited[nx][ny] = 1;
            connected.push_back({nx, ny});
          }
        }
      }
    }
    for (auto [x, y] : connected) {
      bool isBorder = false;
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size() ||
            (visited[nx][ny] == 0 && grid[nx][ny] != grid[x][y])) {
          isBorder = true;
          break;
        }
      }
      if (isBorder) {
        grid[x][y] = color;
      }
    }
    return grid;
  }
};
// @lc code=end
/*

[ 1, 1, 1, 2, 1, 2 ]
[ 1, 2, 1, 2, 1, 2 ]
[ 1, 1, 1, 2, 1, 2 ]

[1,3], 1

*/
