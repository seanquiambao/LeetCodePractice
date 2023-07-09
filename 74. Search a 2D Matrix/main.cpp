#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int p = 0;
        int q = matrix.size() - 1;
        int end = matrix[0].size() - 1;
        int n = 0;
        int m = 0;
        
        while(p <= q) {
            n = (q - p) / 2;
            n += p;
            if(matrix[n][0] > target) { q = n - 1; }
            else if(matrix[n][end] < target) { p = n + 1; }
            else { break; }
        }
        p=0;

        while(p <= end) {
            m = (end - p) / 2;
            m += p;
            if(matrix[n][m] == target) { return true; }
            else if(matrix[n][m] > target) { end = m - 1; }
            else { p = m + 1; }
        }

        return false;
    }
};

int main() {

    Solution sol;
    //vector<vector<int>> arr1 = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    vector<vector<int>> arr2 = {{1},{3}};


    //cout << sol.searchMatrix(arr1, 10) << endl;
    cout << sol.searchMatrix(arr2, 3) << endl;


    return 0;
}