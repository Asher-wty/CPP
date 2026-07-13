#include<iostream>
using namespace std;
class Cmycomplex{
    double r,i;
    public:
        Cmycomplex(double a=0, double b=0):r(a), i(b){}
        void Set(double x, double y){
            r=x;
            i=y;
        }
        void Show(){
            cout<<r<<'+'<<i<<'i'<<endl;
        }
        Cmycomplex operator -(const Cmycomplex& other){
            Cmycomplex t;
            t.r=r-other.r;
            t.i=i-other.i;
            return t;
        }
};

//StudybarCommentBegin
int main()
{
    Cmycomplex  z1(2,3), z2, z3(3);
    z2=z1-z3;
    z2.Show();
    double  x, y;
    cin>>x>>y;
    z2.Set(x,y);
    z3=z1-z2;
    cout<<"\n";
    z3.Show();
}
//StudybarCommentEnd