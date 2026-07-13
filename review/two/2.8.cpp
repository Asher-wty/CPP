#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Rational {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    void simplify() {
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        if (numerator == 0) {
            denominator = 1;
            return;
        }
        int g = gcd(abs(numerator), denominator);
        numerator /= g;
        denominator /= g;
    }

public:
    Rational(int n = 0, int d = 1) {
        numerator = n;
        denominator = d;
        simplify();
    }

    void add(const Rational& a, const Rational& b) {
        numerator = a.numerator * b.denominator + b.numerator * a.denominator;
        denominator = a.denominator * b.denominator;
        simplify();
    }

    void minus(const Rational& a, const Rational& b) {
        numerator = a.numerator * b.denominator - b.numerator * a.denominator;
        denominator = a.denominator * b.denominator;
        simplify();
    }

    void multi(const Rational& a, const Rational& b) {
        numerator = a.numerator * b.numerator;
        denominator = a.denominator * b.denominator;
        simplify();
    }

    void divide(const Rational& a, const Rational& b) {
        numerator = a.numerator * b.denominator;
        denominator = a.denominator * b.numerator;
        simplify();
    }

    void printFormal() const {
        if (numerator < 0) {
            cout << "-" << -numerator << "/" << denominator;
        } else {
            cout << numerator << "/" << denominator;
        }
        cout << endl;
    }

    void printBoth() const {
        cout << "the Formal format of the rational is : ";
        if (numerator < 0) {
            cout << "-" << -numerator << "/" << denominator;
        } else {
            cout << numerator << "/" << denominator;
        }
        cout << endl;
        cout << "the Fixed format of the rational is : ";
        cout << fixed << setprecision(2) << (double)numerator / denominator << endl;
    }
};
//StudybarCommentBegin
int main()
{
    int firstN,firstD,secondN,secondD;
    char op;
    
//    cout<<"Please input the numerator of first Rational: ";
    cin>>firstN;
//    cout<<"Please input the denominator of first Rational: ";
    cin>>firstD;
//    cout<<"Please input the numerator of second Rational: ";
    cin>>secondN;
//    cout<<"Please input the denominator of second Rational: ";
    cin>>secondD;

    
    Rational r1(firstN,firstD),r2(secondN,secondD),r3;

    
    cin>>op;
    
    cout<<"the Formal format of the first rational is : ";
    r1.printFormal();
    cout<<"the Formal format of the second rational is : ";
    r2.printFormal();
    cout<<endl;
    
    switch(op)
    {
        case '+' :
            r3.add(r1,r2);
            r3.printBoth();
            break;
        case '-' :
            r3.minus(r1,r2);
            r3.printBoth();
            break;
        case '*':
            r3.multi(r1,r2);
            r3.printBoth();
            break;
        case '/':
            r3.divide(r1,r2);
            r3.printBoth();
            break;
        default:
            cout<<"Invalid operator!";
    }
    
    return 0;
}
//StudybarCommentEnd