#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string expr;
    getline(cin, expr);
    stack<char> s;
    bool valid = true;
    for (size_t i = 0; i < expr.size(); ++i) {
        char c = expr[i];
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (s.empty()) {
                valid = false;
                break;
            }
            char top = s.top();
            if ((c == ')' && top == '(') ||
                (c == ']' && top == '[') ||
                (c == '}' && top == '{')) {
                s.pop();
            } else {
                valid = false;
                break;
            }
        }
    }
    if (!s.empty()) valid = false;
    cout << (valid ? "true" : "false") << endl;
    return 0;
}