#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int evaluateNum(std::stack<int> &st) {
        int a = st.top();
        st.pop();
        int op = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if(op == 43) { return b + a; }
        else { return b - a; }
    }
    int calculate(string s) {
        std::stack<int> st;
        for(int i = 0; i < s.size(); ++i) {
            if (!st.empty() && isdigit(s[i]) && (st.top() == '+' || st.top() == '-')) { 
                int a = s[i] - '0';
                st.push(a);
                st.push(evaluateNum(st));
            }
            else if(!st.empty() && s[i] == ')') {
                int finalAnswer = st.top();
                st.pop();
                st.pop();
                if(!st.empty()) {
                    st.push(finalAnswer);
                    st.push(evaluateNum(st));
                }
                else { st.push(finalAnswer); }
                
            }
            else if(isdigit(s[i]) || s[i] == '+' || s[i] == '-' || s[i] == '('){ st.push(isdigit(s[i]) ? s[i] - '0' : s[i]); }
        }

        return st.top();
    }
};

int main() {

    Solution sol;
    cout << sol.calculate("-(2+5)") << endl;

    return 0;
}