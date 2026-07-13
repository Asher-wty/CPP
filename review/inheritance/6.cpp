//StudybarCommentBegin
#include <iostream>
#include <cmath>
using namespace std;
class Point 
{
protected:
	double x,y;
public:
	Point(double x=0,double y=0)
	{ this->x=x; this->y=y;	}
	void SetPoint(double x=0,double y=0)
	{ this->x=x; this->y=y;	}
	double GetX() const {return x;}
	double GetY() const {return y;}
	void Move(double xOff, double yOff)
	{ x+=xOff; y+=yOff; }
	double Dist(Point const &p) const {
		double tmpx=x-p.x;
		double tmpy=y-p.y;
		return  ::sqrt(tmpx*tmpx+tmpy*tmpy);
	}	
};
class Rectangle: public Point
{
public:
	void SetRect(double x,double y,double w,double h)
		{SetPoint(x,y); this->w=w; this->h=h;}
	double GetW() const {return w;}
	double GetH() const {return h;}
	double DistOfTwoR(const Rectangle &R) {		
		return  this->Dist(R);
	}
protected:
	double w,h;	
};
//StudybarCommentEnd
class RectWithAngle: public Rectangle{
    double angle;
    public:
        RectWithAngle(double a, double b, double c, double d, double e){
            SetRect(a,b,c,d);
            angle=e;
        }
        int IsPointInMe(const Point& p){
            double dx=p.GetX()-GetX();
            double dy=p.GetY()-GetY();
            double a=angle/180*M_PI;
            double X=dx*cos(a)+dy*sin(a);
            double Y=-dx*sin(a)+dy*cos(a);
            return (X<=w &&Y<=h);
        }
};

//StudybarCommentBegin
int main()
{
	double angle;
	double x,y;
	cin>> angle;
	cin>>x>>y;
	RectWithAngle  R1(0,0,8.5,5,angle);
	R1.Move(2,2);
	Point p;
	p.SetPoint(x,y);
	cout<< R1.IsPointInMe(p);
	return 0;
}
//StudybarCommentEnd