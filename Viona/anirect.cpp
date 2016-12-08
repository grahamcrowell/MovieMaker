#include "anirect.h"

AniRect::AniRect(QPointF centre) : centre(centre)
{

}

QRectF AniRect::operator ()(qreal r)
{
    return QRectF(centre.x()-r,centre.y()-r,centre.x()+r,centre.y()+r);
}
