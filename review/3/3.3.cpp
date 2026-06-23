
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
        Cmycomplex Add(const Cmycomplex& c){
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
    z1.Add(z3);
    z1.Show();
}
//StudybarCommentEnd