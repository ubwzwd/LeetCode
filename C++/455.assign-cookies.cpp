/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        // how many children is satisfied
        int child = 0;
        // how many cookies we have tried
        int cookie = 0;
        while(child < g.size() && cookie < s.size())
        {
            // if the cookie size satisfies the child
            if (g[child] <= s[cookie])
                child++;
            // not matter how, go to the next cookie
            cookie++;
        }
        return child;
    }
};

