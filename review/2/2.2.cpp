//StudybarCommentBegin
#include<iostream>
using namespace std;


//StudybarCommentEnd
// 返回 int 数组的中间值
int middle(int arr[]) {
    int a = arr[0], b = arr[1], c = arr[2];
    if ((a >= b && a <= c) || (a <= b && a >= c))
        return a;
    if ((b >= a && b <= c) || (b <= a && b >= c))
        return b;
    return c;
}

// 返回 double 数组的中间值
double middle(double arr[]) {
    double a = arr[0], b = arr[1], c = arr[2];
    if ((a >= b && a <= c) || (a <= b && a >= c))
        return a;
    if ((b >= a && b <= c) || (b <= a && b >= c))
        return b;
    return c;
}

// 返回 unsigned 数组的中间值
unsigned middle(unsigned arr[]) {
    unsigned a = arr[0], b = arr[1], c = arr[2];
    if ((a >= b && a <= c) || (a <= b && a >= c))
        return a;
    if ((b >= a && b <= c) || (b <= a && b >= c))
        return b;
    return c;
}
//StudybarCommentBegin
int main()
{
	int iNumber[3]={45,3,89};
	double dNumber[3]={12.4,6,55.8};
	unsigned uNumber[3]={345,776,565};

	cout<<"\nThe numbers are ";
	for( int i=0;i<3;i++)
		cout<<iNumber[i]<<"\t";
	cout<<endl<<"the middle of them is "<<middle(iNumber)<<endl;

	cout<<"\nThe numbers are ";
	for( int i=0;i<3;i++)
		cout<<dNumber[i]<<"\t";
	cout<<endl<<"the middle of them is "<<middle(dNumber)<<endl;

	cout<<"\nThe numbers are ";
	for( int i=0;i<3;i++)
		cout<<uNumber[i]<<"\t";
	cout<<endl<<"the middle of them is "<<middle(uNumber)<<endl;

	return 0;
}
//StudybarCommentEnd