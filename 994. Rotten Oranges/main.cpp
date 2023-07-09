#include <bits/stdc++.h>

using namespace std;
struct hashFunction
{
  size_t operator()(const pair<int , 
                    int> &x) const
  {
    return x.first ^ x.second;
  }
};
  
class Solution {
public: // {x,y}
    vector<vector<int>> DIRS = {{0,-1},{1,0},{0,1},{-1,0}};

    int BFS(vector<vector<int>> grid, vector<vector<int>>& visited, queue<pair<int,int>>& q, unordered_set<pair<int,int>, hashFunction>& set) {
        int minutes = 1;
        int row = grid[0].size();
        int col = grid.size();
        
        while(!q.empty()) {
            int ai = q.front().first;
            int aj = q.front().second;
            set.erase(q.front());
            q.pop();

            minutes = max(minutes, visited[ai][aj]);
            

            for(int i = 0; i < DIRS.size(); ++i) {
                int ni = ai + DIRS[i][1];
                int nj = aj + DIRS[i][0];

                if(ni>=0&&ni<col&&nj>=0&&nj<row&&(grid[ni][nj] == 1)&&!visited[ni][nj]) {
                    q.push({ni,nj});
                    visited[ni][nj] = visited[ai][aj] + 1;
                }

            }
        }

        return minutes - 1;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> visitedCells(row, vector<int>(col, 0));
        queue<pair<int,int>> q;
        unordered_set<pair<int,int>, hashFunction> set;

        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 2) { 
                    q.push({i,j}); 
                    set.insert({i,j});
                    visitedCells[i][j] = 1;
                }
                else if(grid[i][j] == 1) { set.insert({i,j}); }
            }
        }

        int minutes = BFS(grid, visitedCells, q, set);




        return set.empty() ? minutes : -1;

    }
};

int main() {

    Solution sol;
    vector<vector<int>> arr1 = {{2,1,1},{0,1,1},{1,0,1}};


    cout << sol.orangesRotting(arr1) << endl;


    return 0;
}