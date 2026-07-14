#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Fraction {
private:
    int num, den;
    static int gcd(int a, int b) {
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        while (b) { int t = a % b; a = b; b = t; }
        return a;
    }
    void reduce() {
        if (den == 0) { den = 1; return; }
        if (den < 0) { num = -num; den = -den; }
        int g = gcd(num, den);
        num /= g;
        den /= g;
    }
public:
    Fraction(int n = 0, int d = 1) : num(n), den(d) { reduce(); }
    bool operator<(const Fraction& other) const {
        return 1LL * num * other.den < 1LL * other.num * den;
    }
    bool operator==(const Fraction& other) const {
        return num == other.num && den == other.den;
    }
    bool operator>(const Fraction& other) const {
        return other < *this;
    }
    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }
    friend istream& operator>>(istream& is, Fraction& f) {
        is >> f.num >> f.den;
        f.reduce();
        return is;
    }
    friend ostream& operator<<(ostream& os, const Fraction& f) {
        if (f.den == 1)
            os << f.num;
        else
            os << f.num << '/' << f.den;
        return os;
    }
};
template <typename T>
class Cassemblage {
private:
    vector<T> elements;
public:
    void Set(T arr[], int n) {
        elements.clear();
        for (int i = 0; i < n; ++i) {
            bool exist = false;
            for (const auto& e : elements) {
                if (e == arr[i]) {
                    exist = true;
                    break;
                }
            }
            if (!exist)
                elements.push_back(arr[i]);
        }
        sort(elements.begin(), elements.end());
    }
    Cassemblage<T> operator+(const Cassemblage<T>& other) const {
        Cassemblage<T> result;
        for (const auto& e : elements) result.elements.push_back(e);
        for (const auto& e : other.elements) result.elements.push_back(e);
        sort(result.elements.begin(), result.elements.end());
        result.elements.erase(unique(result.elements.begin(), result.elements.end()), result.elements.end());
        return result;
    }
    Cassemblage<T> operator&(const Cassemblage<T>& other) const {
        Cassemblage<T> result;
        for (const auto& e : elements) {
            for (const auto& oe : other.elements) {
                if (e == oe) {
                    result.elements.push_back(e);
                    break;
                }
            }
        }
        return result;
    }
    Cassemblage<T> operator-(const Cassemblage<T>& other) const {
        Cassemblage<T> result;
        for (const auto& e : elements) {
            bool found = false;
            for (const auto& oe : other.elements) {
                if (e == oe) {
                    found = true;
                    break;
                }
            }
            if (!found)
                result.elements.push_back(e);
        }
        return result;
    }
    void Show() const {
        if (elements.empty()) {
            cout << "empty";
        } else {
            for (size_t i = 0; i < elements.size(); ++i) {
                if (i) cout << ' ';
                cout << elements[i];
            }
        }
        cout << endl;
    }
};
int main() {
    Cassemblage<Fraction> z1, z2, x1;
    Fraction a1[1000], a2[1000];
    int i, n1, n2;
    char op;

    cin >> n1;
    for (i = 0; i < n1; i++) {
        cin >> a1[i];
    }
    z1.Set(a1, n1);

    cin >> n2;
    for (i = 0; i < n2; i++) {
        cin >> a2[i];
    }
    z2.Set(a2, n2);

    cin >> op;

    switch (op) {
        case '+':
            x1 = z1 + z2;
            x1.Show();
            break;
        case '-':
            x1 = z1 - z2;
            x1.Show();
            break;
        case '&':
            x1 = z1 & z2;
            x1.Show();
            break;
        default:
            cout << "Invalid operator!" << endl;
    }
    return 0;
}