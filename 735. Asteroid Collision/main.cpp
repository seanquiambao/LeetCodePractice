#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> finalAsteroids;

        for(int i = 0; i < asteroids.size(); ++i) {
            if(st.empty() || asteroids[i] > 0) { st.push(asteroids[i]); }
            else {
                while(!st.empty() && st.top() > 0 && asteroids[i] < 0 && st.top() < abs(asteroids[i])) {
                    st.pop();
                }
                if(st.empty() || st.top() < 0) { st.push(asteroids[i]); }
                else if(st.top() == abs(asteroids[i])) { st.pop(); }
            }
        }

        while(!st.empty()) { 
            finalAsteroids.push_back(st.top());
            st.pop();
        }
        

        return finalAsteroids;

    }
};

int main() {

    Solution sol;

    vector<int> arr = {-2,-1,1,2};

    vector<int> ans = sol.asteroidCollision(arr);

    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ,";
    }


    return 0;
}