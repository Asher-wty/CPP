#include<iostream>
using namespace std;
class Cmytime{
    private:
        int H,M,S;
    public:
        void Show(){
            cout<<H<<':'<<M<<':'<<S;
        }
        void Set(int h,int m,int s){
            H=h;M=m;S=s;
        }
};
//StudybarCommentBegin
int main(void) {
    int h,m,s;
    cin>>h>>m>>s;
    Cmytime t1;
    t1.Set(h,m,s);
    t1.Show();
    return 0;
    }

//StudybarCommentEnd