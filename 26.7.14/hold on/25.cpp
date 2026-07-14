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
    
    String& operator=( const char *t);
    String& operator=( const String &t );
    String& operator+=( const String &t );
    
    

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

String& String::operator=( const char *t ) {
    delete[] sPtr;
    length = strlen(t);
    sPtr = new char[length + 1];
    strcpy(sPtr, t);
    return *this;
}

String& String::operator=( const String &t ) {
    if (this != &t) {
        *this = t.sPtr; // 调用上面的 operator=(const char*)
    }
    return *this;
}

String& String::operator+=( const String &t ) {
    int newLen = length + t.length;
    char *newPtr = new char[newLen + 1];
    strcpy(newPtr, sPtr);
    strcat(newPtr, t.sPtr);
    delete[] sPtr;
    sPtr = newPtr;
    length = newLen;
    return *this;
}

//StudybarCommentBegin
int main()
{
	char msg[1000];
	cin>>msg;
	String a("This"), b(a), c(msg);	
	cout<<a<<"\na=c is "<<(a=c)<<"\nb+=c is "<<(b+=c)<<endl;
	cout<<(b=msg)<<endl;
}
//StudybarCommentEnd