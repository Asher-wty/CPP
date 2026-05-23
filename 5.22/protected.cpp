#include<iostream>
#include<cmath>
using namespace std;
class Point{
    protected:
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
            this->x=x;
            this->y=y;
            w=wide;
            h=high;
        }
        void Move(double mx,double my){
            Point::Move(mx,my);
        }
        double DistOfTwoR(const Rectangle &t){
            double tx=x-t.x;
            double ty=y-t.y;
            return std::sqrt(tx*tx+ty*ty);
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