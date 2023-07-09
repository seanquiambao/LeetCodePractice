#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int longestSubstringSize = 0;
        int currentSubstringSize = 0;

        for(int i = 0; i < s.size(); ++i) {
            if(hash.find(s[i]) == hash.end()) {
                ++currentSubstringSize;
                hash.insert({s[i], i});
            }
            else {
                if(currentSubstringSize > longestSubstringSize) longestSubstringSize = currentSubstringSize;
                currentSubstringSize = 0;
                i = hash.at(s[i]);
                hash.clear();
                
            }
        }

        return (currentSubstringSize > longestSubstringSize) ? currentSubstringSize : longestSubstringSize;

    }
    
};

int main() {

    Solution sol;

    cout << sol.lengthOfLongestSubstring("dvdf") << endl;
    return 0;
}