/*
 * @lc app=leetcode id=407 lang=cpp
 *
 * [407] Trapping Rain Water II
 */
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
private:
    const int dx[4] = {1, 0, 0, -1};
    const int dy[4] = {0, 1, -1, 0};

public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        int m = heightMap.size(), n = heightMap[0].size();
        auto comp = [](tuple<int, int, int> &x, tuple<int, int, int> &y)
        { return get<2>(x) > get<2>(y); };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(comp)> pq(comp); // minHeap
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // add boundary grids to pq
        for (int i = 0; i < m; i++)
        {
            pq.push({i, 0, heightMap[i][0]});
            pq.push({i, n - 1, heightMap[i][n - 1]});
            visited[i][0] = true;
            visited[i][n - 1] = true;
        }
        for (int j = 0; j < n; j++)
        {
            pq.push({0, j, heightMap[0][j]});
            pq.push({m - 1, j, heightMap[m - 1][j]});
            visited[0][j] = true;
            visited[m - 1][j] = true;
        }

        int res = 0;
        while (!pq.empty())
        {
            auto [x, y, h] = pq.top();
            pq.pop();

            // find its neighbours
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny])
                    continue;
                visited[nx][ny] = true;
                if (h > heightMap[nx][ny])
                {
                    res += h - heightMap[nx][ny];
                }
                pq.push({nx, ny, max(h, heightMap[nx][ny])});
            }
        }
        return res;
    }
};
// @lc code=end
