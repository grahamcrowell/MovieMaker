#ifndef FRAMEMAKER_H
#define FRAMEMAKER_H

#include <QString>
#include <QSize>
#include <QImage>
#include <QPainter>
#include <QPainterPath>
#include <QTransform>
#include "../util/helpers.h"

class FrameMaker
{
    QSize size; // dimension of canvas
    int n; // number of frames to make and save
    QString dirpath; // folder to save JPGs in
    QString imagePathFormat;
//    QImage image; // canvas that is drawn on by painter
//    QPainter painter; // this draws on image
    QTransform *transform; // transformation of coordinate system to cartesian
    QPointF *origin; // point of reference

public:
  FrameMaker(QSize size, int n, QString dirpath);
  QImage* getTestImage();
  int computePaths();
  // int writeImages();
  int allAtOnce();
  // int cleanDir();
   ~FrameMaker();
};

#endif // FRAMEMAKER_H
