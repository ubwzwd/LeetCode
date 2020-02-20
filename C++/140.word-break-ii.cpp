/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (29.27%)
 * Likes:    1424
 * Dislikes: 313
 * Total Accepted:    195.8K
 * Total Submissions: 665.2K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, add spaces in s to construct a sentence where each word is
 * a valid dictionary word. Return all such possible sentences.
 * 
 * Note:
 * 
 * 
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * Output:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * Output:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output:
 * []
 * 
 */
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
    unordered_map<string, vector<string>> map;

    vector<string> append(const vector<string>& prefix, const string& word){
        vector<string> res;
        for(auto s : prefix){
            res.emplace_back(s + " " + word);
        }
        // in this case, if prefix is empty, res is empty
        return res;
    }

    vector<string> wordBreakRec(string s, unordered_set<string>& dict){
        // is s is already in the map(visited)
        if(map.count(s)) return map.at(s);

        // stores all the possible solution for s
        vector<string> res;

        if(dict.count(s))
            res.emplace_back(s);
        
        // the right string starts from i
        for(int i = 1; i < s.size(); i++){
            string right = s.substr(i);
            // if right is not in the dict, means that this can't be the answer
            if(!dict.count(right)) continue;

            string left = s.substr(0,i);
            vector<string> left_res = append(wordBreakRec(left, dict), right);
            // res.emplace_back(left_res);
            res.insert(res.end(), left_res.begin(), left_res.end());   
        }
        map[s] = res;
        // map[s].swap(res); // faster
        return map[s];
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
        return wordBreakRec(s, dict);
    }
};
// @lc code=end

