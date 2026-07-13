#include <iostream>
using namespace std;
class Base
{
public:
    virtual ~Base() {cout<<"delete Base class"<<endl; }// 完善该析构函数并观察加virtual与不加virtual的区别

};
class Derived : public Base
{
public:
    Derived()
    {
        p = new int[100];
    }
    virtual ~Derived()
    {
        delete[] p;
        cout<<"delete new p"<<endl;
        cout<<"delete Derived class"<<endl;
    } // 完善该析构函数并观察加virtual与不加virtual的区别

private:
    int *p;
};
//StudybarCommentBegin
void fun(Base *b)
{
	delete b;
}

int main()
{
	Base *B=new Derived();
	fun(B);
	return 0;
}
//StudybarCommentEnd