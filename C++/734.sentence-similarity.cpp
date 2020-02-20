/*
 * @lc app=leetcode id=734 lang=cpp
 *
 * [734] Sentence Similarity
 *
 * https://leetcode.com/problems/sentence-similarity/description/
 *
 * algorithms
 * Easy (41.38%)
 * Likes:    165
 * Dislikes: 264
 * Total Accepted:    29.5K
 * Total Submissions: 71K
 * Testcase Example:  '["great","acting","skills"]\n' +
  '["fine","drama","talent"]\n' +
  '[["great","fine"],["drama","acting"],["skills","talent"]]'
 *
 * Given two sentences words1, words2 (each represented as an array of
 * strings), and a list of similar word pairs pairs, determine if two sentences
 * are similar.
 * 
 * For example, "great acting skills" and "fine drama talent" are similar, if
 * the similar word pairs are pairs = [["great", "fine"], ["acting","drama"],
 * ["skills","talent"]].
 * 
 * Note that the similarity relation is not transitive. For example, if "great"
 * and "fine" are similar, and "fine" and "good" are similar, "great" and
 * "good" are not necessarily similar.
 * 
 * However, similarity is symmetric. For example, "great" and "fine" being
 * similar is the same as "fine" and "great" being similar.
 * 
 * Also, a word is always similar with itself. For example, the sentences
 * words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though
 * there are no specified similar word pairs.
 * 
 * Finally, sentences can only be similar if they have the same number of
 * words. So a sentence like words1 = ["great"] can never be similar to words2
 * = ["doubleplus","good"].
 * 
 * Note:
 * 
 * 
 * The length of words1 and words2 will not exceed 1000.
 * The length of pairs will not exceed 2000.
 * The length of each pairs[i] will be 2.
 * The length of each words[i] and pairs[i][j] will be in the range [1,
 * 20].
 * 
 * 
 * 
 * 
 */
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        int len1 = words1.size(), len2 = words2.size();
        if(len1 != len2) return false;
        unordered_set<string> set;
        for(int i = 0; i < pairs.size(); i++){
            set.insert(string{pairs[i][0] + ' ' + pairs[i][1]});
        }
        for(int i = 0; i < len1; i++){
            if(words1[i] != words2[i] &&
                (!set.count(string{words1[i] + ' ' + words2[i]}) && !set.count(string{words2[i] + ' ' + words1[i]})))
                return false;
        }
        return true;
    }
};
// @lc code=end

