//StudybarCommentBegin
#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::setfill;
using std::setw;

//StudybarCommentEnd
int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int days(int y, int m) {
        if (((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) && m == 2)
            return 29;
        else
            return months[m-1];
}
class Time{
    int y,m,d,h,min,s;
    public:
        Time(int year=0, int month=0, int day=0, int hour=0, int minute=0, int second=0):y(year), m(month), d(day), h(hour), min(minute), s(second) {}
        void setTime(int year, int month, int day, int hour, int minute, int second){
            y=year;
            m=month;
            d=day;
            h=hour;
            min=minute;
            s=second;
        }
        void printTime()
            {
            cout<<y<<"/"<<m<<"/"<<d<<" "<<setfill('0')<<setw(2)<<h<<":"<<setw(2)<<min<<":"<<setw(2)<<s<<endl;
        }
        Time& operator ++(){
            s++;
            if(s>=60){
                min++;
                s-=60;
            }
            if(min>=60){
                h++;
                min-=60;
            }
            if(h>=24){
                h-=24;
                d++;
            }
            if(d>days(y,m)){
                d-=days(y,m);
                m++;
            }
            if(m>12){
                m-=12;
                y++;
            }
            return *this;
        }   
        Time operator +(int increase){
            Time t=*this;
            t.s+=increase;
            while(t.s>=60){
                t.min++;
                t.s-=60;
            }
            while(t.min>=60){
                t.h++;
                t.min-=60;
            }
            while(t.h>=24){
                t.h-=24;
                t.d++;
            }
            while(t.d>days(t.y,t.m)){
                t.d-=days(t.y,t.m);
                t.m++;
            }
            while(t.m>12){
                t.m-=12;
                t.y++;
            }
            return t;
        }
        long long hours(const Time &t) const
        { 
            long long total = 0;
            for (int i = 0; i < t.y; ++i)
                total += ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) ? 366 : 365;
            for (int i = 1; i < t.m; ++i)
                total += days(t.y, i);
            total += t.d - 1;
            return total * 24;
        }
        int operator -(const Time & t){
            int h1=h+hours(*this);
            int h2=t.h+hours(t);
            int sum1=h1*3600+min*60+s;
            int sum2=h2*3600+t.min*60+t.s;
            return sum1-sum2;
        }
};
//StudybarCommentBegin
int main()
{
	
	int year,month,day;
	int hour,minute,second;
	int increase;
	int capacity=0;
	Time t1(2016,3,31,23,45,0),t2,t3(t1),t4;
	cin>>year>>month>>day>>hour>>minute>>second;
	t1.setTime(year,month,day,hour,minute,second);
	cin>>year>>month>>day>>hour>>minute>>second;
	t2.setTime(year,month,day,hour,minute,second);
	cin>>increase;
	t1.printTime();
	t2.printTime();
	t3=++t1;
	t3.printTime();
	t4=t1+increase;
	t4.printTime();
	capacity = t2-t1;
	cout<<capacity<<endl;
}
//StudybarCommentEnd