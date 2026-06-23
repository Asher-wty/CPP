//StudybarCommentBegin
#include <iostream>
#include <iomanip>
#include <string>
//StudybarCommentEnd
#include <cmath>
using namespace std;
class ComplexNumber{
    double r,i;
    public:
        ComplexNumber(double R=0, double I=0){
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
        ComplexNumber Add(const ComplexNumber& c){
            ComplexNumber t;
            t.r=r+c.r;
            t.i=i+c.i;
            return t;
        }
        ComplexNumber operator +(const ComplexNumber c){
            ComplexNumber t;
            t.r=r+c.r;
            t.i=i+c.i;
            return t;
        }
        ComplexNumber operator -(const ComplexNumber c){
            ComplexNumber t;
            t.r=r-c.r;
            t.i=i-c.i;
            return t;
        }
        ComplexNumber operator *(const ComplexNumber c){
            ComplexNumber t;
            t.r=r*c.r-i*c.i;
            t.i=i*c.r+r*c.i;
            return t;
        }
        ComplexNumber operator /(const ComplexNumber c){
            ComplexNumber t;
            double mu=c.r*c.r+c.i*c.i;
            t.r=(r*c.r+i*c.i)/mu;
            t.i=(i*c.r-r*c.i)/mu;
            return t;
        }
        bool operator ==(const ComplexNumber& c){
            if(r==c.r && i==c.i)
            return true;
            return false;
        }
        bool operator !=(const ComplexNumber& c){
            if(r==c.r && i==c.i)
            return false;
            return true;
        }
        ComplexNumber sqrt(){
            ComplexNumber t;
            double l=std::sqrt(r*r+i*i);
            t.r=std::sqrt((r+l)/2);
            if(i>0)
            t.i=std::sqrt((l-r)/2);
            else
            t.i=std::sqrt((l-r)/2)*-1;
            return t;
        }
        friend ComplexNumber operator +(int a, ComplexNumber c);
        friend istream& operator >>(istream & in, ComplexNumber &c);
        friend ostream& operator <<(ostream & out, ComplexNumber c);
};
ComplexNumber operator +(int a, ComplexNumber c){
    ComplexNumber t;
    t.r=a+c.r;
    t.i=c.i;
    return t;
}
istream& operator >>(istream & in, ComplexNumber &c){
    in>>c.r>>c.i;
    return in;
}
ostream& operator <<(ostream & out, ComplexNumber c){
    if(c.i>=0)
        out<<fixed<<setprecision(2)<<c.r<<'+'<<c.i<<'i';
    else
        out<<fixed<<setprecision(2)<<c.r<<c.i<<'i';
    return out;
}
//StudybarCommentBegin
void CN() { //ComplexNumber
	ComplexNumber cn1, cn2;
	std::cin >> cn1 >> cn2;
	std::cout<<cn1+cn2 << std::endl;
	std::cout<<cn1 - cn2 << std::endl;
	std::cout<<cn1*cn2 << std::endl;
	std::cout<<cn1 / cn2 << std::endl;
}
int main(void) {
	CN();
	return 0;
}
//StudybarCommentEnd