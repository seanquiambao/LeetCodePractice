#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combination(vector<vector<int>>& ans, vector<int>& combo, vector<int>& candidates, int target) {
        
        if(target == 0) {
            ans.push_back(combo);
            return ans; 
        }
        else if(target < 0) {
            return ans;
        }
        for(int i = 0; i < candidates.size(); ++i) {
            if(combo.empty() || (candidates[i] >= combo.back())) {
                combo.push_back(candidates[i]);
                combination(ans, combo, candidates, target - candidates[i]);
                combo.pop_back();
            }
        }

        return ans;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> wa;

        sort(candidates.begin(), candidates.end());

        return combination(answer, wa, candidates, target);
    }
};

int main() {

    Solution sol;
    vector<int> candidates = {3,5,8};

    vector<vector<int>> ans = sol.combinationSum(candidates, 11);


    for(int i = 0; i < ans.size(); ++i) {
        for(int j = 0; j < ans[i].size(); ++j) { cout << ans[i][j] << ", "; }
        cout << endl;
    }


    return 0;
}