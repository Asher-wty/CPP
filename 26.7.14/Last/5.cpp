#include <iostream>
using namespace std;
double divide(double a, double b) {
    if (b == 0)
        throw "Attempted to divide by zero!";
    return a / b;
}

int main() {
    double a, b;
    cin >> a >> b;
    try {
        double result = divide(a, b);
        cout << result << endl;
    }
    catch (const char* msg) {
        cout << msg << endl;
    }
    return 0;
}