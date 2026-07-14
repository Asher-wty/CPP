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
            p=new T[len];
            for(int i=0;i<len;i++){
                p[i]=init;
            }
            cout<<endl<<"new T["<<this->len<<"] malloc "<< this->len << "*"<<sizeof(T)<<"="<<this->len *sizeof(T)<<" bytes memory in heap";
        }
        ~DynamicArray(){
            delete[] p;
            cout<<endl<< "delete[] array free "<< this->len << "*"<<sizeof(T)<<"="<<this->len    *sizeof(T)<<" bytes memory in heap";
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
};


//StudybarCommentBegin
int main()
{
    int length,i;
    cin>> length;
    DynamicArray<int> iarray(length,-1);
    DynamicArray<double> darray(length,-2.1);
    const DynamicArray<char> carray(length,'c');
    cout<<endl<<"capacity:"<<carray.capacity()<<endl;
    for(i=0;i<length;i++) {
        cout << carray[i] <<" ";
    }
    cout<<endl;
    for(i=0;i<length;i++) {
        cout << iarray[i] <<" ";
        iarray[i] = i*1.1;
    }
    cout<<endl;
    for(i=0;i<length;i++) {
        cout << darray[i] <<" ";
        darray[i] = i*1.1;
    }
    cout<<endl;
    for(i=0;i<length;i++) {
        cout << iarray[i] <<" ";
        iarray[i] = i*1.1;
    }
    cout<<endl;
    for(i=0;i<length;i++) {
        cout << darray[i] <<" ";
    }
    return 0;
}
//StudybarCommentEnd