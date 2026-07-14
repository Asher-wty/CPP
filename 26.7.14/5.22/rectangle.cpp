#include<iostream>
using namespace std;
class Point{
    double x,y;
    public:
        double GetX() const{
            return x;
        }
        double GetY() const{
            return y;
        }
        void Setpoint(double tx,double ty){
            x=tx;
            y=ty;
        }
        void Move(double mx,double my){
            x+=mx;
            y+=my;
        }
};
class Rectangle: public Point{
    double w,h;
    public:
        double GetW(){
            return w;
        }
        double GetH(){
            return h;
        }
        void SetRect(double x, double y, double wide, double high){
            Setpoint(x,y);
            w=wide;
            h=high;
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