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
        if(points.size() == 0)
            return 0;
        sort(points.begin(), points.end(), [](vector<int> a, vector<int> b){return a[0] < b[0];});
        int num = 1;
        // initialize shoot range
        // the lower bound can be ignored
        int temp_lower = points[0][0];
        int temp_higher = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {   
            // if the left end is greater the the shoot range
            if (points[i][0] > temp_higher)
            {
                num++;
                temp_lower = points[i][0];
                temp_higher = points[i][1];
            }
            // update shoot range
            else
            {
                temp_lower = points[i][0];
                if (temp_higher > points[i][1])
                    temp_higher = points[i][1];
            }
        }
        return num;
    }
};

