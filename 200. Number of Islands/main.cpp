#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> DIRS = {{0,-1},{1,0},{0,1},{-1,0}};

class Solution {
public:
    void BFS(vector<vector<char>> grid, vector<vector<int>>& visitedCells, int y, int x) {
        queue<pair<int,int>> q;
        visitedCells[y][x] = 1;
        q.push({x,y});

        while(!q.empty()) {
            int ax = q.front().first, ay = q.front().second;
            q.pop();

            for(int i = 0; i < DIRS.size(); ++i)  {
                int nx = ax + DIRS[i][0], ny = ay + DIRS[i][1];
                if(nx>=0&&nx<grid[0].size()&&ny>=0&&ny<grid.size()&&grid[ny][nx]=='1'&&!visitedCells[ny][nx]) { 
                    q.push({nx,ny});
                    visitedCells[ny][nx] = 1;
                }            
            }
            
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) { return 0; }

        int count = 0;
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> visited(row, vector<int>(col,0));

        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(grid[i][j] == '1' && visited[i][j] == 0) {
                    ++count;
                    BFS(grid, visited, i, j);
                }
            }
        }

        return count;


    }
};



int main() {

    Solution sol;

    vector<vector<char>> map1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    vector<vector<char>> map2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    vector<vector<char>> map3 = { {'1','0','1','1','0','1','1'} };



    std::cout << sol.numIslands(map1) << endl;

    std::cout << sol.numIslands(map2) << endl;

    std::cout << sol.numIslands(map3) << endl;


    return 0;
}