#include <iostream>
using namespace std;

class Fraction {
private:
    int num, den;
    int gcd(int a, int b) const {
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        while (b) { int t = a % b; a = b; b = t; }
        return a;
    }
    void reduce() {
        if (den == 0) return;
        if (den < 0) { num = -num; den = -den; }
        if (num == 0) { den = 1; return; }
        int g = gcd(num, den);
        num /= g;
        den /= g;
    }
public:
    Fraction(int n = 1, int d = 1) : num(n), den(d) { reduce(); }
    Fraction operator-(const Fraction& other) const {
        int n = num * other.den - other.num * den;
        int d = den * other.den;
        return Fraction(n, d);
    }
    bool operator==(const Fraction& other) const {
        return num == other.num && den == other.den;
    }
    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }
    friend ostream& operator<<(ostream& os, const Fraction& f) {
        os << f.num << '/' << f.den;
        return os;
    }
    friend istream& operator>>(istream& is, Fraction& f) {
        is >> f.num >> f.den;
        f.reduce();
        return is;
    }
};

//StudybarCommentBegin
int main(int argc, char *argv[]) {
    Fraction a(1, 2), b;
    Fraction const c(1,-2);
    cout << a << "\n" << b << "\n" << c << '\n';
    cin >> a >> b;
    
    if (c != b) 
        cout << "!=" << endl;
    else
    	cout<<"=="<<endl;
    	
    cout <<c<<" - "<<a<<" = "<< c - a <<endl ;
    return 0;
}     
//StudybarCommentEnd