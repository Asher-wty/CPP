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
            cout<<fixed<<setprecision(0)<<'('<<r<<'+'<<i<<'i'<<')';
            else
            cout<<fixed<<setprecision(0)<<'('<<r<<i<<'i'<<')';
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
        Cmycomplex sqrt(){
            Cmycomplex t;
            double l=std::sqrt(r*r+i*i);
            t.r=std::sqrt((r+l)/2);
            if(i>0)
            t.i=std::sqrt((l-r)/2);
            else
            t.i=std::sqrt((l-r)/2)*-1;
            return t;
        }
        friend Cmycomplex operator +(int a, Cmycomplex c);
};
Cmycomplex operator +(int a, Cmycomplex c){
    Cmycomplex t;
    t.r=2+c.r;
    t.i=c.i;
    return t;
}
//StudybarCommentBegin
int main()
{
    Cmycomplex z1(3,4),z2(7),z3,z4(z1);
    double x,y;
    cin>>x>>y;
    z3.Set(x,y);
    cout<<endl;
    z3=z3+z2;
    z3.Show();
    z4=2+z4;
    cout<<endl;
    z4.Show();
    z4=z4+2;
    cout<<endl;
    z4.Show();
} 
//StudybarCommentEnd