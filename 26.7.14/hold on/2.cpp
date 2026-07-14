//StudybarCommentBegin
#include <iostream> 
using namespace std;
class Base {
public:
virtual void f() { cout << "Base::f" << endl; }
virtual void g() { cout << "Base::g" << endl; }
virtual void h() { cout << "Base::h" << endl; }
};

//StudybarCommentEnd

class Derive : public Base {
public:
    virtual void f() { cout << "Derive::f" << endl; }
    virtual void h() { cout << "Derive::h" << endl; }
    virtual void g1() { cout << "Derive::g1" << endl; }
};

int main() {
    Derive d;
    typedef void(*Fun)();
    Fun pFun = NULL;
    // vptr 指向虚函数表，在 VC6 32位下通过对象首地址取出
    int* vptr = (int*)*(int*)(&d);
    // 依次调用虚表中的函数
    pFun = (Fun)vptr[0]; pFun(); // Derive::f
    pFun = (Fun)vptr[1]; pFun(); // Base::g
    pFun = (Fun)vptr[2]; pFun(); // Derive::h
    pFun = (Fun)vptr[3]; pFun(); // Derive::g1
    return 0;
}