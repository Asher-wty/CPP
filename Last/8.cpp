//StudybarCommentBegin
#include <iostream>
using namespace std;
//StudybarCommentEnd

class MyException {
private:
    int excpNo;
public:
    MyException(int n) : excpNo(n) {}
    void Reason() {
        cout << "Exception:" << excpNo << endl;
    }
};

void fn1(int excpNo) {
    throw new MyException(excpNo);
}

//StudybarCommentBegin
int main(){        
        int excpNo;
	cin >> excpNo;
	try{
		if (excpNo > 3 || excpNo < 1)
			throw 1;
		fn1(excpNo);
	}
	catch (MyException* e){
		e->Reason();
	}
	catch (...){
		cout << "Other error." << endl;
	}
        return 0;
}
//StudybarCommentEnd