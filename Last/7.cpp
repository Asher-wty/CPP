//StudybarCommentBegin
#include <iostream>
#include <cstring>
using namespace std;
//StudybarCommentEnd

class MyString {
private:
    char* str;
public:
    MyString(long len) {
        cout << "Constructing..." << endl;
        try {
            str = new char[len];
        } catch (bad_alloc&) {
            cout << "              Constructor abnormal." << endl;
            throw "              Constructor abnormal.";
        }
        cout << "              Construction finished." << endl;
        cin.ignore();
        cin.getline(str, len);
    }
    ~MyString() {
        cout << "              Destruction finished." << endl;
        delete[] str;
    }
    void ShowStr() const {
        cout << "              " << str << endl;
    }
};

//StudybarCommentBegin
int main(){
	long a;
	cin >> a;
	try{
		if (a > 0){
			MyString str1(a);   //生成容纳a个字符的字符串
			str1.ShowStr();
		}
		else 
                 { 
                     char *c="Array length error.";
                     throw c; 
                   //  throw "Array length error.";   work in VC not GCC

                 }
	}
	catch (char* c){
		cout << c << endl;
	}
	catch (...){ 
		cout << "Other failures." << endl; 
	}
	cout << "Main finished." << endl;
	return 0;
}
//StudybarCommentEnd