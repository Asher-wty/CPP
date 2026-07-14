#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int x, y;
    double d;
    cin >> x >> y >> d;
    cout << setw(x) << fixed << setprecision(y) << d << endl;
    return 0;
}