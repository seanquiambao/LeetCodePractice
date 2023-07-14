#include <bits/stdc++.h>
using namespace std;

template<typename A> void WRITE(A x) {
	cout << x;
}

template<typename H, typename... T> void WRITE(const H& h, const T&... t) { 
	WRITE(h);
	WRITE(t...);
}

void PRINT() {
	WRITE("\n");
}

template<typename H, typename... T> void PRINT(const H& h, const T&... t) { 
	WRITE(h);
	if(sizeof...(t))
		WRITE(' ');
	PRINT(t...);
}

template<typename T> void PRINT_ARRAY(const vector<T>& vec) {
    for(int i = 0; i < vec.size(); ++i) {
        if(i != 0) { cout << " "; }
        cout << vec[i];
    }
    cout << "\n";
}

template <typename T> void PRINT_ARRAY(const std::vector< std::vector<T> >& vec) {
    for(int i = 0; i < vec.size(); ++i) {
        for(int j = 0; j < vec[0].size(); ++j) {
            if(j != 0) { cout << " "; }
            cout << vec[i][j];
        }
        cout << "\n";
    }
}

template <typename T> T CONVERT(string& t) {
    if(typeid(T) == typeid(int)) { return stoi(t); }
    else if(typeid(T) == typeid(double)) { return stod(t); }
    else if(typeid(T) == typeid(char)) { return t[0]; }
    throw invalid_argument("Unknown datatype.");
}


template <typename T> void PUSH_ELEMENTS(vector<T>& arr, string& t) {
    t = t.substr(1, t.size() - 2);
    stringstream ss(t);
    string argument;

    while(!ss.eof()) {
        getline(ss, argument, ',');
        T x = CONVERT<T>(argument);
        arr.push_back(x);
    }
}

void PUSH_ELEMENTS(vector<string>& arr, string& t) { 
    t = t.substr(1, t.size() - 2);
    string argument;
    

    auto b = t.begin(), e = t.end();
    while((b = find(b,e,'\"')) != e) {
        ++b;
        auto n_start = b;
        b = find(b,e,'\"');
        argument = string(n_start, b);
        arr.push_back(argument);
        ++b;

    }
}

void PUSH_ELEMENTS(vector<char>& arr, string& t) { 
    t = t.substr(1, t.size() - 2);
    string argument;
    

    auto b = t.begin(), e = t.end();
    while((b = find(b,e,'\"')) != e) {
        ++b;
        auto n_start = b;
        b = find(b,e,'\"');
        argument = string(n_start, b);
        char x = CONVERT<char>(argument);
        arr.push_back(x);
        ++b;

    }
}

template <typename T> void READ(T& x) {
    cin >> x;
}

template <typename T> void READLINE(T& x) {
    getline(cin, x);
}

template <typename T> void POPULATE(vector<T>& arr, string& input) {
    if(input[0] != '[' || input[input.size() - 1] != ']') { throw invalid_argument("Must be a valid array."); }
    PUSH_ELEMENTS(arr, input);
    
}


template <typename T> void POPULATE(vector<vector<T>>& arr, string& input) {
    if(input[0] != '[' || input[input.size() - 1] != ']') { throw invalid_argument("Must be in a valid matrix format."); }
    input = input.substr(1,input.size() - 2);
    string argument;
    vector<T> temp;

    auto b = input.begin(), e = input.end();
    while((b = find(b,e,'[')) != e) {
        temp.clear();
        auto n_start = b;
        b = find(b,e,']');
        argument = string(n_start, ++b);
        PUSH_ELEMENTS(temp, argument);
        arr.push_back(temp);
        ++b;

    }
}

typedef queue<pair<int,int>> queuePair;
typedef vector<vector<int>> matrixInt;
typedef vector<vector<char>> matrixChar;
class Solution {
public:
    vector<vector<int>> DIRS = {{0,-1},{1,0},{0,1},{-1,0}};
    bool canGo(int i, int j, int n, int m) {
        return i>=0&&i<n&&j>=0&&j<m;
    }
    void BFS(queuePair q, matrixInt& visited, matrixChar board) {
        int n = visited.size(), m = visited[0].size();
        while(!q.empty()) {
            pair<int,int> currentPosition = q.front();
            int ai = currentPosition.first, aj = currentPosition.second;
            q.pop();
            visited[ai][aj] = 1;

            for(int i = 0; i < DIRS.size(); ++i) {
                int ni = ai + DIRS[i][1], nj = aj + DIRS[i][0];
                if(canGo(ni,nj,n,m) && board[ni][nj] == 'O' && !visited[ni][nj]) {
                    q.push({ni,nj});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        queuePair q;
        int n = board.size(), m = board[0].size();
        matrixInt visited(n, vector<int>(m, 0));

        for(int i = 0; i < n; ++i) {
            if(i == 0 || i == n - 1) {
                for(int j = 0; j < m; ++j) {
                    if(board[i][j] == 'O') { q.push({i,j}); }
                }
            }
            else {
                if(board[i][0] == 'O') { q.push({i,0}); }
                if(board[i][m - 1] == 'O') { q.push({i, m - 1}); }
            }
        }

        BFS(q, visited, board);

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                board[i][j] = (!visited[i][j] && (board[i][j] == 'O')) ? 'X' : board[i][j];
            }
        }

        

    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    int cases;
    string input;
    vector<vector<char>> matrix;

    READ(cases);
    cin.ignore();

    for(int i = 0; i < cases; ++i) {
        matrix.clear();
        READLINE(input);
        POPULATE(matrix, input);
        WRITE("Case #", i+1, ": ");
        sol.solve(matrix);
        PRINT_ARRAY(matrix);
        // Collect inputs in this for loop.
        // PRINT(sol.functionName(...inputs));
    }

    

    return 0;
}