#include <iostream>
int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
class date{
    int y,m,d;
    int days(int y, int m) {
        if (((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) && m == 2)
            return 29;
        else
            return months[m-1];
    }
    public:
        date(int year=0, int month=0, int day=0): y(year), m(month), d(day){}
        date operator ++(int){
            date t=*this;
            d++;
            if(d>days(y,m)){
                d-=days(y,m);
                m++;
                if(m>12){
                    m-=12;
                    y++;
                }
            }
            return t;
        }
        int operator -(date t){
            int day=0,s1=0,s2=0;
            for(int i=0; i<y ;i++){
                if((i % 4 == 0 && i % 100 != 0) || i % 400 == 0){
                    s1+=366;
                }
                else{
                    s1+=365;
                }
            }
            for(int i=0; i<t.y ;i++){
                if((i % 4 == 0 && i % 100 != 0) || i % 400 == 0){
                    s2+=366;
                }
                else{
                    s2+=365;
                }
            }
            for(int i=1;i<m;i++){
                s1+=days(y,i);
            }
            for(int i=1;i<t.m;i++){
                s2+=days(t.y,i);
            }
            s1+=d;
            s2+=t.d;
            day=s1-s2;
            return day;
        }
        void operator +=(int day){
            d+=day;
            while(d>days(y,m)){
                d-=days(y,m);
                m++;
                if(m>12){
                    m-=12;
                    y++;
                }
            }
        }
        void operator -=(int day){
            d-=day;
            while(d<0){
                m--;
                if(m<1){
                    m+=12;
                    y--;
                }
                d+=days(y,m);               
            }
        }
        int year() const {return y;}
        int month() const {return m;}
        int day() const {return d;}
};
//StudybarCommentBegin
int main(void) {
    using std::cin;
    using std::cout;
    using std::endl;
    date D1,D2;
    int year;
    int month;
    int day;
    cin>>year>>month>>day; //shu ru di yi ge ri qi
    D1=date(year,month,day);
    cin>>year>>month>>day;  //shu ru di er ge ri qi
    D2=date(year,month,day);
    cout<<D2-D1<<endl; 
    cin>>day;  //shu ru yao jia jian de tian shu, 
    D1+=day;
    D2-=day;
    cout<<D1.year()<<" "<<D1.month()<<" "<<D1.day()<<endl;
    cout<<D2.year()<<" "<<D2.month()<<" "<<D2.day()<<endl;
    return 0;
}

//StudybarCommentEnd