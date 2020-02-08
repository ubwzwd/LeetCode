/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 *
 * https://leetcode.com/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (49.49%)
 * Likes:    1788
 * Dislikes: 137
 * Total Accepted:    107.1K
 * Total Submissions: 215.1K
 * Testcase Example:  '[["a","b"],["b","c"]]\n' +
  '[2.0,3.0]\n' +
  '[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]'
 *
 * Equations are given in the format A / B = k, where A and B are variables
 * represented as strings, and k is a real number (floating point number).
 * Given some queries, return the answers. If the answer does not exist, return
 * -1.0.
 * 
 * Example:
 * Given  a / b = 2.0, b / c = 3.0.
 * queries are:  a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
 * return  [6.0, 0.5, -1.0, 1.0, -1.0 ].
 * 
 * The input is:  vector<pair<string, string>> equations, vector<double>&
 * values, vector<pair<string, string>> queries , where equations.size() ==
 * values.size(), and the values are positive. This represents the equations.
 * Return  vector<double>.
 * 
 * According to the example above:
 * 
 * 
 * equations = [ ["a", "b"], ["b", "c"] ],
 * values = [2.0, 3.0],
 * queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]
 * ]. 
 * 
 * 
 * 
 * The input is always valid. You may assume that evaluating the queries will
 * result in no division by zero and there is no contradiction.
 * 
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
//     pair<string, double> find(const string& A, unordered_map<string, pair<string, double>>& parents){
//         if(parents.at(A).first != A){
//             // got the parent of B, that is C, and B/C
//             pair<string, double> temp = find(parents.at(A).first, parents);
//             parents.at(A).first = temp.first;
//             // A/C = A/B * B/C
//             parents.at(A).second *= temp.second;
//         }
//         return parents.at(A);
//     }
// public:
//     vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//         int e_len = equations.size(), v_len = values.size(), q_len = queries.size();

//         // parents[A].first = B, parents[A].second = ratio, A/B = ratio
//         unordered_map<string, pair<string, double>> parents;

//         for(int i = 0; i < e_len; i++){
//             const string& A = equations[i][0];
//             const string& B = equations[i][1];
//             if(!parents.count(A) && !parents.count(B)){
//                 parents[A] = make_pair(B, values[i]);
//                 // make B to be the root
//                 parents[B] = make_pair(B, 1.0);
//             }
//             else if(!parents.count(A)){
//                 parents[A] = make_pair(B, values[i]);
//             }
//             else if(!parents.count(B)){
//                 parents[B] = make_pair(A, 1.0/values[i]);
//             }
//             else{
//                 // update A and B
//                 pair<string, double> tempA = find(A, parents);
//                 pair<string, double> tempB = find(B, parents);
//                 // merge the two parent
//                 // for A, tempA: parent of A: pA, and A/pA
//                 // for B, tempB: pB and B/pB
//                 // pA/pB = (B/pB)/(A/pA)*(A/B)
//                 parents.at(tempA.first) =  make_pair(tempB.first, tempB.second/tempA.second*values[i]);
//             }
//         }
//         vector<double> res(q_len, -1.0);
//         for(int i = 0; i < q_len; i++){
//             string& A = queries[i][0];
//             string& B = queries[i][1];            
//             if(!parents.count(A) || !parents.count(B)) continue;
//             if(A == B){
//                 res[i] = 1.0;
//                 continue;
//             }
//             pair<string, double> parentA = find(A, parents);
//             pair<string, double> parentB = find(B, parents);
//             // cout << A << ' ' << B << ' ' << parentA.second << ' ' << parentB.second << endl;
//             if(parentA.first == parentB.first){
//                 res[i] = parentA.second/parentB.second;
//             }
//         }
//         return res;
//     }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int e_len = equations.size(), q_len = queries.size();
        unordered_map<string, unordered_map<string, double>> graph;
        for(int i = 0; i < e_len; i++){
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = 1.0/values[i];
        }
        vector<double> res(q_len, -1.0);
        for(int i = 0; i < q_len; i++){
            const string& A = queries[i][0];
            const string& B = queries[i][1];
            if(!graph.count(A) || !graph.count(B)){
                continue;
            }
            unordered_set<string> visited;
            res[i] = calcEquationRec(A, B, graph, visited);
        }
        return res;
    }
private:
    // return A/B
    double calcEquationRec(const string& A, const string& B, unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& visited){
        if(A == B) return 1.0;
        visited.insert(A);
        for(auto& pair : graph[A]){
            const string& C = pair.first;
            if(visited.count(C)) continue;
            // d = C/B
            double d = calcEquationRec(C, B, graph, visited);
            // A/B = A/C * C/B
            if(d>0) return d*pair.second;
        }
        return -1;
    }
};
// @lc code=end

