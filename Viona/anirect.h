#ifndef ANIRECT_H
#define ANIRECT_H
#include <QRectF>
#include <QPointF>


class AniRect
{
    QPointF centre;
public:
    AniRect(QPointF centre);
    QRectF operator ()(qreal r);
};

#endif // ANIRECT_H
