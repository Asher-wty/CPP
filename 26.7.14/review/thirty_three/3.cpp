#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
int main(){
    multiset<int> a;
    set<int> appear;
    int n=0;
    cin>>n;
    string cmd;
    int x;
    while(n--){
        cin>>cmd>>x;
        if(cmd=="add"){
            a.insert(x);
            appear.insert(x);
            cout<<a.count(x)<<endl;
        }
        else if(cmd=="del"){
            cout<<a.count(x)<<endl;
            a.erase(x);
        }
        else{
            if(appear.count(x)) cout<<1<<' ';
            else cout<<0<<' ';
            cout<<a.count(x)<<endl;
        }
    }
    return 0;
}