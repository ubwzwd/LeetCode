/*
 * @lc app=leetcode id=778 lang=cpp
 *
 * [778] Swim in Rising Water
 */
#include <vector>
#include <queue>
// #include <priority_queue>
using namespace std;
// @lc code=start
class Solution
{
private:
    const int dx[4]{-1, 1, 0, 0};
    const int dy[4]{0, 0, -1, 1};

public:
    int swimInWater(vector<vector<int>> &grid)
    {
        // i, j, height
        auto comp = [](const tuple<int, int, int> &a, const tuple<int, int, int> &b)
        {
            return get<2>(a) > get<2>(b);
        };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(comp)> minHeap(comp);
        minHeap.push({0, 0, grid[0][0]});
        grid[0][0] = -1; // mark as visited
        while (!minHeap.empty())
        {
            auto [x, y, h] = minHeap.top();
            minHeap.pop();
            if (x == grid.size() - 1 && y == grid[0].size() - 1)
                return h;
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] >= 0)
                {
                    minHeap.push({nx, ny, max(grid[nx][ny], h)});
                    grid[nx][ny] = -1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end
