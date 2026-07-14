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

   Cmytime t1;
   t1.Set(h,m,s);
   t1.Show();
   cout<<endl<<t1.Set(24,0,0)<<"\n";
   t1.Show();

   t1.AddNSeconds(1);
   cout<<endl;
   t1.Show();
   cout<<endl<<t1.AddNSeconds(3600*25);
  
    return 0;
}

//StudybarCommentEnd
