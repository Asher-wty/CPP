#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> odds, evens;
    int num;
    while (cin >> num) {
        if (num % 2 == 0)
            evens.push_back(num);
        else
            odds.push_back(num);
    }
    sort(odds.begin(), odds.end(), greater<int>());
    sort(evens.begin(), evens.end());
    bool first = true;
    for (int i = 0; i < odds.size(); ++i) {
        if (!first) cout << " ";
        cout << odds[i];
        first = false;
    }
    for (int i = 0; i < evens.size(); ++i) {
        if (!first) cout << " ";
        cout << evens[i];
        first = false;
    }
    return 0;
}