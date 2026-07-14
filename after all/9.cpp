#include <iostream>
using namespace std;

template <class T>
class DynamicVector
{
    T* array;
    unsigned mallocSize;
    unsigned numofItems;
    int virtualZero;

public:
    DynamicVector (int);
    ~DynamicVector();
    inline void push_back (const T&);
    T& operator[] (int Vindex);
    unsigned length() const;
    unsigned capacity() const;
    int firstIndex() const;
};

template <class T>
DynamicVector<T>::DynamicVector(int Vindex)
{
    array = NULL;
    numofItems = 0;
    mallocSize = 0;
    virtualZero = Vindex;
}

template <class T>
DynamicVector<T>::~DynamicVector()
{
    delete[] array;
}

template <class T>
void DynamicVector<T>::push_back(const T& newItem)
{
    if (numofItems < mallocSize) {
        array[numofItems] = newItem;
        numofItems++;
    } else {
        unsigned newSize = (mallocSize == 0) ? 1 : (2 * mallocSize + 1);
        T* newArray = new T[newSize];
        for (unsigned i = 0; i < numofItems; ++i) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        mallocSize = newSize;
        array[numofItems] = newItem;
        numofItems++;
    }
}

template <class T>
T& DynamicVector<T>::operator[] (int Vindex)
{
    int _entry = Vindex - virtualZero;
    if (_entry < 0 || _entry >= (int)numofItems)
    {
        cout << endl << "Out Of Range";
        exit(1);
    }
    return array[_entry];
}

template <class T>
unsigned DynamicVector<T>::length() const
{
    return numofItems;
}

template <class T>
unsigned DynamicVector<T>::capacity() const
{
    return mallocSize;
}

template <class T>
int DynamicVector<T>::firstIndex() const
{
    return virtualZero;
}

//StudybarCommentBegin
int main()
{
    int i,n;
    DynamicVector<int> ra(-2);
    
    cin>>n;
    ra.push_back(-3);
    ra.push_back(-2);
    ra.push_back(-1);
    for ( i = 0; i < n; i++)
    {
      ra.push_back(i);
    }
    cout<<"\n malloSize is "<<ra.capacity();
    cout<<"\n numofItems is "<<ra.length();
    cout<<"\n StartIndex is " << ra.firstIndex()<<endl;
    for ( i = -2; i < n+3; i++)
    {
      cout<<ra[i]<<" ";
    }
    

  return 0;
}
//StudybarCommentEnd