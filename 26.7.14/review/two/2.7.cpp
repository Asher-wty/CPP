#include <iostream>
#include <cmath>
using namespace std;

class Rectangle {
private:
    double coords[4][2];

    double distSq(int i, int j) const {
        double dx = coords[i][0] - coords[j][0];
        double dy = coords[i][1] - coords[j][1];
        return dx * dx + dy * dy;
    }

    double dist(int i, int j) const {
        return sqrt(distSq(i, j));
    }

    double dot(int i, int j, int k, int l) const {
        double vx = coords[j][0] - coords[i][0];
        double vy = coords[j][1] - coords[i][1];
        double wx = coords[l][0] - coords[k][0];
        double wy = coords[l][1] - coords[k][1];
        return vx * wx + vy * wy;
    }

    bool isValidRectangle() const {
        const double eps = 1e-6;
        double lenAB = dist(0, 1);
        double lenCD = dist(2, 3);
        if (fabs(lenAB - lenCD) > eps) return false;

        double cross = (coords[1][0] - coords[0][0]) * (coords[3][1] - coords[2][1])
                     - (coords[1][1] - coords[0][1]) * (coords[3][0] - coords[2][0]);
        if (fabs(cross) > eps) return false;

        bool ok1 = (fabs(dist(0, 2) - dist(1, 3)) <= eps) && (fabs(dot(0, 1, 0, 2)) <= eps);
        bool ok2 = (fabs(dist(0, 3) - dist(1, 2)) <= eps) && (fabs(dot(0, 1, 0, 3)) <= eps);
        return ok1 || ok2;
    }

    void setDefault() {
        coords[0][0] = 1.0; coords[0][1] = 2.0;
        coords[1][0] = 3.0; coords[1][1] = 2.0;
        coords[2][0] = 1.0; coords[2][1] = 1.0;
        coords[3][0] = 3.0; coords[3][1] = 1.0;
    }

    void setCoords(double p[4][2]) {
        bool valid = true;
        for (int i = 0; i < 4 && valid; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (p[i][j] <= 0.0 || p[i][j] >= 20.0) {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) {
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 2; ++j)
                    coords[i][j] = p[i][j];
            if (!isValidRectangle()) {
                setDefault();
            }
        } else {
            setDefault();
        }
    }

public:
    Rectangle(double p[4][2]) {
        setCoords(p);
    }

    double length() const {
        double side1 = (dist(0, 1) + dist(2, 3)) / 2.0;
        double side2;
        if (fabs(dist(0, 2) - dist(1, 3)) < 1e-6 && fabs(dot(0, 1, 0, 2)) < 1e-6) {
            side2 = (dist(0, 2) + dist(1, 3)) / 2.0;
        } else {
            side2 = (dist(0, 3) + dist(1, 2)) / 2.0;
        }
        return side1 > side2 ? side1 : side2;
    }

    double width() const {
        double side1 = (dist(0, 1) + dist(2, 3)) / 2.0;
        double side2;
        if (fabs(dist(0, 2) - dist(1, 3)) < 1e-6 && fabs(dot(0, 1, 0, 2)) < 1e-6) {
            side2 = (dist(0, 2) + dist(1, 3)) / 2.0;
        } else {
            side2 = (dist(0, 3) + dist(1, 2)) / 2.0;
        }
        return side1 < side2 ? side1 : side2;
    }

    double perimeter() const {
        return 2 * (length() + width());
    }

    double area() const {
        return length() * width();
    }

    bool square() const {
        return fabs(length() - width()) < 1e-6;
    }
};
//StudybarCommentBegin
int main()
{
    double rect[4][2];
    int i;
    
    for(i=0;i<4;i++)
    {
//        cout<<"请输入第"<<i+1<<"个点的横纵坐标（大于0且小于20）,以空格分隔：";
        cin>>rect[i][0]>>rect[i][1];
    }
    
    Rectangle myRect(rect);
    cout<<"长度为："<<myRect.length()<<endl;
    cout<<"宽度为："<<myRect.width()<<endl;
    cout<<"周长为："<<myRect.perimeter()<<endl;
    cout<<"面积为："<<myRect.area()<<endl;
    
    if(myRect.square())
        cout<<"此长方形是一个正方形"<<endl;
    else
        cout<<"此长方形不是一个正方形"<<endl;
    
    return 0;
}
//StudybarCommentEnd