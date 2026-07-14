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
    DynamicArray<Point> iarray2(iarray),iarray3(iarray2);
    cout<<endl;
    for(i=0;i<length;i++) {
        cout << iarray3[i] <<" ";
        iarray[i] = Point(i,i+1);	
    }
    iarray3=iarray2=iarray;
    cout<<endl;
    for(i=0;i<length;i++) {
        cout << iarray3[i] <<" ";	
    }

    return 0;
}
//StudybarCommentEnd