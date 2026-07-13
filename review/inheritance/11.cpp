#include<iostream>
using namespace std;
//爷爷
class Shape{
    protected:
        double x,y,z;
    public:
        Shape(double x=0, double y=0, double z=0):x(x), y(y), z(z){}
        virtual ~Shape(){};
        virtual void print(ostream& o) const = 0;        
};
ostream & operator <<(ostream& out, const Shape& t){
    t.print(out);
    return out;
}
//父亲
class TwoDimensionalShape: public Shape{
    public:
        TwoDimensionalShape(double a=0, double b=0): Shape(a,b,0){}
        virtual ~TwoDimensionalShape(){}
        virtual double getArea() =0;
};
class ThreeDimensionalShape: public Shape{
    public:
        ThreeDimensionalShape(double a=0, double b=0,double c=0): Shape(a,b,c){}
        virtual ~ThreeDimensionalShape(){}
        virtual double getArea() =0;
        virtual double getVolume()=0;
};
//儿子
class Circle: public TwoDimensionalShape{
    double r;
    public:
        Circle(double r=0, double a=0, double b=0):TwoDimensionalShape(a,b), r(r){}
        double getArea(){ return 3.14159*r*r;}
        void print(ostream& o) const{
            o<< "Circle with radius " << r << "; center at ("<< x << ", " << y << ")";
        }
};
class Square: public TwoDimensionalShape{
    double s;
    public:
        Square(double s=0, double a=0, double b=0):TwoDimensionalShape(a,b), s(s){}
        double getArea(){ return s*s;}
        void print(ostream& o) const{
            o<< "Square with side length " <<s<< "; center at ("<<x<< ", " <<y << ")";
        }
};
class Sphere: public ThreeDimensionalShape{
    double r;
    public:
        Sphere(double r=0, double a=0, double b=0, double c=0): ThreeDimensionalShape(a,b,c), r(r){}
        double getArea(){return 4*3.14159*r*r;}
        double getVolume(){return (4.0/3.0)*3.14159*r*r*r;}
        void print(ostream& o) const{
            o<< "Sphere with radius " << r << "; center at ("<< x << ", " << y<< ")";
        }
};
class Cube: public ThreeDimensionalShape{
    double l;
    public:
        Cube(double l=0, double a=0, double b=0, double c=0): ThreeDimensionalShape(a,b,c), l(l){}
        double getArea(){return 6*l*l;}
        double getVolume(){return l*l*l;}
        void print(ostream& o) const{
            cout << "Cube with side length " <<l << "; center at ("<< x<< ", " << y<< ")";
        }
};
//StudybarCommentBegin
int main()
{
    Shape * shapes[4];
    
    // initialize vector with Shapes
    shapes[ 0 ] = new Circle( 3.5, 6, 9 );
    shapes[ 1 ] = new Square( 12, 2, 2 );
    shapes[ 2 ] = new Sphere( 5, 1.5, 4.5 );
    shapes[ 3 ] = new Cube( 2.2 ); 
    // output Shape objects and display area and volume as appropriate
    for ( int i = 0; i < 4; i++ )
    {
        cout << *( shapes[ i ] ) << endl; 
        // downcast pointer
        TwoDimensionalShape *twoDimensionalShapePtr =
        dynamic_cast < TwoDimensionalShape * > ( shapes[ i ] );
        
        // if Shape is a TwoDimensionalShape, display its area
        if ( twoDimensionalShapePtr != 0 )
            cout << "Area: " << twoDimensionalShapePtr->getArea() << endl;
        
        // downcast pointer
        ThreeDimensionalShape *threeDimensionalShapePtr =
        dynamic_cast < ThreeDimensionalShape * > ( shapes[ i ] );
        
        // if Shape is a ThreeDimensionalShape, display its area and volume
        if ( threeDimensionalShapePtr != 0 )
            cout << "Area: " << threeDimensionalShapePtr->getArea()
            << "\nVolume: " << threeDimensionalShapePtr->getVolume()
            << endl;
        
        cout << endl;
    } // end for
    
    return 0;
} // end main

//StudybarCommentEnd