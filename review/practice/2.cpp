#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Student {
    int id;
    int height;
    int time;
};
int main() {
    int n;
    cin >> n;
    vector<Student> all;
    all.push_back({1, 160, 0});
    for (int i = 1; i <= n; ++i) {
        int id, h;
        cin >> id >> h;
        all.push_back({id, h, i});
    }
    sort(all.begin(), all.end(), [](const Student& a, const Student& b) {
        return a.height < b.height;
    });
    vector<pair<int,int>> ans(n + 1);
    for (int t = 1; t <= n; ++t) {
        int pos = -1;
        for (int i = 0; i < (int)all.size(); ++i) {
            if (all[i].time == t) {
                pos = i;
                break;
            }
        }
        int left = -1, right = -1;
        for (int i = pos - 1; i >= 0; --i) {
            if (all[i].time < t) {
                left = i;
                break;
            }
        }
        for (int i = pos + 1; i < (int)all.size(); ++i) {
            if (all[i].time < t) {
                right = i;
                break;
            }
        }
        int chosen = -1;
        if (left == -1) chosen = right;
        else if (right == -1) chosen = left;
        else {
            int dl = t == 0 ? 0 : all[pos].height - all[left].height; // t>0
            int dr = all[right].height - all[pos].height;
            if (dl < dr) chosen = left;
            else if (dl > dr) chosen = right;
            else {
                chosen = (all[left].time < all[right].time) ? left : right;
            }
        }
        ans[t] = {all[pos].id, all[chosen].id};
    }
    for (int t = 1; t <= n; ++t) {
        cout << ans[t].first << " " << ans[t].second << endl;
    }
    return 0;
}