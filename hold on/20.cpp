#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct Fraction {
    int a, b;
};

int gcd(int x, int y) {
    x = abs(x);
    y = abs(y);
    while (y) {
        int t = y;
        y = x % y;
        x = t;
    }
    return x;
}

void simplify(Fraction& f) {
    if (f.b < 0) {
        f.a = -f.a;
        f.b = -f.b;
    }
    int g = gcd(abs(f.a), f.b);
    f.a /= g;
    f.b /= g;
}

bool cmp(const Fraction& x, const Fraction& y) {
    return x.a * y.b < y.a * x.b;
}

int main() {
    int n;
    cin >> n;
    vector<Fraction> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].a >> v[i].b;
        simplify(v[i]);
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; ++i) {
        if (v[i].b == 1)
            cout << v[i].a << endl;
        else
            cout << v[i].a << "/" << v[i].b << endl;
    }
    return 0;
}