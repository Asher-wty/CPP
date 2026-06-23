#include<iostream>
using namespace std;
class Cmytime{
    private:
        int H,M,S;
    public:
        Cmytime(int h, int m, int s){
            H=h;
            M=m;
            S=s;
        }
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
        void AddOneSecond(){
            int total=H*3600+M*60+S;
            total++;
            H=total/3600;
            M=(total%3600)/60;
            S=(total%60);
        }
        int AddNSeconds(int n){
            int total=H*3600+M*60+S;
            int d=0;
            total+=n;
            H=total/3600;
            d=H/24;
            H%=24;
            M=(total%3600)/60;
            S=(total%60);
        }
};
//StudybarCommentBegin
int main(void) {
    int h,m,s;
   cin>>h>>m>>s;
  
  Cmytime t1(3,2,1);
  t1.Show();
  cout<<"\n";
  t1.Set(h,m,s);
  t1.Show();
  
  return 0;
}

//StudybarCommentEnd
