//StudybarCommentBegin
#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::setfill;
using std::setw;
//StudybarCommentEnd
class Time{
    int h,m,s;
    public:
        Time(int H=0, int M=0, int S=0) : h(H), m(M), s(S) {}
        void setTime(int H, int M, int S){
            h=H;
            m=M;
            s=S;
        }
        void printTime(){
            int sum=h*3600+m*60+s;
            h=(sum/3600)%24;
            sum%=3600;
            m=sum/60;
            s=sum%60;
            cout<<setfill('0')<<setw(2)<<h<<":"<<setw(2)<<m<<":"<<setw(2)<<s<<endl;
        }
        Time& operator ++(){
            s++;
            if(s>=60){
                s-=60;
                m++;
                if(m>=60){
                    m-=60;
                    h++;
                }
            }
            return *this;
        }
        friend Time operator +(int a, const Time& t);
};
Time operator +(int a, const Time& t){
    Time temp;
    temp.s=t.s;
    temp.m=t.m;
    temp.h=t.h;
    temp.s+=a;
    return temp;
}
//StudybarCommentBegin
int main()
{
    int hour, minute, second;
    int increase;
    Time t1(23, 45, 0), t2, t3(t1);
    cin >> hour >> minute >> second >> increase;
    t1.setTime(hour, minute, second);
    t1.printTime();
    t2 = ++t1;
    t2.printTime();
    t3 = increase + t1;
    t3.printTime();
    return 0;
}
//StudybarCommentEnd