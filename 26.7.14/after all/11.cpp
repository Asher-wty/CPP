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
    DynamicVector(const DynamicVector&);
    ~DynamicVector();
    inline void push_back (const T&);
    void push_back (const DynamicVector&);
    DynamicVector& operator=(const DynamicVector&);
    T& operator[] (int Vindex);
    const T& operator[] (int Vindex) const;
    unsigned length() const;
    unsigned capacity() const;
    int firstIndex() const;
    bool operator == (const  DynamicVector<T>& dv) const;
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
DynamicVector<T>::DynamicVector(const DynamicVector& other)
{
    virtualZero = other.virtualZero;
    numofItems = other.numofItems;
    mallocSize = other.mallocSize;
    if (mallocSize == 0) {
        array = NULL;
    } else {
        array = new T[mallocSize];
        for (unsigned i = 0; i < numofItems; ++i)
            array[i] = other.array[i];
    }
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
        ++numofItems;
    } else {
        unsigned newSize = (mallocSize == 0) ? 1 : (2 * mallocSize + 1);
        T* newArray = new T[newSize];
        for (unsigned i = 0; i < numofItems; ++i)
            newArray[i] = array[i];
        delete[] array;
        array = newArray;
        mallocSize = newSize;
        array[numofItems] = newItem;
        ++numofItems;
    }
}

template <class T>
void DynamicVector<T>::push_back(const DynamicVector& other)
{
    int start = other.firstIndex();
    int len = other.length();
    for (int i = 0; i < len; ++i) {
        push_back(other[start + i]);
    }
}

template <class T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector& other)
{
    if (this == &other) return *this;
    delete[] array;
    virtualZero = other.virtualZero;
    numofItems = other.numofItems;
    mallocSize = other.mallocSize;
    if (mallocSize == 0) {
        array = NULL;
    } else {
        array = new T[mallocSize];
        for (unsigned i = 0; i < numofItems; ++i)
            array[i] = other.array[i];
    }
    return *this;
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
const T& DynamicVector<T>::operator[] (int Vindex) const
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

template <class T>
bool DynamicVector<T>::operator == (const DynamicVector<T>& dv) const
{
    if (virtualZero != dv.virtualZero) return false;
    if (numofItems != dv.numofItems) return false;
    for (unsigned i = 0; i < numofItems; ++i) {
        if (array[i] != dv.array[i]) return false;
    }
    return true;
}
//StudybarCommentBegin
int main()
{
    DynamicVector<int> ra(-2);
    int i,n;
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
    for ( i = -2; i < n+1; i++)
    {
      cout<<ra[i]<<" ";      
    }
    cout<<endl;
    DynamicVector<int> raCopy(ra);
    cout<<"\n malloSize is "<<raCopy.capacity();
    cout<<"\n numofItems is "<<raCopy.length();
    cout<<"\n StartIndex is " << raCopy.firstIndex()<<endl;
    cout<<endl;
    for ( i = -2; i < n+1; i++)
    {   cout<<++ra[i]<<" ";      
    }
    cout<<endl;
    for ( i = -2; i < n+1; i++)
    {   cout<<raCopy[i]<<" ";      
    }
    
    raCopy=ra;
    if (ra==raCopy)  cout<<"\n ra == raCopy";
    else cout<<"\n ra != raCopy";
    
	 
    ra[-2]=100;
    
    if (ra==raCopy)  cout<<"\n ra == raCopy";
    else cout<<"\n ra != raCopy";
    
    raCopy.push_back(ra);
    cout<<endl;
    int firstI=raCopy.firstIndex();
    for ( i = 0; i < (int)raCopy.length() ; i++)
    {   cout<<raCopy[i+firstI ]<<" ";      
    }
    
 
  return 0;
}
//StudybarCommentEnd