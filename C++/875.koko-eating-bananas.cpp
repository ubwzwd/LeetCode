/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 *
 * https://leetcode.com/problems/koko-eating-bananas/description/
 *
 * algorithms
 * Medium (49.23%)
 * Likes:    481
 * Dislikes: 52
 * Total Accepted:    26.1K
 * Total Submissions: 52.9K
 * Testcase Example:  '[3,6,7,11]\n8'
 *
 * Koko loves to eat bananas.  There are N piles of bananas, the i-th pile has
 * piles[i] bananas.  The guards have gone and will come back in H hours.
 * 
 * Koko can decide her bananas-per-hour eating speed of K.  Each hour, she
 * chooses some pile of bananas, and eats K bananas from that pile.  If the
 * pile has less than K bananas, she eats all of them instead, and won't eat
 * any more bananas during this hour.
 * 
 * Koko likes to eat slowly, but still wants to finish eating all the bananas
 * before the guards come back.
 * 
 * Return the minimum integer K such that she can eat all the bananas within H
 * hours.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: piles = [3,6,7,11], H = 8
 * Output: 4
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: piles = [30,11,23,4,20], H = 5
 * Output: 30
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: piles = [30,11,23,4,20], H = 6
 * Output: 23
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= piles.length <= 10^4
 * piles.length <= H <= 10^9
 * 1 <= piles[i] <= 10^9
 * 
 * 
 * 
 * 
 * 
 */
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int left = 1, right = *max_element(piles.begin(), piles.end())+1;
        // h is the hour, we want to find the maximum h that h <= H, Then we get the minimum K
        // and left, right and mid are the number of bananas Koko eat at one time
        int mid = 0, h = 0;
        while(left < right){
            mid = left+(right-left)/2;
            h = 0;
            for(auto p : piles){
                // the same thing as ceilling(p/mid)
                h += (p+mid-1)/mid;
            }
            // if mid is less than what we want, it means h > H
            if(h>H) left = mid+1;
            else right = mid;
        }
        return left;
    }
};
// @lc code=end

