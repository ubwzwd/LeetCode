/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Friend Circles
 *
 * https://leetcode.com/problems/friend-circles/description/
 *
 * algorithms
 * Medium (55.28%)
 * Likes:    1241
 * Dislikes: 98
 * Total Accepted:    107.8K
 * Total Submissions: 194.9K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * 
 * There are N students in a class. Some of them are friends, while some are
 * not. Their friendship is transitive in nature. For example, if A is a direct
 * friend of B, and B is a direct friend of C, then A is an indirect friend of
 * C. And we defined a friend circle is a group of students who are direct or
 * indirect friends.
 * 
 * 
 * 
 * Given a N*N matrix M representing the friend relationship between students
 * in the class. If M[i][j] = 1, then the ith and jth students are direct
 * friends with each other, otherwise not. And you have to output the total
 * number of friend circles among all the students.
 * 
 * 
 * Example 1:
 * 
 * Input: 
 * [[1,1,0],
 * ⁠[1,1,0],
 * ⁠[0,0,1]]
 * Output: 2
 * Explanation:The 0th and 1st students are direct friends, so they are in a
 * friend circle. The 2nd student himself is in a friend circle. So return
 * 2.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * [[1,1,0],
 * ⁠[1,1,1],
 * ⁠[0,1,1]]
 * Output: 1
 * Explanation:The 0th and 1st students are direct friends, the 1st and 2nd
 * students are direct friends, so the 0th and 2nd students are indirect
 * friends. All of them are in the same friend circle, so return 1.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * N is in range [1,200].
 * M[i][i] = 1 for all students.
 * If M[i][j] = 1, then M[j][i] = 1.
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
// class Solution {
// public:
//     // BFS
//     int findCircleNum(vector<vector<int>>& M) {
//         int res = 0;
//         if(M.size() == 0){
//             return res;
//         }
//         int len = M.size();
//         queue<int> Q;
//         for(int i = 0; i < len; i++){
//             if(M[i][i] == 1){
//                 M[i][i] = 0;
//                 res++;
//                 Q.push(i);
//                 while (!Q.empty())
//                 {
//                     int index = Q.front();
//                     Q.pop();
//                     for(int k = 0; k < len; k++){
//                         if(M[index][k] == 1){
//                             Q.push(k);
//                             M[index][k] = 0;
//                             M[k][index] = 0;
//                         }
//                     }
//                 }
//             }
//         }
//         return res;
//     }
// };

// forget everything about BFS, use Union Find
class UnionFindSet{
private:
    vector<int> ranks_, parents_;
    int groups;
public:
    UnionFindSet(int n){
        ranks_ = vector<int>(n+1, 0);
        parents_ = vector<int>(n+1, 0);
        for(int i = 0; i < parents_.size(); i++){
            parents_[i] = i;
        }
        groups = n;
    }
    bool Union(int u, int v){
        int uRoot = Find(u);
        int vRoot = Find(v);
        if(vRoot == uRoot) return false;
        if(ranks_[uRoot] < ranks_[vRoot])
            parents_[uRoot] = vRoot;
        else if(ranks_[uRoot] > ranks_[vRoot])
            parents_[vRoot] = uRoot;
        else // uRoot == vRoot
        {
            parents_[uRoot] = vRoot;
            ranks_[vRoot]++;
        }
        groups--;
        return true;
    }
    int Find(int u){
        if(parents_[u] != u){
            parents_[u] = Find(parents_[u]);
        }
        return parents_[u];
    }
    int getGroupNum(){
        return groups;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        UnionFindSet s(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(M[i][j]) s.Union(i,j);
            }
        }
        
        // unordered_set<int> groups;
        // for(int i = 0; i < n; i++){
        //     groups.insert(s.Find(i));
        // }

        return s.getGroupNum();
    }
};
// @lc code=end

