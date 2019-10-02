/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long maximum = 0, sum = 0;
        for(auto num : nums){
            maximum = max((long long)num, maximum);
            sum += num;
        }
        while(maximum < sum){
            long long mid = (sum-maximum)/2+maximum;
            if(canSplit(nums, m - 1 , mid))
                sum = mid;
            else
                maximum = mid+1;
        }
        return maximum;
    }
private:
    bool canSplit(const vector<int>& nums, int m, long long maximum){
        long long accumulator = 0;
        for(int i = 0; i < nums.size(); i++){
            
            if((long long)nums[i]>maximum) return false;
            else if(accumulator + (long long)nums[i] <= maximum)
                accumulator += (long long)nums[i];
            else{
                m--;
                accumulator = (long long)nums[i];
                if(m < 0) return false;
            }
        }
        return true;
    }
};
// class Solution {
// private:
//     bool doable (const vector<int>& nums, int cuts, long long max) {
//         int acc = 0;
//         for (auto num : nums) {
//             // This step is unnecessary for this problem. I didn't discard this line because I want doable function more generalized.
//             if (num > max) return false;
//             else if (acc + num <= max) acc += num;
//             else {
//                 --cuts;
//                 acc = num;
//                 if (cuts < 0) return false;
//             }
//         }
//         return true;
//     }
    
// public:
//     int splitArray(vector<int>& nums, int m) {
//         long long left = 0, right = 0;
//         for (auto num : nums) {
//             left = max(left, (long long)num);
//             right += num;
//         }
        
//         while (left < right) {
//             long long mid = left + (right - left) / 2;
//             if (doable(nums, m - 1, mid)) right = mid;
//             else left = mid + 1;
//         }
//         return left;
//     }
// };

