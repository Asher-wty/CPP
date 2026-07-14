#include <iostream>
#include <cmath>
using namespace std;
class Point{
    protected:
        double x,y;
    public:
        void SetPoint(double a, double b){
            x=a;
            y=b;
        }
        void Move(double a, double b){
            x+=a;
            y+=b;
        }
        double GetX() const{return x;}
        double GetY() const{return y;}     
};
class Rectangle:public Point{
    double w,h;
    public:
        void SetRect(double a, double b, double c, double d){
            SetPoint(a,b);
            w=c;
            h=d;
        }
        double GetW() const {return w;}
        double GetH() const {return h;}
        double DistOfTwoR(const Rectangle & other){
            double dx=x-other.x;
            double dy=y-other.y;
            return sqrt(dx*dx+dy*dy);
        }
};
//StudybarCommentBegin
int main()
{
	Rectangle rect,rect2;
	rect.SetRect(0,0,1,1);
	rect.Move(3,2);
	cout<<"sizeof(Point):"<<sizeof(Point)<<" and sizeof(rect):" 
	    <<sizeof(rect)<<", (x,y,w,h) is ("<<rect.GetX()<<","
	    <<rect.GetY()<<","<<rect.GetW()<<","<<rect.GetH()<<")";
	rect2.SetRect(1,1,1,1);
	rect2.Move(2,3);
	cout<<endl<<rect2.DistOfTwoR(rect);
	return 0;
}
//StudybarCommentEnd