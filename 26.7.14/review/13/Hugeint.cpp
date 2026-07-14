//StudybarCommentBegin
#include <iostream>
#include <cctype>  // isdigit function prototype
#include <cstring> // strlen function prototype
using namespace std;

class HugeInt
{
    friend ostream &operator<<(ostream &, const HugeInt &);

public:
    static const int digits = 30;
    HugeInt(long = 0);     // conversion/default constructor
    HugeInt(const char *); // conversion constructor

    // addition operator; HugeInt + HugeInt
    HugeInt operator+(const HugeInt &) const;

    // addition operator; HugeInt + int
    HugeInt operator+(int) const;

    // addition operator;
    // HugeInt + string that represents large integer value
    HugeInt operator+(const char *) const;

    int getLength() const;

private:
    short integer[digits];
}; // end class HugeInt

//StudybarCommentEnd
HugeInt::HugeInt(long t){
    for(int i=0;i<digits;i++){
        if(t/=10>0){
            integer[i]=t%10;
        }
        else
            integer[i]=0;
    }
}
HugeInt::HugeInt(const char* num){
    int len=strlen(num);
    int pos=len-1;
    for(int i=0;i<digits;i++){
        if(pos>=0){
            integer[i]=(num[pos]-'0');
            pos--;
        }
        else
            integer[i]=0;
    }
}
int HugeInt::getLength() const{
    int i=0;
    for(i=0;integer[i]==0 && integer[i+1]!=0;i++){
    }
    return digits-i-1;
}
HugeInt HugeInt::operator+(const HugeInt & t) const{
    HugeInt temp;
    for(int i=0;i<digits;i++){
        
    }
}
HugeInt HugeInt::operator+(int t) const{

}
//StudybarCommentBegin
int main()
{
    HugeInt n1(7654321);
    HugeInt n2(7891234);
    HugeInt n3("99999999999999999999999999999");
    HugeInt n4("1");
    HugeInt result;

    cout << "n1 is " << n1 << "\nn2 is " << n2
         << "\nn3 is " << n3 << "\nn4 is " << n4
         << "\nresult is " << result << "\n\n";

    result = n1 + n2;
    cout << n1 << " + " << n2 << " = " << result << "\n\n";

    cout << n3 << " + " << n4 << "\n= " << (n3 + n4) << "\n\n";

    result = n1 + 9;
    cout << n1 << " + " << 9 << " = " << result << endl;

    result = n2 + "10000";
    cout << n2 << " + " << "10000" << " = " << result << endl;
    return 0;
} // end main

//StudybarCommentEnd