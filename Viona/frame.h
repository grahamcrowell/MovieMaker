#ifndef FRAME_H
#define FRAME_H
#include <QList>
#include <QPainterPath>

class Frame : public QList<QPainterPath>
{
public:
    Frame(QList<QPainterPath> paths);

};

#endif // FRAME_H
