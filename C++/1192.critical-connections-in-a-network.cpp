/*
 * @lc app=leetcode id=1192 lang=cpp
 *
 * [1192] Critical Connections in a Network
 *
 * https://leetcode.com/problems/critical-connections-in-a-network/description/
 *
 * algorithms
 * Hard (46.89%)
 * Likes:    272
 * Dislikes: 29
 * Total Accepted:    12.1K
 * Total Submissions: 25.3K
 * Testcase Example:  '4\n[[0,1],[1,2],[2,0],[1,3]]'
 *
 * There are n servers numbered from 0 to n-1 connected by undirected
 * server-to-server connections forming a network where connections[i] = [a, b]
 * represents a connection between servers a and b. Any server can reach any
 * other server directly or indirectly through the network.
 * 
 * A critical connection is a connection that, if removed, will make some
 * server unable to reach some other server.
 * 
 * Return all critical connections in the network in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
 * Output: [[1,3]]
 * Explanation: [[3,1]] is also accepted.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^5
 * n-1 <= connections.length <= 10^5
 * connections[i][0] != connections[i][1]
 * There are no repeated connections.
 * 
 * 
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
private:
    struct GraphNode
    {
        int label;
        int degree = 0;
        vector<GraphNode*> neighbours;
        GraphNode(int x): label(x) {};
    };

    int time = 0;

    void dfs(int u, vector<int>& index, vector<int>& low, vector<GraphNode*>& graph, vector<vector<int>>& res, int pre){
        /*
        u: the current node
        pre: the previous node of u
        res: contains the edges that is critical
        */
        index[u] = time;
        low[u] = time;
        time++;
        // go through the neighbours of node u
        for(int i = 0; i < graph[u]->neighbours.size(); i++){
            int v = graph[u]->neighbours[i]->label;
            if(v == pre)
                continue;
            // means that node v has not been visited yet
            if(index[v] == -1){
                dfs(v, index, low, graph, res, u);
                // update the low vector
                low[u] = min(low[u], low[v]);
                // this means that u is in a circle and v is not in this circle
                if(index[u] < low[v]){
                    res.push_back(vector<int>{u,v});
                }
            }
            else // v has been visited before
            {
                // update the low vector
                low[u] = min(low[u], low[v]);
            }
        }
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        if(n <= 1) return vector<vector<int>> {};
        vector<int> index(n,-1);
        // low vector means the most 
        vector<int> low(n,-1);
        vector<vector<int>> res;
        vector<GraphNode*> graph;
        // initialize the graph
        for(int i = 0; i < n; i++){
            graph.push_back(new GraphNode(i));
        }
        // add the edges to the graph
        for(int i = 0; i < connections.size(); i++){
            graph[connections[i][0]]->neighbours.push_back(graph[connections[i][1]]);
            graph[connections[i][1]]->neighbours.push_back(graph[connections[i][0]]);
        }
        for(int i = 0; i < n; i++){
            if(index[i] == -1){
                // if the node hasn't been visited
                dfs(i, index, low, graph, res, i);
            }
        }
        return res;
    }
};
// @lc code=end

