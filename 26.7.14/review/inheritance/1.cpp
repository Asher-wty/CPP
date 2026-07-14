#include <iostream>
using namespace std;
class Point{
    double x,y;
    public:
        void setPoint(int x, int y){
            this->x=x;
            this->y=y;
        }
};
class Circle: public Point{
    double r;
    public:
        void setRadius(double r){
            this->r=r;
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