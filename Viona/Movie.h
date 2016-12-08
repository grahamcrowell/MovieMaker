#ifndef MOVIE_H
#define MOVIE_H

#include <QString>
#include <QSize>
#include <QImage>
#include <QPainter>
#include <QPainterPath>
#include <QTransform>
#include "../util/helpers.h"
#include <functional>
typedef qreal real;
typedef real (*fptr)(real);

class Movie
{
    QSize size; // dimension of canvas
    int n; // number of frames to make and save
    QString dirpath; // folder to save JPGs in
    QString imagePathFormat;
    QImage image; // canvas that is drawn on by painter
    QPainter painter; // this draws on image
    QTransform *transform; // transformation of coordinate system to cartesian
    QPointF *origin; // point of reference
    QList<QPointF> points; // control points for benzier curve
    QList<QPainterPath> frames;

public:
    Movie(QSize size, int n, QString dirpath, QList<QPointF> points);
    void makeMovie();
    void runFFmpeg(QString movieName);
    int toFile(QList<QPainterPath> paths);
    ~Movie();
};

#endif // MOVIE_H
