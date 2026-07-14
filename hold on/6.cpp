#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> primes;
    for (int i = 2; i <= N; ++i) {
        bool isPrime = true;
        for (int j = 0; j < primes.size(); ++j) {
            if (i % primes[j] == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            primes.push_back(i);
        }
    }
    for (int i = 0; i < primes.size(); ++i) {
        cout << setw(5) << primes[i];
        if ((i + 1) % 10 == 0) cout << endl;
    }
    if (primes.size() % 10 != 0) cout << endl;
    return 0;
}