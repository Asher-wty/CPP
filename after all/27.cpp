#include <iostream>
using namespace std;

template<typename T>
class Queue {
private:
    T* array;
    int count;
    int SIZE;
public:
    Queue();
    ~Queue();
    void insert(const T& Item);
    T remove();
    void clear();
    const T& getFront() const;
    int getLength() const;
    bool isEmpty() const;
    bool isFull() const;
    friend ostream& operator<<(ostream& os, const Queue& q) {
        for (int i = 0; i < q.count; ++i) {
            if (i) os << ' ';
            os << q.array[i];
        }
        os << endl;  // 添加换行，与期望输出一致
        return os;
    }
};

template<typename T>
Queue<T>::Queue() : array(nullptr), count(0), SIZE(0) {}

template<typename T>
Queue<T>::~Queue() { delete[] array; }

template<typename T>
void Queue<T>::insert(const T& Item) {
    if (SIZE == 0) {
        SIZE = 1;
        array = new T[SIZE];
        array[0] = Item;
        count = 1;
    } else if (count < SIZE) {
        array[count] = Item;
        ++count;
    } else {
        SIZE *= 2;
        T* newArray = new T[SIZE];
        for (int i = 0; i < count; ++i) newArray[i] = array[i];
        delete[] array;
        array = newArray;
        array[count] = Item;
        ++count;
    }
}

template<typename T>
T Queue<T>::remove() {
    if (count == 0) {
        cout << "The queue is empty";
        exit(1);
    }
    T front = array[0];
    for (int i = 0; i < count - 1; ++i) array[i] = array[i + 1];
    --count;
    return front;
}

template<typename T>
void Queue<T>::clear() {
    delete[] array;
    array = nullptr;
    count = 0;
    SIZE = 0;
}

template<typename T>
const T& Queue<T>::getFront() const {
    if (count == 0) {
        cout << "The queue is empty";
        exit(1);
    }
    return array[0];
}

template<typename T>
int Queue<T>::getLength() const { return count; }

template<typename T>
bool Queue<T>::isEmpty() const { return count == 0; }

template<typename T>
bool Queue<T>::isFull() const { return count == SIZE; }

//StudybarCommentBegin
int main() 
{
	Queue<double> z1;
	double num[5]={2.53,4.3,6.75,8.9};
	int i;
	double x;
	cin>>x;
	for(i=0;i<4;i++)
	{
		z1.insert(num[i]);
	}
	cout<<z1.getLength();  //初始定义的数组长度 
	
	cout<<endl;
	
	z1.insert(x);         //插入一个double类元素 
	
	cout<<z1.isFull()<<endl;   //判断是否为满 
	
	cout<<z1.getLength(); //插入元素后的长度 
	
	cout<<endl; 
	
	cout<<z1.getFront();  //初始队首元素值 
	
	cout<<endl;
	
	z1.remove();    //删掉队首元素 
	
	cout<<z1.getFront();  //删除后的队首元素 
	
	cout<<endl;

	cout<<z1;              //输出现在z1中的各元素值 
	
	z1.clear();            //清空z1 
	
	cout<<z1.isEmpty()<<endl;    //判断是否为空 
	
	z1.getFront();         // 访问队首元素 
	
	return 0;
}
//StudybarCommentEnd