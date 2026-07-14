#include <iostream>
using namespace std;

template<typename T>
class Queue {
private:
    T* array;
    int count;
    int SIZE;
public:
    Queue() : array(nullptr), count(0), SIZE(0) {}
    ~Queue() { delete[] array; }
    void insert(const T& Item) {
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
    T remove() {
        if (count == 0) {
            cout << "The queue is empty";
            exit(1);
        }
        T front = array[0];
        for (int i = 0; i < count - 1; ++i) array[i] = array[i + 1];
        --count;
        return front;
    }
    void clear() {
        delete[] array;
        array = nullptr;
        count = 0;
        SIZE = 0;
    }
    friend ostream& operator<<(ostream& os, const Queue& q) {
        for (int i = 0; i < q.count; ++i) {
            if (i) os << ' ';
            os << q.array[i];
        }
        os << endl;
        return os;
    }
};

//StudybarCommentBegin
int main() 
{
    Queue<int> z1;
    int num[5]={2,4,6,8};
    int i,x;
    cin>>x;
    for(i=0;i<4;i++)
    {
        z1.insert(num[i]);
    }
    z1.insert(x);
    
    cout<<z1.remove();
    
    cout<<endl;

    cout<<z1;
    
    z1.clear();
    
    z1.remove();
    
    return 0;
}
//StudybarCommentEnd