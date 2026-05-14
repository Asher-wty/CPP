#include <iostream>
using namespace std;

template <typename T>
class DynamicArray{
    private:
        T* p;
        int len;
    public:
        DynamicArray(int length, T init){
            len=length;
            cout<<endl<<"new T["<<this->len<<"] malloc "<< this->len << "*"<<sizeof(T)<<"="<<this->len *sizeof(T)<<" bytes memory in heap";
            p=new T[len];
            for(int i=0;i<len;i++){
                p[i]=init;
            }
        }
        DynamicArray(const DynamicArray& copy){
            len=copy.len;
            cout<<endl<< "Copy Constructor is called";
            p=new T[len];
            for(int i=0;i<len;i++){
                p[i]=copy.p[i];
            }   
        }
        ~DynamicArray(){
            cout<<endl<< "delete[] array free "<< this->len << "*"<<sizeof(T)<<"="<<this->len    *sizeof(T)<<" bytes memory in heap";
            delete[] p;
        }
        int capacity () const{
            return len;
        }
        T& operator [](int i){
            return p[i];
        }
        const T& operator [](int i) const{
            return p[i];
        }
        DynamicArray<T> & operator =(const DynamicArray<T>& copy){  //返回引用以支持链式赋值    //"="的意思时让左边等于右边的“副本”
            cout<<endl<<"operator = is called";
            delete[] p;
            len=copy.len;
            p=new T[len];
            for(int i=0; i<len; i++){
                p[i]=copy.p[i];
            }
            return *this;
        }
        int resize(int newlen, const T& newinit){
            cout<<"\nresize is called";
            if(newlen==len) return 0;
            else if (newlen < len){
                T* newp = new T[newlen];
                for(int i=0; i<newlen; i++){   //..没有改newlen ，导致运行时错误，卡了20min。。。。
                    newp[i]=p[i];
                }
                len = newlen;
                delete[] p;
                p=newp;
                return -1;
            }
            else{
                T* newp= new T[newlen];
                for(int i=0;i<len;i++){
                    newp[i]=p[i];
                }
                for(int i=len;i<newlen;i++){
                    newp[i]=newinit;
                }
                len=newlen;
                delete[] p;
                p=newp;
                return 1;
            }
        }
};
class Point{
    private:
        int x,y;
    public:
        Point(int a=0, int b=0): x(a), y(b) {cout<<"\nPoint is called!";}
        ~Point(){cout<<"\n~Point is called!";}
        friend ostream& operator <<(ostream& x, const Point& p){   //x可以任意替换 out os cout等
            x<<"("<<p.x<<","<<p.y<<")";
            return x;
        }
};

//StudybarCommentBegin
int main()
{
int length,i;
cin>> length;

DynamicArray<Point> iarray(length,Point(3));

cin>>length;

cout<<endl<<iarray.resize(length,Point(1,2));

cout<<endl;
for(i=0;i<length;i++) {
	cout << iarray[i] <<" ";	
}

return 0;
}
//StudybarCommentEnd