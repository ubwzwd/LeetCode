/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (33.41%)
 * Likes:    1297
 * Dislikes: 1700
 * Total Accepted:    583.9K
 * Total Submissions: 1.7M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */
#include <string>
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start

// // brute force
// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int len1 = haystack.size();
//         int len2 = needle.size();
//         if(len2 == 0) return 0;
//         if(len1 == 0) return -1;
//         int i = 0;
//         while(i < len1){
//             for(int j = 0; j < len2; j++){
//                 if(needle[j] != haystack[i+j]) {
//                     break;
//                 }
//                 else{
//                     // all the elements are matched
//                     if(j == needle.size()-1){
//                         return i;
//                     }
//                 }
//             }
//             i++;
//         }
//         return -1;
//     }
// };

// try to implement KMP
class Solution {
    vector<int> calPrefix(string s){
        int n = s.size();
        vector<int> prefix(n,0);
        // calculates the prefix lenth for i-th element, len is the index of element currently be considering add to prefix
        int i = 1, len = 0;
        while(i<n){
            if(s[i] == s[len]){
                len++;
                prefix[i] = len;
                i++;
            }
            // if s[i] != s[len],
            else if(len){
                len = prefix[len-1];
            }
            else{
                prefix[i] = 0;
                i++;
            }
        }
        return prefix;
    }
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size();
        int len2 = needle.size();
        if(len2 == 0) return 0;
        // calculate the prefix array
        vector<int> prefix = calPrefix(needle);
        // i is the index in haystack, j is the index in needle
        int i = 0, j = 0;
        while(i < len1){
            if(haystack[i] == needle[j]){
                i++, j++;
            }
            // matched
            if(j == len2){
                return i-j;
            }
            if(i<len1 && haystack[i] != needle[j]){
                if(j > 0)
                    j = prefix[j-1];
                else
                    i++;
            }
        }
        return -1;
    }
};
// @lc code=end

