#include <iostream>
#include <vector>
#include <random>
#include <cmath>
using namespace std;

int simulate(int t, mt19937& gen) {
    uniform_int_distribution<> dist(500, 2000);
    vector<int> births;
    births.push_back(0);
    int splits = 0;
    while (!births.empty()) {
        int birth = births.back();
        births.pop_back();
        int split_time = birth + dist(gen);
        if (split_time <= t) {
            ++splits;
            births.push_back(split_time);
            births.push_back(split_time);
        }
    }
    return 1 + splits;
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    int t;
    cin >> t;
    const int N = 100000;
    double sum = 0;
    for (int i = 0; i < N; ++i)
        sum += simulate(t, gen);
    cout << round(sum / N) << endl;
    return 0;
}