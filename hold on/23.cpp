#include <iostream>
using namespace std;

class Cmycomplex {
private:
    int real, imag;
public:
    Cmycomplex(int r = 0, int i = 0) : real(r), imag(i) {}
    void Set(double r, double i) { real = (int)r; imag = (int)i; }
    Cmycomplex operator+(const Cmycomplex &z) {
        return Cmycomplex(real + z.real, imag + z.imag);
    }
    Cmycomplex operator-(const Cmycomplex &z) {
        return Cmycomplex(real - z.real, imag - z.imag);
    }
    Cmycomplex operator*(const Cmycomplex &z) {
        return Cmycomplex(real * z.real - imag * z.imag,
                          real * z.imag + imag * z.real);
    }
    void Show() {
        cout << "(" << real << "+" << imag << "i)";
    }
};

//StudybarCommentBegin
int main()
{
Cmycomplex  z1(3,4),z2(7),z3;
double  x,y;
cin>>x>>y;
z2.Set(x,y);
z3=z1+z2;
cout<<"\n";
z3.Show();
z3=z1-z2;
cout<<"\n";
z3.Show();
z3=z1*z2;
cout<<"\n";
z3.Show();

}
//StudybarCommentEnd