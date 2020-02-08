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
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end()); 
        if(!dict.count(endWord)) return 0;
        unordered_set<string> qBegin;
        unordered_set<string> qEnd;
        qBegin.insert(beginWord);
        qEnd.insert(endWord);

        int l = beginWord.size();
        int step = 0;

        // this loop will end in 2 cases
        // 1. after changing a letter, the current string is equal to the endWord, then break, return the steps
        // 2. No one matches the endWord until the dict is erased to empty, so the queue should be empty later, then break
        while(!qBegin.empty() && !qEnd.empty()){
            step++;
            // go further with the larger set
            unordered_set<string> temp;
            if(qBegin.size() > qEnd.size()){
                for(string w : qBegin){
                    for(int i = 0; i < l; i++){
                        char ch = w[i];
                        for(char j = 'a'; j <= 'z'; j++){
                            w[i] = j;
                            // if found in qEnd
                            if(qEnd.count(w)) return step+1;
                            // if not exists in dict
                            if(!dict.count(w)) continue;
                            dict.erase(w);
                            temp.insert(w);
                        }
                        w[i] = ch;
                    }
                }
                qBegin.swap(temp);
            }
            else{
                for(string w : qEnd){
                    for(int i = 0; i < l; i++){
                        char ch = w[i];
                        for(char j = 'a'; j <= 'z'; j++){
                            w[i] = j;
                            if(qBegin.count(w)) return step+1;
                            if(!dict.count(w)) continue;
                            dict.erase(w);
                            temp.insert(w);
                        }
                        w[i] = ch;
                    }
                }
                qEnd.swap(temp);
            }
        }
        return 0;
    }
};
// @lc code=end

