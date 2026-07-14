#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <cstdlib>
using namespace std;

vector<string> strings;

bool isInteger(const string& s, int& val) {
    if (s.empty()) return false;
    for (size_t i = 0; i < s.size(); ++i)
        if (!isdigit(s[i])) return false;
    if (s.size() > 5) return false;
    val = stoi(s);
    return val >= 0 && val <= 99999;
}

int parseInt(vector<string>& tokens, int& pos);
string parseString(vector<string>& tokens, int& pos);

string parseString(vector<string>& tokens, int& pos) {
    string tok = tokens[pos++];
    if (tok == "copy") {
        int N = parseInt(tokens, pos);
        int X = parseInt(tokens, pos);
        int L = parseInt(tokens, pos);
        return strings[N].substr(X, L);
    } else if (tok == "add") {
        string s1 = parseString(tokens, pos);
        string s2 = parseString(tokens, pos);
        int v1, v2;
        bool b1 = isInteger(s1, v1);
        bool b2 = isInteger(s2, v2);
        if (b1 && b2) return to_string(v1 + v2);
        else return s1 + s2;
    } else {
        return tok;
    }
}

int parseInt(vector<string>& tokens, int& pos) {
    string tok = tokens[pos++];
    if (tok == "find") {
        string S = parseString(tokens, pos);
        int N = parseInt(tokens, pos);
        size_t f = strings[N].find(S);
        if (f == string::npos) return (int)strings[N].size();
        else return (int)f;
    } else if (tok == "rfind") {
        string S = parseString(tokens, pos);
        int N = parseInt(tokens, pos);
        size_t f = strings[N].rfind(S);
        if (f == string::npos) return (int)strings[N].size();
        else return (int)f;
    } else {
        return stoi(tok);
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    strings.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        getline(cin, strings[i]);
    }
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        istringstream iss(line);
        vector<string> tokens;
        string w;
        while (iss >> w) tokens.push_back(w);
        if (tokens.empty()) continue;
        string cmd = tokens[0];
        if (cmd == "over") break;
        int pos = 1;
        if (cmd == "insert") {
            string S = parseString(tokens, pos);
            int N = parseInt(tokens, pos);
            int X = parseInt(tokens, pos);
            strings[N].insert(X, S);
        } else if (cmd == "reset") {
            string S = parseString(tokens, pos);
            int N = parseInt(tokens, pos);
            strings[N] = S;
        } else if (cmd == "print") {
            int N = parseInt(tokens, pos);
            cout << strings[N] << endl;
        } else if (cmd == "printall") {
            for (int i = 1; i <= n; ++i)
                cout << strings[i] << endl;
        }
    }
    return 0;
}