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
        Cmycomplex sqrt(){
            Cmycomplex t;
            double R=std::sqrt(r*r+i*i);
            t.r=std::sqrt((r+R)/2);
            if(i>0)
            t.i=std::sqrt((R-r)/2);
            else
            t.i=-std::sqrt((R-r)/2);
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
};
Cmycomplex operator *(int a,const Cmycomplex& z){
    Cmycomplex t;
    t.r=a*z.r;
    t.i=a*z.i;
    return t;
}
//StudybarCommentBegin
int main()
{
    double x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    Cmycomplex a(x1, y1), b(x2, y2), c(x3, y3), z, t1, t2;
    z = b * b - 4 * a * c;
    t1 = ((-1) * b + z.sqrt()) / (2 * a); // z.sqrt()为求复数z的平方根，这里的2*a涉及操作符重载，且友元重载。
    t2 = ((-1) * b - z.sqrt()) / 2.0 / a; // 这里涉及到除法的重载
    if (t1.gety() > t2.gety()) // gety()为得到虚部值
    {
        t1.Show();
        t2.Show();
    }
    else
    {
        t2.Show();
        t1.Show();
    }
    return 0;
}
//StudybarCommentEnd