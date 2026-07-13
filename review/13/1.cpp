#include <iostream>
using namespace std;
class Point
{
    int x,y;
    public:
        Point(int X=0, int Y=0): x(X), y(Y){
            cout<<"\nPoint is called!";
        }   
        ~Point(){
            cout<<"\n~Point is called!";
        }  
        friend ostream& operator <<(ostream& out,const Point& p){
            out<<"("<<p.x<<","<<p.y<<")";
            return out;
        }
};
template <typename T>
class DynamicArray
{
private:
    T *array;                // pointer  ，一个T类型的指针
    unsigned int mallocSize; // 分配空间的大小。
public:
    DynamicArray(unsigned length, const T &content){
        mallocSize=length;
        cout<<endl<< "new T["<<this->mallocSize<<"] malloc "<< this->mallocSize << "*"<<sizeof(T)<<"="<<this->mallocSize *sizeof(T)<<" bytes memory in heap";
        array=new T[length];      
        for(int i=0;i<length;i++){
            array[i]=content;
        } 
    }
    DynamicArray():mallocSize(0), array(nullptr){}
    DynamicArray(const DynamicArray& copy){
        mallocSize=copy.mallocSize;
        cout<<endl<< "Copy Constructor is called";
        array=new T[mallocSize];
        for(int i=0;i<mallocSize;i++){
            array[i]=copy.array[i];
        }
    }
    ~DynamicArray(){
        cout<<endl<< "delete[] array free "<< this->mallocSize << "*"<<sizeof(T)<<"="<<this->mallocSize *sizeof(T)<<" bytes memory in heap";
        delete [] array;
    }
    unsigned int capacity() const{return mallocSize;}
    // for the array[i]=someT.
    T &operator[](unsigned int i){
        return array[i];
    };
    const T &operator[](unsigned int i)const{
        return array[i];
    }
    DynamicArray & operator =(const DynamicArray& copy){
        cout<<endl<<"operator = is called";
        delete [] array;
        mallocSize=copy.mallocSize;
        array=new T[mallocSize];
        for(int i=0;i<mallocSize;i++){
            array[i]=copy.array[i];
        }
        return *this;
    }
    int resize(unsigned int newSize, const T& ValOfNewItems){
        cout<<"\nresize is called";
        if(mallocSize>newSize){
            T* newarray=new T[newSize];
            for(int i=0;i<newSize;i++){
                newarray[i]=array[i];
            }
            mallocSize=newSize;
            delete []array;
            array=newarray;
            return -1;
        }
        else if(mallocSize<newSize){
            T* newarray=new T[newSize];
            for(int i=0;i<newSize;i++){
                if(i<mallocSize){
                    newarray[i]=array[i];
                }
                else
                newarray[i]=ValOfNewItems;
            }
            mallocSize=newSize;
            delete[] array;
            array=newarray;
            return 1;
        }
        else return 0;
    }
};
//StudybarCommentBegin
int main()
{
	int i,j;
	DynamicArray<int>  a(20,0);	
	DynamicArray<DynamicArray<int> > b(10,a);
	b[0].resize(30,1);
	b[5].resize(10,5);
	for(i=0;i<10;i++)
	{	cout<<"\n";		
		for(j=0;j<b[i].capacity();j++)
		{	cout<<" "<<b[i][j] ;}
	}
	return 0;
}
//StudybarCommentEnd