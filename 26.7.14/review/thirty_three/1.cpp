#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    map<pair<int, int>, int> pairCount;
    //输入模块
    string line;
    while(line !="00000"){
        getline(cin,line);
        istringstream sline(line);
        set<int> oneline;
        int i;
        while(sline>>i){
            oneline.insert(i);
        }
        if(oneline.size()<2) continue;
        for(auto it1=oneline.begin(); it1!=oneline.end();it1++){
            for(auto it2=next(it1); it2!=oneline.end();it2++){
                pairCount[pair<int, int>(*it1,*it2)]++;
            }
        }
    }
    //处理模块
    int max = 0;
    for(const auto& times : pairCount){
        if(times.second>max){
            max=times.second;
        }
    }
    //输出模块
    vector<pair<int, int>> output;
    for(const auto& times : pairCount){
        if(times.second==max){
            output.push_back(times.first);
        }
    }
    for(const auto& p : output){
        cout<<p.first<<' '<<p.second<<endl;
    }
    return 0;
}   