#include <iostream>
#include <cmath>
using namespace std;
class Cmycomplex{
    double r,i;
    public:
        Cmycomplex(double R=0, double I=0): r(R), i(I) {}
        Cmycomplex operator +(const Cmycomplex& z){
            Cmycomplex t;
            t.r=r+z.r;
            t.i=i+z.i;
            return t;
        }
        Cmycomplex operator -(const Cmycomplex& z){
            Cmycomplex t;
            t.r=r-z.r;
            t.i=i-z.i;
            return t;
        }
        Cmycomplex operator *(const Cmycomplex& z){
            Cmycomplex t;
            t.r=r*z.r-i*z.i;
            t.i=i*z.r+r*z.i;
            return t;
        }
        Cmycomplex operator /(const Cmycomplex& z){
            Cmycomplex t;
            double mu=z.r*z.r+z.i*z.i;
            t.r=(r*z.r+i*z.i)/mu;
            t.i=(i*z.r-r*z.i)/mu;
            return t;
        }
        void Show(){
            if(i>=0){
                cout<<'('<<r<<'+'<<i<<"i)"<<endl;
            }
            else
                cout<<'('<<r<<i<<"i)"<<endl;
        }
        double gety() const {return i;}
        friend Cmycomplex operator *(int a,const Cmycomplex& z);
        friend Cmycomplex sqrt(Cmycomplex z);
        friend ostream& operator <<(ostream& out, Cmycomplex& z);
        friend istream& operator >>(istream& in, Cmycomplex& z);
};
Cmycomplex operator *(int a,const Cmycomplex& z){
    Cmycomplex t;
    t.r=a*z.r;
    t.i=a*z.i;
    return t;
}
Cmycomplex sqrt(Cmycomplex z){
    Cmycomplex t;
    double R=std::sqrt(z.r*z.r+z.i*z.i);
    t.r=std::sqrt((z.r+R)/2);
    if(z.i>0)
    t.i=std::sqrt((R-z.r)/2);
    else
    t.i=-std::sqrt((R-z.r)/2);
    return t;
}
istream& operator >>(istream& in, Cmycomplex& z){
    in>>z.r>>z.i;
    return in;
}
ostream& operator <<(ostream& out, Cmycomplex& z){
    if(z.i>=0){
        out<<'('<<z.r<<'+'<<z.i<<"i)"<<endl;
    }
    else
        out<<'('<<z.r<<z.i<<"i)"<<endl;
    return out;
}
//StudybarCommentBegin
// StudybarCommentBegin
int main()
{

    Cmycomplex a, b, c, z, t1, t2;
    cin >> a >> b >> c;
    z = b * b - 4 * a * c;
    t1 = ((-1) * b + sqrt(z)) / (2 * a); // sqrt(z)为求复数z的平方根，这里的2*a涉及操作符重载，且友元重载。
    t2 = ((-1) * b - sqrt(z)) / 2.0 / a; // 这里涉及到除法的重载
    if (t1.gety() > t2.gety()) // gety()为得到虚部值
    {
        cout << t1 << t2;
    }
    else
    {
        cout << t2 << t1;
    }
    return 0;
}
// StudybarCommentEnd
//StudybarCommentEnd