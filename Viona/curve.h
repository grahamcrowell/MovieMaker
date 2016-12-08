#ifndef CURVE_H
#define CURVE_H

#include <QPointF>
#include <QList>
#include <QPainterPath>

typedef QPointF Pt;

class Curve : public QList<Pt>
{
public:
    // define line from pt0 to pt1 with n sublines
    Curve(Pt pt0, Pt pt1, int n);
    QList<QPainterPath> growCurve();
    QPainterPath getPath();
    QList<QPainterPath> fadeCurve();
    QList<QPainterPath> getPaths();
    QList<QPainterPath> joinPaths(QList<QPainterPath> other);

};

#endif // CURVE_H
