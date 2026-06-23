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
        double GetReal(){
            return r;
        }
        double GetImaginary(){
            return i;
        }

};
//StudybarCommentBegin
int main()
{
    Cmycomplex  z1(2,3),z2,z3(3);
    cout<<z1.GetReal()<<"\n";
    cout<<z2.GetImaginary()<<"\n";
    cout<<z3.GetReal()<<"\n";
}
//StudybarCommentEnd