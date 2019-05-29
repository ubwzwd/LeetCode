/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> a, vector<int> b){return a[0] < b[0];});
        int num = 1;
        int temp_lower = points[0][0];
        for (int i = 0; i < points.size(); i++)
        {
            
        }
    }
};

