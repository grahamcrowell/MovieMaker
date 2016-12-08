#include <iostream>
#include <memory>
#include <functional>

typedef qreal real;
typedef QPointF Point;

typedef real (*Function)(real);
//#include <random>

//using namespace std;

class B
{
    Point p0;
    Point p1;
public:
    B(Point p0, Point p1):p0(p0),p1(p1) {}
    Point operator()(real t)
    {
        return (1-t)*p0+t*p1;
    }
};



void foo2()
{
    Point p0(100,100);
    Point p1(-100,-213);
    Point p2(400,-100);
    B b(p0,p1);
    out(b(0));
    out(b(0.5));
    out(b(1));

    auto f = [p0,p1](real t){ return (1-t)*p0+t*p1; };
    auto *fptr = &f;


    out((Point)(f(0)));
    out(f(0.5));
    out(f(1));

    out((Point)((*fptr)(0)));
    out((Point)((*fptr)(0.5)));
    out((Point)((*fptr)(1)));





//    qDebug() << f(0.5);

}
void foo3()
{
    Point p0(100,100);
    Point pn = p0/100;
    out(pn);
    Point p5 = pn*5;
    out(p5);
    Point pp = p5-p0;
    out(pp);
}
#include "curve.h"


//void foo()
//{
//    pt pt0 = pt(0,0);
//    pt pt1 = pt(100,100);
//    pt pt2 = pt(200,0);
//    QList<pt> pts;
//    pts.append(pt0);
//    pts.append(pt1);
//    pts.append(pt2);
//    QList<Curve> B;
//    int n = 100;
//    B.append(Curve(pt0,pt1,n));
//    B.append(Curve(pt1,pt2,n));

////    QList<Curve> B2;
////    Curve c;

////    for (int i = 0; i < n; ++i) {
////        Curve tmp(B[0][i],B[1][i],n);
////        B2.append(c);
////        c.append(tmp[i]);
////    }


//}
