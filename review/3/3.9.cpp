#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class Cmycomplex{
    double r,i;
    public:
        Cmycomplex(double R=0, double I=0){
            r=R;
            i=I;
        }
        void Show(){
            if(i>=0)
            cout<<fixed<<setprecision(2)<<'('<<r<<'+'<<i<<'i'<<')';
            else
            cout<<fixed<<setprecision(2)<<'('<<r<<i<<'i'<<')';
        }
        void Set(double R, double I){
            r=R;
            i=I;
        }
        double GetReal(){
            return r;
        }
        double GetImaginary(){
            return i;
        }
        Cmycomplex Add(const Cmycomplex& c){
            Cmycomplex t;
            t.r=r+c.r;
            t.i=i+c.i;
            return t;
        }
        Cmycomplex operator +(const Cmycomplex c){
            Cmycomplex t;
            t.r=r+c.r;
            t.i=i+c.i;
            return t;
        }
        Cmycomplex operator -(const Cmycomplex c){
            Cmycomplex t;
            t.r=r-c.r;
            t.i=i-c.i;
            return t;
        }
        Cmycomplex operator *(const Cmycomplex c){
            Cmycomplex t;
            t.r=r*c.r-i*c.i;
            t.i=i*c.r+r*c.i;
            return t;
        }
        Cmycomplex operator /(const Cmycomplex c){
            Cmycomplex t;
            double mu=c.r*c.r+c.i*c.i;
            t.r=(r*c.r+i*c.i)/mu;
            t.i=(i*c.r-r*c.i)/mu;
            return t;
        }
        bool operator ==(const Cmycomplex& c){
            if(r==c.r && i==c.i)
            return true;
            return false;
        }
        bool operator !=(const Cmycomplex& c){
            if(r==c.r && i==c.i)
            return false;
            return true;
        }
};
//StudybarCommentBegin
int main()
{
    Cmycomplex  z1(3,4),z2(7),z3;
    double  x,y;
    cin>>x>>y;
    z1.Set(x,y);
    cin>>x>>y;
    z2.Set(x,y);
    if(z1==z2)
    cout<<"y\n";
    else
    cout<<"n\n";
    if(z1!=z2)
    cout<<"y\n";
    else
    cout<<"n\n";
}
//StudybarCommentEnd