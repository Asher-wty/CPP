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
        double getImaginary() const {return i;}
        double getReal() const {return r;}
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
double trim(double v) {
        return (fabs(v) < 1e-9) ? 0.0 : v;
}
int main(){
    Cmycomplex x1,y1,x2,y2,x3,y3,resa,resb,resc;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    Cmycomplex A1,A2,B1,B2,C1,C2,det;
    A1=x1*x1-x2*x2;
    A2=x1*x1-x3*x3;
    B1=x1-x2;
    B2=x1-x3;
    C1=y1-y2;
    C2=y1-y3;
    //克莱姆法则
    det=A1*B2-A2*B1;
    resa=(C1*B2-C2*B1)/det;
    resb=(A1*C2-A2*C1)/det;
    resc=y1-resa*x1*x1-resb*x1;
    printf("%lf %lf\n", trim(resa.getReal()), trim(resa.getImaginary()));
    printf("%lf %lf\n", trim(resb.getReal()), trim(resb.getImaginary()));
    printf("%lf %lf\n", trim(resc.getReal()), trim(resc.getImaginary()));
}