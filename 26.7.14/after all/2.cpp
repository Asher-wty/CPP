#include <iostream>
#include <cstdlib>
using namespace std;

class Fraction {
private:
    int numerator, denominator;
    static int gcd(int a, int b) {
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        while (b) { int t = a % b; a = b; b = t; }
        return a;
    }
    void reduce() {
        if (denominator < 0) { numerator = -numerator; denominator = -denominator; }
        int g = gcd(numerator, denominator);
        numerator /= g; denominator /= g;
    }
public:
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) { reduce(); }
    Fraction operator+(const Fraction& o) const {
        return Fraction(numerator * o.denominator + o.numerator * denominator, denominator * o.denominator);
    }
    Fraction operator-(const Fraction& o) const {
        return Fraction(numerator * o.denominator - o.numerator * denominator, denominator * o.denominator);
    }
    Fraction operator*(const Fraction& o) const {
        return Fraction(numerator * o.numerator, denominator * o.denominator);
    }
    Fraction operator/(const Fraction& o) const {
        return Fraction(numerator * o.denominator, denominator * o.numerator);
    }
    bool operator==(const Fraction& o) const { return numerator == o.numerator && denominator == o.denominator; }
    bool operator!=(const Fraction& o) const { return !(*this == o); }
    bool operator<(const Fraction& o) const {
        return 1LL * numerator * o.denominator < 1LL * o.numerator * denominator;
    }
    bool operator<=(const Fraction& o) const { return (*this < o) || (*this == o); }
    bool operator>(const Fraction& o) const { return !(*this <= o); }
    bool operator>=(const Fraction& o) const { return !(*this < o); }
    friend ostream& operator<<(ostream& os, const Fraction& f);
    friend istream& operator>>(istream& is, Fraction& f);
};

ostream& operator<<(ostream& os, const Fraction& f) {
    if (f.denominator == 1) os << f.numerator;
    else os << f.numerator << '/' << f.denominator;
    return os;
}
istream& operator>>(istream& is, Fraction& f) {
    is >> f.numerator >> f.denominator;
    f.reduce();
    return is;
}

//StudybarCommentBegin
int main(int argc, char *argv[]) {
	
	Fraction a(1),b(1,3),c(-3,9),d(2,-6);
	
	cin>>a>>b;
	
	cout << "a= " << a << ", b = " << b << endl;
	
	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a - b << endl;
	cout << a << " * " << b << " = " << a * b << endl;
	cout << a << " / " << b << " = " << a / b << endl;
	
	cout << "a == b is " << (a == b) << endl;
	cout << "a != b is " << (a != b) << endl;
	cout << "a <= b is " << (a <= b) << endl;
	cout << "a >= b is " << (a >= b) << endl;
	cout << "a < b is " << (a < b) << endl;
	cout << "a > b is " << (a > b) << endl;
        cout << "c == d is " << (c == d) << endl;
	
    return 1;
}
//StudybarCommentEnd