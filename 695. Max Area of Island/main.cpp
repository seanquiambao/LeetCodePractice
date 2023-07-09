#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> DIRS = {{0,-1},{1,0},{0,1},{-1,0}};
    int areaIslandBFS(vector<vector<int>> grid, vector<vector<int>>& visited, int y, int x) {
        queue<pair<int,int>> q;
        q.push({x,y});
        visited[y][x] = 1;
        int n = grid.size(), m = grid[0].size();
        int area = 1;

        while(!q.empty()) {
            int ax = q.front().first, ay = q.front().second;
            q.pop();

            for(int i = 0; i < DIRS.size(); ++i) {
                int nx = ax + DIRS[i][0], ny = ay + DIRS[i][1];
                if(nx>=0 && nx<m && ny >= 0 && ny < n && grid[ny][nx] && !visited[ny][nx]) { 
                    visited[ny][nx] = 1;
                    area += visited[ny][nx];
                    q.push({nx,ny});
                }
            }

        }

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int currentMax = 0;
        vector<vector<int>> visitedCells(row, vector<int>(col, 0));

        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(grid[i][j] && !visitedCells[i][j]) { currentMax = max(currentMax, areaIslandBFS(grid, visitedCells, i, j)); }
            }   
        }

        return currentMax;
    }
};



int main() {

    Solution sol;

    vector<vector<int>> map1 = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}};



    cout << sol.maxAreaOfIsland(map1) << endl;



    return 0;
}