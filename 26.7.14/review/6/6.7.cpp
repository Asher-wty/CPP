#include <iostream>
#include <algorithm>
using namespace std;

class Cassemblage{
    int n;
    int a[1000];
    public:
        Cassemblage():n(0){}
        void Set(int* A, int N){
            n=N;
            for(int i=0;i<n;i++){
                a[i]=A[i];
            }
        }
        void Show(){
            sort(a,a+n);
            int newn=unique(a,a+n)-a;
            n=newn;
            if(n==0) cout<<"empty";
            else
            for(int i=0;i<n;i++){
                cout<<a[i];
                if(i!=n-1) cout<<' ';
            }
        }
        Cassemblage operator +(const Cassemblage& other){
            Cassemblage t;
            t.n=n+other.n;
            for(int i=0;i<n;i++){
                t.a[i]=a[i];
            }
            for(int i=0;i<other.n;i++){
                t.a[n+i]=other.a[i];
            }
            return t;
        }
        Cassemblage operator &(const Cassemblage& other){
            Cassemblage t;
            t.n=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<other.n;j++){
                    if(a[i]==other.a[j]){
                        t.a[t.n]=a[i];
                        t.n++;
                    }
                }
            }
            return t;
        }
        Cassemblage operator -(const Cassemblage& other){
            Cassemblage t;
            t.n=0;
            for(int i=0;i<n;i++){
                bool equal=false;
                for(int j=0;j<other.n;j++){
                    if(a[i]==other.a[j]){
                        equal=true;
                        break;
                    }
                }
                if(!equal){
                    t.a[t.n]=a[i];
                    t.n++;
                }
            }
            return t;
        }
};
//StudybarCommentBegin
int main(int argc, char *argv[])
{
    Cassemblage z1, z2, x1, x2, x3;
    int i, n1, n2, a1[1000], a2[1000];
    cin >> n1;
    for (i = 0; i < n1; i++)
    {
        cin >> a1[i];
    }
    z1.Set(a1, n1);
    cin >> n2;
    for (i = 0; i < n2; i++)
    {
        cin >> a2[i];
    }
    z2.Set(a2, n2);
    x1 = z1 + z2;
    x1.Show();
    cout << endl;
    x2 = z1 & z2;
    x2.Show();
    cout << endl;
    x3 = z1 - z2;
    x3.Show();
    return 0;
}

//StudybarCommentEnd