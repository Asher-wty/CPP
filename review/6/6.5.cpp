#include<iostream>
using namespace std;
template <typename T>
bool isEqualTo(T a, T b){
    if(a==b) return true;
    return false;
}
class SomeClass{
    int a;
    double b;
    public:
        SomeClass(int A=0, double B=0.0): a(A), b(B) {};
        bool operator ==(SomeClass t){
            if(a==t.a && b==t.b) return true;
            return false;
        }
        friend istream & operator >>(istream & in, SomeClass& t);
        friend ostream & operator <<(ostream & out,SomeClass t);
};
istream & operator >>(istream & in, SomeClass& t){
    in>>t.a>>t.b;
    return in;
}
ostream & operator <<(ostream & out,SomeClass t){
    out<<'('<<t.a<<','<<t.b<<')';
    return out;
}
//StudybarCommentBegin
int main()
{
    int a; // integers used for
    int b; // testing equality

    // test if two ints input by user are equal
    //    cout << "Enter two integer values: ";
    cin >> a >> b;

    char c; // chars used for
    char d; // testing equality

    // test if two chars input by user are equal
    //    cout << "\nEnter two character values: ";
    cin >> c >> d;

    double e; // double values used for
    double f; // testing equality

    // test if two doubles input by user are equal
    //    cout << "\nEnter two double values: ";
    cin >> e >> f;

    SomeClass g(1, 1.1); // SomeClass objects used
    SomeClass h;         // for testing equality

    cin >> h;

    cout << a << " and " << b << " are "
         << (isEqualTo(a, b) ? "equal" : "not equal") << '\n';

    cout << c << " and " << d << " are "
         << (isEqualTo(c, d) ? "equal" : "not equal") << '\n';

    cout << e << " and " << f << " are "
         << (isEqualTo(e, f) ? "equal" : "not equal") << '\n';

    // test if two SomeClass objects are equal
    // uses overloaded << operator
    cout << "The class objects " << g << " and " << h << " are "
         << (isEqualTo(g, h) ? "equal" : "not equal") << '\n';

    return 0;

} // end main

//StudybarCommentEnd