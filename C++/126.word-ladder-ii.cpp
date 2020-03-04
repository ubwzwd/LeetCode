/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 *
 * https://leetcode.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (20.08%)
 * Likes:    1399
 * Dislikes: 220
 * Total Accepted:    155.3K
 * Total Submissions: 771K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * all shortest transformation sequence(s) from beginWord to endWord, such
 * that:
 * 
 * 
 * Only one letter can be changed at a time
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * Note:
 * 
 * 
 * Return an empty list if there is no such transformation sequence.
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
 * Output:
 * [
 * ⁠ ["hit","hot","dot","dog","cog"],
 * ["hit","hot","lot","log","cog"]
 * ]
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
 * Output: []
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
#include <unordered_set>
#include <unordered_map>
#include <climits>
using namespace std;
// @lc code=start
class Solution {
    void getParents(const string& word, const string& beginWord, const unordered_map<string, vector<string>>& parents, vector<string>& temp, vector<vector<string>>& res){
        if(word == beginWord){
            res.push_back(vector<string>(temp.rbegin(), temp.rend()));
            return;
        }

        for(auto p : parents.at(word)){
            temp.emplace_back(p);
            getParents(p, beginWord, parents, temp, res);
            temp.pop_back();
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.count(endWord)) return {};
        dict.erase(beginWord);
        dict.erase(endWord);

        unordered_map<string, vector<string>> parents;
        unordered_map<string, int> steps{{beginWord, 1}};
        queue<string> q;
        q.push(beginWord);

        vector<vector<string>> res;
        bool found = false;
        int step = 0;
        const int l = beginWord.size();

        while(!q.empty() && !found){
            step++;
            // take out all the nodes of this step in the queue
            for(int size = q.size(); size>0; size--){
                const string p = q.front();
                q.pop();
                string w = p;
                for(int i = 0; i < l; i++){
                    char ch = w[i];
                    for(int j = 'a'; j <= 'z'; j++){
                        if(j == ch) continue;
                        w[i] = j;
                        // if w already exists in steps
                        // found
                        if(w == endWord){
                            found = true;
                            parents[w].push_back(p);
                        }
                        // not found, but can be updated
                        else if(steps.count(w) && step < steps.at(w)){
                            parents[w].push_back(p);
                        }

                        // if w is visited before, skip the next several statements
                        if(!dict.count(w)) continue;

                        // w is a new word found in the dict, not in steps
                        dict.erase(w);
                        q.push(w);
                        steps[w] = steps.at(p) + 1;
                        parents[w].push_back(p);
                    }
                    w[i] = ch;
                }
            }
        }

        if(found){
            vector<string> temp{endWord};
            getParents(endWord, beginWord, parents, temp, res);
        }

        return res;
    }
};
// @lc code=end

