#include<iostream>
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
            cout<<'('<<r<<'+'<<i<<'i'<<')'<<endl;
            else
            cout<<'('<<r<<i<<'i'<<')'<<endl;
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
};
//StudybarCommentBegin
int main()
{
    Cmycomplex  z1(2,3),z2,z3(3);
    z2=z1+z3;
    z2.Show();
    double  x,y;
    cin>>x>>y;
    z2.Set(x,y);
    z3=z1+z2;
    cout<<"\n";
    z3.Show();
}
//StudybarCommentEnd