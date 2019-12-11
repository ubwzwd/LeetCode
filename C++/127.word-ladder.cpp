/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (25.75%)
 * Likes:    2099
 * Dislikes: 947
 * Total Accepted:    329.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 * 
 * 
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * Note:
 * 
 * 
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * Output: 5
 * 
 * Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
 * "dog" -> "cog",
 * return its length 5.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * Output: 0
 * 
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 * 
 * 
 * 
 * 
 * 
 */
#include <string>
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
    int diff(string& a, string& b){
        int res = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]) res++;
        }
        return res;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int length = 0;
        bool isEndWordExists = false;
        for(int i = 0; i < wordList.size(); i++){
            if(wordList[i] == endWord){
                isEndWordExists = true;
                break;
            }
        }
        
        if(isEndWordExists == false) return 0;
        int res = 0;
        queue<pair<int,int>> Q;
        vector<int> visited(wordList.size(), 0);
        for(int i = 0; i < wordList.size(); i++){
            if(diff(wordList[i], beginWord) == 1) {
                Q.push(make_pair(i, 2));
                visited[i] = 1;
            }
        }
        int cur_index=0, cur_layer = 0;
        while(!Q.empty()){
            cur_index = Q.front().first;
            cur_layer = Q.front().second;
            Q.pop();
            if(wordList[cur_index] == endWord){
                res = cur_layer;
                break;
            } 
            if(cur_layer <= wordList.size())
            {
                for(int i = 0; i < wordList.size(); i++){
                    if(cur_index != i && diff(wordList[i], wordList[cur_index]) == 1 && visited[i] == 0){
                        Q.push(make_pair(i, cur_layer+1));
                        visited[i] = 1;
                    }
                }
            }
            else break;
        }
        return res;
    }
};
// @lc code=end

