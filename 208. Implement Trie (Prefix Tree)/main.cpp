#include <bits/stdc++.h>

using namespace std;
class Trie {
public:
    char letter;
    vector<Trie*> neighbors;
    Trie() {
        letter = ' ';
        neighbors = vector<Trie*>();
    }
    Trie(char ch) {
        letter = ch;
        neighbors = vector<Trie*>();
    }

    pair<Trie*, int> searchAlgo(Trie* curr, string word) {
        Trie* dest = curr;
        bool ok = 1;
        int j = 0;

        while(ok && j < word.size()) {
            ok = 0;
            for(int i = 0; i < dest->neighbors.size() && !ok; ++i) {
                if(dest->neighbors[i]->letter == word[j]) {
                    ok = 1;
                    j += ok;
                    dest = dest->neighbors[i];
                }
                
            } 
        }

        return {dest, j};
    }
    
    void insert(string word) {

        pair<Trie*, int> result = searchAlgo(this, word);
        Trie* curr = result.first;
        int j = result.second;

        for(int i = j; i < word.size(); ++i) {
            Trie* nnode = new Trie(word[i]);
            curr->neighbors.push_back(nnode);
            curr = nnode;
        }
        bool ok = 0;
        for(int i = 0; i < curr->neighbors.size() && !ok; ++i) { ok |= curr->neighbors[i]->letter == '!'; }
        if(!ok) { curr->neighbors.push_back(new Trie('!')); }
    }
    
    bool search(string word) {
        
        pair<Trie*, int> result = searchAlgo(this, word);
        Trie* curr = result.first;
        int j = result.second;
        if(j != word.size()) { return false; }
        for(int i = 0; i < curr->neighbors.size(); ++i) {
            if(curr->neighbors[i]->letter == '!') { return true; }
        }

        return false;
    }
    
    bool startsWith(string prefix) {
        pair<Trie*, int> result = searchAlgo(this, prefix);
        Trie* curr = result.first;
        int j = result.second;

        return j == prefix.size();
        
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int main() {

    Trie* trie = new Trie();
    trie->insert("hello");
    cout << trie->search("hell") << endl;
    cout << trie->search("helloa") << endl;
    cout << trie->search("hella") << endl;


    return 0;
}