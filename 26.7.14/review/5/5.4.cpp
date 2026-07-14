#include <iostream>
class date{
    int y,m,d;
    int days(int y, int m) {
        int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
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
                if(m>=12){
                    m-=12;
                    y++;
                }
            }
            return t;
        }
        int year() const {return y;}
        int month() const {return m;}
        int day() const {return d;}
};
//StudybarCommentBegin
int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;

	date D1,D2;

	int year;
	int month;
	int day;

	cin>>year>>month>>day; //shu ru di yi ge ri qi
	D1=date(year,month,day);

	D2=D1++;

	cout<<D1.year()<<" "<<D1.month()<<" "<<D1.day()<<endl;
	cout<<D2.year()<<" "<<D2.month()<<" "<<D2.day()<<endl;
	return 0;
}

//StudybarCommentEnd