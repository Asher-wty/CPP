#include <iostream>
using namespace std;

template<class T,int N>
class Array{
    T a[N];
    static int cnt;
    public:
        Array(){ cnt++;}
        static int getArrayCount(){
            return cnt;
        }
        int getSize() {return N;}
        friend istream &operator>>(istream &in, Array<T, N> &t)
        {
            for (int i = 0; i < N; i++)
            {
                in >> t.a[i];
            }
            return in;
        }
        friend ostream& operator <<(ostream& out, Array<T,N> t){
            for(int i=0;i<N;i++){
                out<<t.a[i]<<' ';
            }
            out<<endl;
            return out;
        }
};
template<class T,int N>
int Array<T,N>::cnt=0;
//StudybarCommentBegin
int main()
{
    // create intArray object
    Array<int, 5> intArray1;
    // initialize intArray with user input values
    cin >> intArray1;

    // create intArray object
    Array<int, 5> intArray2;

    // initialize intArray with user input values
    cin >> intArray2;

    // create floatArray
    Array<float, 5> floatArray;

    cin >> floatArray;

    // output intArray1
    cout << "\nIntArray1 contains " << intArray1.getSize() << " Elements.\n";
    cout << "The values in intArray are:\n";
    cout << intArray1;

    // output intArray2
    cout << "\nIntArray2 contains " << intArray2.getSize() << " Elements.\n";
    cout << "The values in intArray are:\n";
    cout << intArray2;

    // output floatArray
    cout << "\nDoubleArray contains " << floatArray.getSize() << " Elements.\n";
    cout << "The values in the doubleArray are:\n";
    cout << floatArray;

    cout << "\nThere are " << Array<int, 5>::getArrayCount() << " Array<int,5> objects.\n";
    cout << "\nThere are " << Array<float, 5>::getArrayCount() << " Array<float,5> objects.\n";

    return 0;

} // end main

//StudybarCommentEnd