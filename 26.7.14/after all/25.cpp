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
        } else { // count == SIZE
            SIZE *= 2;
            T* newArray = new T[SIZE];
            for (int i = 0; i < count; ++i) newArray[i] = array[i];
            delete[] array;
            array = newArray;
            array[count] = Item;
            ++count;
        }
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
    cout<<z1;
    return 0;
}
//StudybarCommentEnd