/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> farthest;
        // find the minimum of the vector
        int mini = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < mini)
            {
                mini = nums[i];
            }
            farthest.push_back(i+nums[i]);
        }
        // if all the numbers > 1, we won't got stuck. We can always move to the next position
        if(mini > 0)
            return true;
        // for a point, determin the farthest position it can jump to within the next step
        int temp_farthest = farthest[0];
        // record the position. It means that if I jump to this position, I can get to the farthest position next step
        int next_position = 0;
        while(next_position < nums.size() && next_position <= temp_farthest)
        {
            // if we can reach farther
            if(temp_farthest < farthest[next_position])
            {
                temp_farthest = farthest[next_position];
            }
            next_position++;
        }
        if(next_position == nums.size())
            return true;
        else return false;
    }
};

