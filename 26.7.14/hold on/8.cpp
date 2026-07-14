#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    stack<int> s;
    while (n > 0) {
        s.push(n % 2);
        n /= 2;
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
    return 0;
}