#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>

using namespace std;

struct GraphNodes{
    int label;
    vector<GraphNodes*> neighbors;
    GraphNodes(int x) : label(x) {};
};

void DFS(GraphNodes* node, vector<int>& visit){
    visit[node->label] = 1;
    printf("%d", node->label);
    for(int i = 0; i < node->neighbors.size(); i++){
        if(visit[node->neighbors[i]->label == 0]){
            DFS(node->neighbors[i], visit);
        }
    }
}

void BFS(GraphNodes* node, vector<int>& visit){
    queue<GraphNodes*> Q;
    Q.push(node);
    visit[node->label] = 1;
    while(!Q.empty()){
        GraphNodes* temp = Q.front();
        Q.pop();
        for(int i = 0; i < temp->neighbors.size(); i++){
            if(visit[temp->neighbors[i]->label] = 0){
                Q.push(temp->neighbors[i]);
                visit[temp->neighbors[i]->label] = 1;
            }
        }
    }
}