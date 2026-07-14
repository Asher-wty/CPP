#include<iostream>
using namespace std;
class Cmytime{
    private:
        int H,M,S;
    public:
        void Show(){
            cout<<H<<':'<<M<<':'<<S;
        }
        int Set(int h,int m,int s){
            if(h>=0 && h<=23 && m>=0 && m<=59 && s>=0 && s<=59){
            H=h;M=m;S=s;
            return 1;
            }
            return 0;
        }
};
//StudybarCommentBegin
int main(void) {
    int h,m,s;
    cin>>h>>m>>s;
    Cmytime t1;
    t1.Set(1,2,3);
    t1.Set(h,m,s);
    t1.Show();
    return 0;
}

//StudybarCommentEnd