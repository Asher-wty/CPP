#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin.ignore(5);
    getline(cin, str);
    cout << str << endl;
    return 0;
}