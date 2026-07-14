#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main() {
    map<int, int> mp; // power -> id
    mp[1000000000] = 1;
    int n;
    cin >> n;
    while (n--) {
        int id, power;
        cin >> id >> power;
        auto it = mp.lower_bound(power);
        int oppId;
        if (it == mp.begin()) {
            oppId = it->second;
        } else if (it == mp.end()) {
            oppId = prev(it)->second;
        } else {
            auto prevIt = prev(it);
            int diff1 = power - prevIt->first;
            int diff2 = it->first - power;
            if (diff1 <= diff2) {
                oppId = prevIt->second;
            } else {
                oppId = it->second;
            }
        }
        cout << id << " " << oppId << endl;
        mp[power] = id;
    }
    return 0;
}