#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class Complex{
    double r,i;
    public:
        friend istream& operator>>(istream& in, Complex & c);
        Complex operator *(const Complex c){
            Complex t;
            t.r=r*c.r-i*c.i;
            t.i=r*c.i+i*c.r;
            return t;
        }
        Complex operator *(int c){
            Complex t;
            t.r=c*r;
            t.i=c*i;
            return t;
        }
        Complex operator -(const Complex c){
            Complex t;
            t.r=r-c.r;
            t.i=i-c.i;
            return t;
        }
        Complex operator -(){
            Complex t;
            t.r=-r;
            t.i=-i;
            return t;
        }
        Complex operator /(const Complex c){
            Complex t;
            double mu=c.r*c.r+c.i*c.i;
            t.r=(r*c.r+i*c.i)/mu;
            t.i=(-r*c.i+i*c.r)/mu;
            return t;
        }
        Complex operator +(const Complex c){
            Complex t;
            t.r=r+c.r;
            t.i=i+c.i;
            return t;
        }
        friend void Ccout(Complex c);
        friend Complex csqrt(Complex c);
};
istream& operator>>(istream& in, Complex & c){
    in>>c.r>>c.i;
    return in;
}
void Ccout(Complex c){
        if(c.i>=0)
        cout<<fixed<<setprecision(2)<<'('<<c.r<<'+'<<c.i<<'i'<<')'<<endl;
        else
        cout<<fixed<<setprecision(2)<<'('<<c.r<<c.i<<'i'<<')'<<endl;
}
Complex csqrt(Complex c){
        Complex t;
        double r=sqrt(c.r*c.r+c.i*c.i);
        t.r=sqrt((r+c.r)/2);
        if(c.i>0)
        t.i=sqrt((r-c.r)/2);
        else
        t.i=-sqrt((r-c.r)/2);
        return t;
}
int main(){
    Complex a,b,c;
    cin>>a>>b>>c;
    Complex delta = csqrt(b*b-a*c*4);
    Complex rs1,rs2;
    rs1=(-b+delta)/(a*2);
    rs2=(-b-delta)/(a*2);
    Ccout(rs1);
    Ccout(rs2);
    return 0;
}