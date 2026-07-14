#include <iostream>
using namespace std;
int maxinum(int a, int b, int c){
    if(a>b){
        if(a>c) return a;
        else return c;
    }
    else{
        if(b>c) return b;
        else return c;
    }  
}
float maxinum(float a, float b, float c){
    if(a>b){
        if(a>c) return a;
        else return c;
    }
    else{
        if(b>c) return b;
        else return c;
    }  
}
char maxinum(char a, char b, char c){
    if(a>b){
        if(a>c) return a;
        else return c;
    }
    else{
        if(b>c) return b;
        else return c;
    }  
}
//StudybarCommentBegin
int main()
{
    int b1, b2, b3;
	float c1, c2, c3;
	char a1, a2, a3;
	cin >> b1 >> b2 >> b3 >> c1 >> c2 >> c3>> a1 >> a2 >> a3;
	cout << maxinum(b1, b2, b3) << ' ' << maxinum(c1, c2, c3) << ' ' << maxinum(a1, a2, a3);
	return 0;
}
//StudybarCommentEnd