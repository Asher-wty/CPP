#include <iostream>
#include <cmath>
int gcd(int a, int b){
    while(b!=0){
        int t=a%b;
        a=b;
        b=t;
    }
    return a;
}
using namespace std;
class Fraction{
    int z,m;
    public:
        Fraction(int a=1, int b=1): z(a), m(b){
            int t=gcd(z,m);
            z/=t;
            m/=t;
        }
        Fraction operator +(const Fraction& other){
            Fraction t;
            t.z=z*other.m+m*other.z;
            t.m=m*other.m;
            int a=gcd(t.z,t.m);
            t.z/=a;
            t.m/=a;
            return t;
        }
        bool operator ==(const Fraction& t){
            return (z==t.z && m==t.m);
        }
        void print(){
            if(m<0){
                m*=-1;
                z*=-1;
            }
            cout<<z<<'/'<<m;
        }
};

//StudybarCommentBegin
int main() {
    int n1, d1, n2, d2;
    cin >> n1 >> d1;
    cin >> n2 >> d2;

    Fraction f1(n1, d1);
    Fraction f2(n2, d2);
    Fraction sum = f1 + f2;

    cout << "f1 = "; f1.print(); cout << endl;
    cout << "f2 = "; f2.print(); cout << endl;
    cout << "f1 + f2 = "; sum.print(); cout << endl;

    if (f1 == f2)
        cout << "f1 和 f2 相等" << endl;
    else
        cout << "f1 和 f2 不相等" << endl;

    return 0;
}
//StudybarCommentEnd