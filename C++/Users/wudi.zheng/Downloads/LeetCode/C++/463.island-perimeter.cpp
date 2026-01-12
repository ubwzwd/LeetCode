/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
private:
    int countNeighhours(vector<vector<int>> &grid, int x, int y)
    {
        int res = 0;
        if (x - 1 >= 0)
            res += grid[x - 1][y];
        if (y - 1 >= 0)
            res += grid[x][y - 1];
        if (x + 1 < grid.size())
            res += grid[x + 1][y];
        if (y + 1 < grid[0].size())
            res += grid[x][y + 1];
        return res;
    }

public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int counts = 0, connections = 0;
        // find all the 1s, count the number as well as the connection number
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                // find 1
                if (grid[i][j] == 1)
                {
                    counts++;
                    connections += countNeighhours(grid, i, j);
                }
            }
        }
        return counts * 4 - connections;
    }
};
// @lc code=end
