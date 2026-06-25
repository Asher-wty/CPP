#include<iostream>
using namespace std;
class Cmytime{
    int h,m,s;
    public:
        Cmytime(int H=0, int M=0, int S=0) : h(H), m(M), s(S) {}
        void Show(){
            cout<<h<<':'<<m<<':'<<s;
        }
        void Set(int H, int M, int S){
            h=H;
            m=M;
            s=S;
        }
};
//StudybarCommentBegin
int main(void)
{
    int h, m, s;
    cin >> h >> m >> s;
    Cmytime t1(3, 2, 1), t2, t3(5);
    t1.Show();
    cout << "\n";
    t1.Set(h, m, s);
    t1.Show();
    cout << "\n";
    t2.Show();
    cout << "\n";
    t3.Show();
    return 0;
}

//StudybarCommentEnd