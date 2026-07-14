//StudybarCommentBegin
#include <iostream>
#include <cstring> // strcpy and strcat prototypes
using namespace std;


class String
{
public:
    String( const char * = "" ); // 输出"Conversion (and default) constructor: "
    String( const String & ); //输出 "Copy constructor: "
    ~String(); // 输出"Destructor: "

    bool operator==( const String & ) const; // test s1 == s2
    operator  char*(){ return this->sPtr; }; //转换函数 
    friend ostream &operator<<( ostream &out, const String &t );

private:
    int length; // string length (not counting null terminator)
    char *sPtr; // pointer to start of pointer-based string
}; 
//StudybarCommentEnd

String::String( const char *s ) {
    length = strlen(s);
    sPtr = new char[length + 1];
    strcpy(sPtr, s);
    cout << "Conversion (and default) constructor: " << sPtr << endl;
}

String::String( const String &s ) {
    length = s.length;
    sPtr = new char[length + 1];
    strcpy(sPtr, s.sPtr);
    cout << "Copy constructor: " << sPtr << endl;
}

String::~String() {
    cout << "Destructor: " << sPtr << endl;
    delete[] sPtr;
}

bool String::operator==( const String &s ) const {
    return strcmp(sPtr, s.sPtr) == 0;
}

ostream &operator<<( ostream &out, const String &t ) {
    out << t.sPtr;
    return out;
}

//StudybarCommentBegin
int main()
{
	char msg[1000];
	cin>>msg;
	String a("This"), b(" is "), c(msg);
	cout<<a<<b<<c<<endl;	
	String A(a),B,C(c);
	cout<<A<<B<<C<<endl;
	cout <<"A==a is "<< (A==a ) <<endl<<"A==c is "<<(A==c)<<endl;
}
//StudybarCommentEnd