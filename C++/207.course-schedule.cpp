/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{

private:
    struct GraphNode
    {
        int label;
        vector<GraphNode *> neighbors;
        GraphNode(int x) : label(x){};
    };

    bool DFS(GraphNode *node, vector<int> &visit)
    {
        visit[node->label] = 0;
        // cout s<< node->neighbors.size();
        for (int i = 0; i < node->neighbors.size(); i++)
        {
            // if the neighbour is not visited
            if (visit[node->neighbors[i]->label] == -1)
            {
                bool temp_res = DFS(node->neighbors[i], visit);
                // cout << temp_res << endl;
                if(!temp_res)
                    return false;
            }
            else if(visit[node->neighbors[i]->label] == 0)
                return false;
        }
        visit[node->label] = 1;
        return true;
    }

public:
    // using DFS
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // visit[i] = 0 means not visited, 1 means being visited, 2 means visited
        // cout << prerequisites[0][0] << prerequisites[0][1] << endl;
        vector<int> visit(numCourses, -1);
        vector<GraphNode *> graph;
        // define the vertex of the graph, which is each course.
        for (int i = 0; i < numCourses; i++)
        {
            graph.push_back(new GraphNode(i));
        }
        // define the edges of the graph, which is the prerequisites, from pre to current course.
        for (int i = 0; i < prerequisites.size(); i++)
        {
            graph[prerequisites[i][1]]->neighbors.push_back(graph[prerequisites[i][0]]);
        }
        // now begin the DFS
        for (int i = 0; i < numCourses; i++)
        {
            if(visit[i] == -1){
                bool temp_res = DFS(graph[i], visit);
                if(!temp_res) return false;
            }
        }
        for(int i = 0; i < numCourses; i++){
            delete graph[i];
        }
        return true;
    }

    // // using BFS
    // bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // }
};

// int main()
// {
//     vector<vector<int>> input;
//     vector<int> input1 {0,1};
//     vector<int> input2 {1,0};
//     input.push_back(input1);
//     // input.push_back(input2);
//     Solution S;
//     bool res = S.canFinish(2, input);
//     cout << res;
//     return 0;
// }
