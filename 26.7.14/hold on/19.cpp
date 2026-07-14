#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>
#include <cstdlib>
using namespace std;

bool cmp(pair<double, string> a, pair<double, string> b) {
    return a.first < b.first;
}

int main() {
    string token;
    set<double> seen;
    vector<pair<double, string> > uniques;
    int i;
    
    while (cin >> token) {
        double val = atof(token.c_str());
        if (val == 0.0) break;
        
        if (seen.find(val) != seen.end()) {
            cout << "  " << token << " is duplicated" << endl;
        } else {
            seen.insert(val);
            uniques.push_back(make_pair(val, token));
        }
    }
    
    if (uniques.empty()) return 0;
    
    sort(uniques.begin(), uniques.end(), cmp);
    
    double minVal = uniques.front().first;
    double maxVal = uniques.back().first;
    double medium = (minVal + maxVal) / 2.0;
    
    vector<string> leMedium, geMedium;
    for (i = 0; i < (int)uniques.size(); ++i) {
        if (uniques[i].first <= medium) leMedium.push_back(uniques[i].second);
        if (uniques[i].first >= medium) geMedium.push_back(uniques[i].second);
    }
    
    cout << "  <= medium:";
    for (i = 0; i < (int)leMedium.size(); ++i) {
        cout << " " << leMedium[i];
    }
    cout << endl;
    
    cout << "  >= medium:";
    for (i = 0; i < (int)geMedium.size(); ++i) {
        cout << " " << geMedium[i];
    }
    cout << endl;
    
    return 0;
}