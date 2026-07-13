#include <iostream>
using namespace std;
class Point{
    double x,y;
    public:
        void setPoint(double x, double y){
            this->x=x;
            this->y=y;
        }
        double GetX() const{return x;}
        double GetY() const{return y;}
        void Move(double x,double y){
            this->x+=x;
            this->y+=y;
        }
};
class Rectangle : private Point{
    double w,h;
    public:
        void SetRect(double a, double b, double c, double d){
            setPoint(a,b);
            w=c;
            h=d;
        }
        double GetW() const{return w;}
        double GetH() const{return h;}
        double GetY() const{return Point::GetY();}
        double GetX() const{return Point::GetX();}
        void Move(double a, double b){
            Point::Move(a,b);
        }
};
//StudybarCommentBegin
int main()
{
	Rectangle rect;
	rect.SetRect(0,0,1,1);
	rect.Move(3,2);
	cout<<"sizeof(Point):"<<sizeof(Point)<<" and sizeof(rect):" 
	    <<sizeof(rect)<<", (x,y,w,h) is ("<<rect.GetX()<<","
	    <<rect.GetY()<<","<<rect.GetW()<<","<<rect.GetH()<<")";
	return 0;
	
}
//StudybarCommentEnd
