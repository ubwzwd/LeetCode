/*
 * @lc app=leetcode id=778 lang=cpp
 *
 * [778] Swim in Rising Water
 */
#include <vector>
using namespace std;
// class Solution {
// private:
//     vector<int> uf;
//     vector<int> rank;
//     // total is the total number
//     int row, col, total;
//     // initialize the set with each node in different sets, all the rank is 1
//     void init(){
//         uf.clear();
//         for(int i = 0; i < total; i++){
//             uf.push_back(i);
//             rank.push_back(1);
//         }
//     }
//     int find(int x){
//         // // if x is the root
//         // if(uf[x] == x)
//         //     return x;
//         // // if x is not the root
//         // else{
//         //     uf[x] = this->find(uf[x]);
//         //     return uf[x];
//         // }
//         return uf[x]==x ? x : uf[x] = find(uf[x]);
//     }

//     void unionMember(int x, int y){
//         // find the set of x and y
//         // cout << x << y;
//         int fx = find(x), fy = find(y);
//         if(fx == fy) return;
//         // if the set of fy is larger, put the root of x into the set of y
//         if(rank[fx] < rank[fy]){
//             uf[fx] = fy;
//             rank[fy] += rank[fx];
//         }
//         else{
//             uf[fy] = fx;
//             rank[fx] += rank[fy];
//         }
//         // uf[fx] = fy;
//     }

//     int id(int x, int y){
//         return x*this->col + y;    
//     }
//     const int dx[4] = {0,0,-1,1};
//     const int dy[4] = {-1,1,0,0};

// public:
//     int swimInWater(vector<vector<int>>& grid) {
//         this->row = grid.size();
//         this->col = this->row;
//         this->total = this->row * this->col;
//         // vec stores the (x,y) for every according value
//         vector<pair<int,int>> vec(total);
//         for(int x = 0; x < row; x++){
//             for(int y = 0; y < col; y++){
//                 vec[grid[x][y]] = make_pair(x,y);
//                 // cout << grid[x][y] << endl;
//             }
//         }
//         this->init();
//         for(int i = 0; i < total; i++){
//             int nx = vec[i].first, ny = vec[i].second;
//             for(int j = 0; j < 4; j++){
//                 int x = dx[j]+nx, y = dy[j]+ny;
                
//                 if(x<0||x>=row||y<0||y>=col) continue;
//                 // cout << grid[x][y]  << i << endl;
//                 if(grid[x][y] > i) continue;
//                 // cout << nx << ny << endl;
//                 // cout << id(nx,ny) << endl;
//                 unionMember(id(nx,ny), id(x,y));
//                 if(find(0) == find(this->total-1)) {
//                     // cout << find(this->total-1) << find(0) << total-1;
//                     return i;
//                 }
//             }
//         }
//         return -1;
//     }
// };

class Solution{
private:
    vector<vector<int>> visit;
    bool check(int mid, int n, vector<vector<int>> &g){
        visit.assign(n, vector<int>(n,0));
        visit[0][0] = 1;
        dfs(0,0,mid, g);
        return visit[n-1][n-1];
    }
    int dx[4] {0,0,-1,1};
    int dy[4] {-1,1,0,0};
    void dfs(int x, int y, int mid, vector<vector<int>>& g){
        
    }
public:
    int swimInWater(vector<vector<int>>& grid){
        int n = grid.size();
        int l = 0, r = n*n-1;
        int mid, ans = r;
        while(l<=r){
            mid = (r-l)/2+l;
            if(check(mid, n, grid)){
                ans = min(ans, mid);
                r = mid-1;
            }
        }
    }
};