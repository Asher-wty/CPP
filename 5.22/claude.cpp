#include <iostream>
#include <cmath>
using namespace std;

class Cmycomplex {
private:
    double real;
    double imag;
public:
    Cmycomplex() : real(0), imag(0) {}

    void Set(double r, double i) {
        real = r;
        imag = i;
    }

    double GetReal() const { return real; }
    double GetImag() const { return imag; }

    double modulus() const {
        return sqrt(real * real + imag * imag);
    }

    bool operator==(const Cmycomplex& other) const {
        return real == other.real && imag == other.imag;
    }

    void Print() const {
        if (imag >= 0)
            cout << "(" << real << "+" << imag << "i)";
        else
            cout << "(" << real << imag << "i)";
    }
};

class Cassemblage {
private:
    Cmycomplex data[1000];
    int size;

public:
    Cassemblage() : size(0) {}

    void Set(Cmycomplex arr[], int n) {
        size = 0;
        for (int i = 0; i < n; i++) {
            bool found = false;
            for (int j = 0; j < size; j++) {
                if (data[j] == arr[i]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                data[size++] = arr[i];
            }
        }
    }

    Cassemblage operator+(const Cassemblage& other) const {
        Cassemblage result;
        for (int i = 0; i < size; i++) {
            result.data[result.size++] = data[i];
        }
        for (int i = 0; i < other.size; i++) {
            bool found = false;
            for (int j = 0; j < result.size; j++) {
                if (result.data[j] == other.data[i]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                result.data[result.size++] = other.data[i];
            }
        }
        return result;
    }

    Cassemblage operator&(const Cassemblage& other) const {
        Cassemblage result;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < other.size; j++) {
                if (data[i] == other.data[j]) {
                    bool found = false;
                    for (int k = 0; k < result.size; k++) {
                        if (result.data[k] == data[i]) {
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        result.data[result.size++] = data[i];
                    }
                    break;
                }
            }
        }
        return result;
    }

    Cassemblage operator-(const Cassemblage& other) const {
        Cassemblage result;
        for (int i = 0; i < size; i++) {
            bool found = false;
            for (int j = 0; j < other.size; j++) {
                if (data[i] == other.data[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                result.data[result.size++] = data[i];
            }
        }
        return result;
    }

    void Show() const {
        if (size == 0) {
            cout << "empty";
            return;
        }
        Cmycomplex sorted[1000];
        for (int i = 0; i < size; i++) {
            sorted[i] = data[i];
        }
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - 1 - i; j++) {
                if (sorted[j].modulus() > sorted[j + 1].modulus()) {
                    Cmycomplex temp = sorted[j];
                    sorted[j] = sorted[j + 1];
                    sorted[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < size; i++) {
            if (i > 0) cout << " ";
            sorted[i].Print();
        }
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
