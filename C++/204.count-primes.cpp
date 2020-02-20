/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (30.46%)
 * Likes:    1535
 * Dislikes: 510
 * Total Accepted:    302.1K
 * Total Submissions: 991.7K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 * 
 */
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        if(n <= 2) return res;
        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;
        int upper = sqrt(n)+1;
        for(int i = 2; i < n; i++){
            if(isPrime[i]) {
                res++;
            }
            if(i >= upper) continue;
            for(int j = i*i; j < n; j+=i){
                isPrime[j] = false;
            }
        }
        return res;
    }
};
// @lc code=end

