#include <iostream>
using namespace std;

class Cmytime {
private:
    int h, m, s;
public:
    Cmytime() { h = m = s = 0; }
    void Show() {
        cout << h << ":" << m << ":" << s;
    }
    int Set(int hh, int mm, int ss) {
        if (hh >= 0 && hh <= 23 && mm >= 0 && mm <= 60 && ss >= 0 && ss <= 60) {
            h = hh; m = mm; s = ss;
            return 1;
        }
        return 0;
    }
    void AddOneSecond() {
        s++;
        if (s > 59) {
            s = 0;
            m++;
        }
        if (m > 59) {
            m = 0;
            h++;
        }
        if (h > 23) {
            h = 0;
        }
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

   t1.AddOneSecond();
   cout<<endl;
   t1.Show();
  
    return 0;
}

//StudybarCommentEnd