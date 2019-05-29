/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        // find the farthest position each position can reach
        vector<int> max_index_each_position;
        for (int i = 0; i < nums.size(); i++)
        {
            max_index_each_position.push_back(i+nums[i]);
        }
        int temp_far = max_index_each_position[0];
        int current_far = max_index_each_position[0];
        int jump_min = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            // if we finish scanning the current position, and got the farthest position it can reach, jump
            if (i > current_far)
            {
                current_far = temp_far;
                jump_min+=1;
            }
            if (max_index_each_position[i] > temp_far)
            {
                temp_far = max_index_each_position[i];
            }
        }
        return jump_min;
    }
};

