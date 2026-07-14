//StudybarCommentBegin
#include <iostream>
#include <iterator>
using namespace std;
class MyLess {
public:
    bool operator() (int a1,int a2) {
        if( ( a1 % 10 ) < (a2%10) )
            return true;
        else
            return false;
    }
};
bool MyCompare(int a1,int a2)
{
    if( ( a1 % 10 ) < (a2%10) )
        return false;
    else
        return true;
}
//StudybarCommentEnd

template <class Iterator, class Compare>
Iterator MyMax(Iterator first, Iterator last, Compare comp) {
    if (first == last) return last;
    Iterator maxIter = first;
    for (Iterator it = first; it != last; ++it) {
        if (comp(*maxIter, *it)) {
            maxIter = it;
        }
    }
    return maxIter;
}

//StudybarCommentBegin
int main()
{
    int a[] = {35,7,13,19,12};
    cout << * MyMax(a,a+5,MyLess())
    << endl;
    cout << * MyMax(a,a+5,MyCompare)
    << endl;
    return 0;
}
//StudybarCommentEnd