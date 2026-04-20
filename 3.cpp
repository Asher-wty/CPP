#include <iostream>
using namespace std;

template <typename T>
class DynamicArray {
private:
    T* array;
    unsigned int mallocSize;

public:

    DynamicArray(unsigned length, const T &content) : mallocSize(length) {
        array = new T[length];
        for (unsigned i = 0; i < length; ++i) {
            array[i] = content;
        }

        cout << "new T[" << mallocSize << "] malloc " << mallocSize
             << "*" << sizeof(T) << "=" << mallocSize * sizeof(T)
             << " bytes memory in heap";
    }

    ~DynamicArray() {
        delete[] array;
        cout << "delete[] array free " << mallocSize << "*" << sizeof(T)
             << "=" << mallocSize * sizeof(T) << " bytes memory in heap";
    }

    unsigned int capacity() const {
        return mallocSize;
    }

    T& operator[](unsigned int i) {
        return array[i];
    }
};

//StudybarCommentBegin
int main()
{
    int length, i;
    cin >> length;

    DynamicArray<int> iarray(length, -1);
    DynamicArray<double> darray(length, -2.1);

    cout << endl << "capacity:" << iarray.capacity() << endl;

    for (i = 0; i < length; i++) {
        cout << iarray[i] << " ";
        iarray[i] = i * 1.1;
    }
    cout << endl;
    for (i = 0; i < length; i++) {
        cout << darray[i] << " ";
        darray[i] = i * 1.1;
    }
    cout << endl;
    for (i = 0; i < length; i++) {
        cout << iarray[i] << " ";
        iarray[i] = i * 1.1;
    }
    cout << endl;
    for (i = 0; i < length; i++) {
        cout << darray[i] << " ";
    }
    // 程序结束时，darray 和 iarray 依次析构，输出析构信息（不带换行）
    return 0;
}
//StudybarCommentEnd