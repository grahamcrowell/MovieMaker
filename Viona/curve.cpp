#include "curve.h"

Curve::Curve(Pt pt0, Pt pt1, int n)
{
    Pt dpt = (pt1-pt0)/n;
    for (int i = 0; i < n; ++i) {
        this->append(pt0+dpt*i);
    }
}
QList<QPainterPath> Curve::growCurve()
{
    QList<QPainterPath> paths;
    QPainterPath pp;
    pp.moveTo(this->at(0));
    for (int i = 1; i < this->length(); ++i) {
        pp.lineTo(this->at(i));
        paths.append(pp);
    }
    return paths;
}
QPainterPath Curve::getPath()
{
    QPainterPath pp;
    for (int i = 0; i < this->length() - 1; ++i) {
        pp = QPainterPath(this->at(i));
        pp.lineTo(this->at(i+1));
    }
    return pp;
}

QList<QPainterPath> Curve::getPaths()
{
    QList<QPainterPath> paths;
    QPainterPath pp;
    for (int i = 0; i < this->length() - 1; ++i) {
        pp = QPainterPath(this->at(i));
        pp.lineTo(this->at(i+1));
        paths.append(pp);
    }
    return paths;
}

QList<QPainterPath> Curve::joinPaths(QList<QPainterPath> other)
{
    QList<QPainterPath> paths;
    QPainterPath pp;
    for (int i = 0; i < this->length() - 1; ++i) {
        pp = QPainterPath(this->at(i));
        pp.lineTo(this->at(i+1));
        pp.addPath(other[i]);
        paths.append(pp);
    }
    return paths;
}
