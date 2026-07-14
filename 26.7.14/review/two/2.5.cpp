#include <iostream>
#include <iomanip>
using namespace std;
class Rectangle{
    double l,w;
    public:
        Rectangle(double l=1, double w=1):l(l), w(w){
            if(l<=0.0 || l>=20.0){l=1;}
            if(w<=0.0 || w>=20.0){w=1;}
        }
        void setLength(double t){
            l=t;
            if(l<=0.0 || l>=20.0){l=1;}
        }
        void setWidth(double t){
            w=t;
            if(w<=0.0 || w>=20.0){w=1;}
        }
        double perimeter(){
            return 2*(l+w);
        }
        double area(){
            return l*w;
        }
};
//StudybarCommentBegin
int main()
{
    Rectangle r;
    double length,width;
    
//    cout<<"please input the length of Rectangle:";
    cin>>length;
//    cout<<"please input the width of Rectangle:";
    cin>>width;
    r.setLength(length);
    r.setWidth(width);
    cout<<"the perimeter is:"<<setprecision(2)<<fixed<<r.perimeter()<<endl;
    cout<<"the area is:"<<setprecision(2)<<fixed<<r.area()<<endl;
    return 0;
    
}
//StudybarCommentEnd