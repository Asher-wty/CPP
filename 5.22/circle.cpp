#include<iostream>
using namespace std;
class point{
    private:
        double x,y;
    public:
        void setPoint(double a, double b){
            x=a;
            y=b;
        }
}; 
class Circle :public point
{
    private:
        double r;
    public:
        void setRadius(double t){
            r=t;
        }
        double getArea(){
            return 3.1415926*r*r;
        }
};

//StudybarCommentBegin
int main()
{
	Circle c;
	c.setPoint(1,1);
	c.setRadius(2);
	cout<<c.getArea();
}
//StudybarCommentEnd