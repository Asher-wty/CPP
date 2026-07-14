
//StudybarCommentBegin
#include <iostream>
#include<string>
using namespace std;
//StudybarCommentEnd

string indent = "              ";

void f2() {
    cout << "In f2 function" << endl;
    throw "Exception from f2";
}

void f1(int a, int b) {
    if (b == 0) throw 0;
    try {
        f2();
    }
    catch (const char* msg) {
        cout << indent << msg << endl;
    }
    cout << indent << a << "%" << b << "=" << a % b << endl;
    cout << indent << "In f1 function" << endl;
}

int main() {
    double x, y;
    cin >> x >> y;
    if (x != (int)x || y != (int)y) {
        try {
            throw "Non-int was inputted, try again";
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
        cout << indent << "In main function" << endl;
        return 0;
    }
    int a = (int)x;
    int b = (int)y;
    try {
        f1(a, b);
    }
    catch (int) {
        cout << "You inputted:" << b << endl;
    }
    cout << indent << "In main function" << endl;
    return 0;
}