#include <iostream>
using namespace std;
int gcd(int a, int b){
    int t=a%b;
    if(t==0)
    return b;
    return gcd(b,t);
}
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int z=a*d+b*c;
    int m=b*d;
    int g=gcd(z,m);
    z/=g;
    m/=g;
    if(m<0){
        z=-z;
        m*=-1;
    }
    cout<<z<<"/"<<m;
    return 0;
}