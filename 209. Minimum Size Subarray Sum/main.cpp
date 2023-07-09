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

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0;
        int sz = nums.size();
        int sum = nums[0];
        int minSize = 0;

        while(i <= j) {
            if(sum >= target) {
                minSize = !minSize ? (j - i + 1) : minSize;
                minSize = min(minSize, j - i + 1);
                sum -= nums[i++];
            }
            else if( j != sz - 1) { sum += nums[++j]; }
            else { sum -= nums[i++]; }
        }

        return minSize;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    int cases;

    READ(cases);
    cin.ignore();

    int t;
    vector<int> arr;
    string input;

    for(int i = 0; i < cases; ++i) {
        arr.clear();
        WRITE("Case #", i+1, ": ");
        READ(t);
        cin.ignore();
        READLINE(input);
        POPULATE(arr, input);
        PRINT(sol.minSubArrayLen(t, arr));
        // PRINT(sol.functionName(...inputs));
    }

    

    return 0;
}