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
            if(a[i]!=b[i]) res++;
        }
        return res;
    }
    // int ladderLengthRec(string& beginword, string& endWord, vector<string>& wordList, int temp, int index){
    //     if(beginword == endWord){
    //         return temp;
    //     }
    //     for(int )
    // }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int length = 0;
        bool isEndWordExists = false;
        for(int i = 0; i < wordList.size(); i++){
            if(wordList[i] == endWord){
                isEndWordExists = true;
            }
            if(wordList[i] == beginWord) return 1;
        }
        if(isEndWordExists == false) return 0;
        int res = 0;
        // res = ladderLengthRec(beginWord, endWord, wordList, 0, 0);
        // <int,int> is <index, layer>
        queue<pair<int,int>> bfs;
        for(int i = 0; i < wordList.size(); i++){
            if(diff(beginWord, wordList[i]) == 1){
                bfs.push(make_pair(i, 2));
            }
        }
        int index = 0, layer = 0;
        while(!bfs.empty()){
            index = bfs.front().first;
            layer = bfs.front().second;
            if(wordList[index] == endWord){
                return layer;
            }
            for(int i = 0; i < wordList.size(); i++){
                if(i != index && diff(wordList[i], wordList[index]) == 1){
                    bfs.push(make_pair(i, layer+1));
                }
            }
        }
        return res;
    }
};
// @lc code=end

