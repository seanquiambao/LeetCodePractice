#include <iostream>

using namespace std;



class Solution {
public:
    bool detectCapitalUse(string word) {
        bool allLowerCase = true;
        bool allUpperCase = true;
        for(int i = 1; i < word.size(); ++i) {
            if(islower(word[i])) allUpperCase = false;
            if(isupper(word[i])) allLowerCase = false;
        }

        if(islower(word[0]) && allUpperCase) allUpperCase = false;
        return (allLowerCase || allUpperCase) ? true : false;
    }
};


int main() {

    Solution sol;

    cout << "Case #1: " << sol.detectCapitalUse("USA") << endl;
    cout << "Case #2: " << sol.detectCapitalUse("uSA") << endl;
    cout << "Case #3: " << sol.detectCapitalUse("Usa") << endl;
    cout << "Case #4: " << sol.detectCapitalUse("UsA") << endl;
    cout << "Case #5: " << sol.detectCapitalUse("usa") << endl;

    return 0;
}