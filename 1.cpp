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
    private:
        int h,m,s;
    public:
        Time(int a=0, int b=0, int c=0):h(a), m(b), s(c){}
        void setTime(int a, int b, int c){
            h=a; m=b; s=c;
        }
        void printTime(){
             cout<<setfill('0')<<setw(2)<<h<<":"<<setw(2)<<m<<":"<<setw(2)<<s<<endl;
        }
        Time& operator ++(){ //前置++
            s++;
            if(s==60){
                s=0;
                m++;
            }
            if(m==60){
                m=0;
                h++;
            }
            if(h==24){
                h=0;
            }
            return *this;
        }
        Time operator ++(int){ //后置++
            Time t=*this;
            s++;
            if(s==60){
                s=0;
                m++;
            }
            if(m==60){
                m=0;
                h++;
            }
            if(h==24){
                h=0;
            }
            return t;
        }
        Time& operator --(){  //前置--
            s--;
            if(s==-1){
                s=59;
                m--;
            }
            if(m==-1){
                m=59;
                h--;
            }
            return *this;
        }
        Time operator --(int){  //后置--
            Time t=*this;
            s--;
            if(s==-1){
                s=59;
                m--;
            }
            if(m==-1){
                m=59;
                h--;
            }
            return t;
        }
        friend Time operator +(int increase, Time a){
            int total = a.h * 3600 + a.m * 60 + a.s;
            total += increase;
            total %= 86400;
            if (total < 0) total += 86400;
            return Time(total / 3600, (total % 3600) / 60, total % 60);
        }
};

//StudybarCommentBegin
int main()
 {
 int hour,minute,second;
 int number;
 Time t1(23,45,0),t2,t3(t1),t4;
cin>>hour>>minute>>second>>number;
 t1.setTime(hour,minute,second);
 t2=t1--;
 t2.printTime();
 t1.printTime();
 t3=--t1;
 t3.printTime();
 t4=number+t1;
 t4.printTime();
}
//StudybarCommentEnd
//github