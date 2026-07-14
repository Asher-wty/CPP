#include <iostream>
#include <stdexcept>
using namespace std;

class TriExcpt : public runtime_error {
public:
    TriExcpt(const char* msg) : runtime_error(msg) {}
    const char* what() const throw() {
        return runtime_error::what();
    }
};

class SubTriExcpt : public TriExcpt {
public:
    SubTriExcpt(const char* msg) : TriExcpt(msg) {}
    const char* what() const throw() {
        return TriExcpt::what();
    }
};

class triangle {
private:
    float a, b, c;
public:
    triangle(float x, float y, float z) : a(x), b(y), c(z) {
        judgement();
    }
    ~triangle() {}
    void judgement() {
        if (a == 0 && b == 0 && c == 0)
            throw runtime_error("All o inputted.");
        if (a == 0 || b == 0 || c == 0)
            throw SubTriExcpt("Not a triangle, a=0.");
        if (a + b == c || a + c == b || b + c == a)
            throw TriExcpt("Not a normal triangle, a=b+c.");
        if (a + b < c || a + c < b || b + c < a)
            throw SubTriExcpt("Not a triangle, a>b+c.");
    }
    float perimeter() {
        return a + b + c;
    }
};

//StudybarCommentBegin
int main()
{
	float a, b, c;
	cin >> a >> b >> c;
	try	{
		triangle Tr1(a, b, c);
		cout << Tr1.perimeter() << endl;
	}
	catch (runtime_error &e) {
		cout << e.what() << endl;
	}
        return 1;
}
//StudybarCommentEnd