#include <iostream>
#include <stack>
#include <string>

using namespace std;

#define TEST(a, b)                   \
(a == b ?                    \
to_string(a) + "\t\t PASS" : \
to_string(a) + "\t\t FAIL" + " Correct: " + to_string(b))
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> stack;

        int currentLength = 0;
        int possibleLength = 0;
        int longestLength = 0;

        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(') stack.push(s[i]);
            else if(s[i] == ')' && stack.empty()) {
                if(possibleLength > longestLength) longestLength = possibleLength;
                currentLength = 0;
                possibleLength = 0;
            }
            else {
                stack.pop();
                currentLength += 2;
                if(stack.empty()){
                    possibleLength += currentLength;
                    currentLength = 0;
                }
                
            }
        }

        if(!stack.empty() && currentLength > possibleLength) possibleLength = currentLength;

        if(possibleLength > longestLength) longestLength = possibleLength;
        return longestLength;
    }
};

int main() {
    Solution sol;

    string s1 = ")()())()()(";
    string s2 = ")()())";
    string s3 = "((()())";
    string s4 = "()((())";
    string s5 = "(()(((()";
    cout << s1 << " --- " << TEST(sol.longestValidParentheses(s1), 4) << endl;
    cout << s2 << " --- " << TEST(sol.longestValidParentheses(s2), 4) << endl;
    cout << s3 << " --- " << TEST(sol.longestValidParentheses(s3), 6) << endl;
    cout << s4 << " --- " << TEST(sol.longestValidParentheses(s4), 4) << endl;
    cout << s5 << " --- " << TEST(sol.longestValidParentheses(s5), 2) << endl;
    return 0;
}