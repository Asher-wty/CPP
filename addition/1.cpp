#include<iostream>
#include<cmath>
using namespace std;
class Cmycomplex{
    private:
        double real,imagine;
        double size=sqrt(real*real+imagine*imagine);
    public:
        void Set(double r, double i){
            real=r;
            imagine=i;
        }
};
class Cassemblage{
    private:
        Cmycomplex* p;
        int size;
    public:
        void Set(Cmycomplex* t, int s){
            p=t;
            size=s;
        }

};
//StudybarCommentBegin
int main(int argc, char* argv[])
{
	Cassemblage z1, z2, x1, x2, x3;
	Cmycomplex a1[1000], a2[1000];
	int i, n1, n2;
	double a11[1000], a12[1000], a21[1000], a22[1000];
	
	cin >> n1;
	for(i=0; i<n1; i++)
	{
		cin >> a11[i] >> a12[i];
		a1[i].Set(a11[i], a12[i]);
	}
       z1.Set(a1, n1);

	cin >> n2;
	for(i=0; i<n2; i++)
	{
		cin >> a21[i] >> a22[i];
		a2[i].Set(a21[i], a22[i]);
	}	
	z2.Set(a2, n2);

	x1=z1+z2;
	x1.Show();
	cout << endl;

	x2=z1&z2;
	x2.Show();
	cout << endl;

	x3=z1-z2;
	x3.Show();


	return 0;
}

//StudybarCommentEnd
