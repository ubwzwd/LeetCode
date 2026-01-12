/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<pair<int, int>> passengerChanges;
        for (auto &trip : trips)
        {
            passengerChanges.push_back({trip[0], trip[1]});
            passengerChanges.push_back({-trip[0], trip[2]});
        }
        auto comp = [](pair<int, int> &a, pair<int, int> &b)
        {
            if (a.second != b.second)
                return a.second < b.second;
            return a.first < b.first;
        };
        sort(passengerChanges.begin(), passengerChanges.end(), comp);
        int paxCount = 0;
        for (auto &passengerChange : passengerChanges)
        {
            paxCount += passengerChange.first;
            if (paxCount > capacity)
                return false;
        }
        return true;
    }
};
// @lc code=end
