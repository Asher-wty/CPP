#include<iostream>
using namespace std;
class Cmycomplex{
    int r,i;
    public:
        Cmycomplex(int R=0, int I=0){
            r=R;
            i=I;
        }
        void Show(){
            if(i>=0)
            cout<<'('<<r<<'+'<<i<<'i'<<')'<<endl;
            else
            cout<<'('<<r<<i<<'i'<<')'<<endl;
        }

};
//StudybarCommentBegin
int main()
{
    Cmycomplex  z1(2,3),z2,z3(3);
    z1.Show();
}
//StudybarCommentEnd