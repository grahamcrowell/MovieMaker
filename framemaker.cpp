#include "framemaker.h"
#include <QTransform>
#include <QPen>
#include <QBrush>
#include <QDir>

#include <QtCore>
#include <math.h>

FrameMaker::FrameMaker(QSize size, int n, QString dirpath)
    : size(size), n(n), dirpath(dirpath)
{
    out(QString("in the future everyone will be famous for 15 minutes."));
    imagePathFormat = QString("%1/%2");

// drawing init
//    image = QImage(size,QImage::Format_RGB32);
//    image.fill(Qt::white);
//    painter = QPainter(&image);
//    painter.setRenderHint(QPainter::Antialiasing);

    // center coordinates at center of image (cartesian) with translation
    // if matrix is identity then there is not transformation
    // see http://doc.qt.io/qt-5/qtransform.html#basic-matrix-operations
    qreal m11, m12, m13, m21, m22, m23, m31, m32, m33;
    m11 = 1; // horizontal scaling factor (1 = none)
    m22 = 1; // vertical scaling factor (1 = none)
    m31 = size.width()/2; // horizontal translation aka 'dx()' (0 = none)
    m32 = size.height()/2; // vertical translation aka 'dy()' (0 = none)
    m21 = 0; // horizontal shearing (0 = none)
    m12 = 0; // vertical shearing (0 = none)
    m13 = 0; // horizontal projection (0 = none)
    m23 = 0; // vertical projection (0 = none)
    m33 = 1; // additional projection factor (0 = none)
    transform = new QTransform(m11, m12, m13, m21, m22, m23, m31, m32, m33);
//    painter.setWorldTransform(*transform);
    origin = new QPointF(0,0);
}

int FrameMaker::allAtOnce()
{
    QImage tmpImage(size,QImage::Format_RGB32);
    tmpImage.fill(Qt::white);
    QPainter tmpPainter(&tmpImage);
    tmpPainter.setRenderHint(QPainter::Antialiasing);
    tmpPainter.setBrush(Qt::black);
    tmpPainter.setPen(Qt::blue);
    tmpPainter.setWorldTransform(*transform);

    qreal unit(200);
    qreal x0=unit,y0=0,r=10;
    QPointF pti(x0,y0);
    for (int i = 0; i < n; ++i) {
//        tmpImage.fill(Qt::white);
        pti.setX(unit*qCos(i*2*M_PI/n));
        pti.setY(unit*qSin(i*2*M_PI/n));
        tmpPainter.drawEllipse(pti,r,r);
        out(QString("paint complete"));
        out(pti);
        int width = 3;
        int base = 10;
        QChar fill = '0';
        QString filename = QString("img%1.jpg").arg(i,width,base,fill);
        QString filepath = imagePathFormat.arg(dirpath).arg(filename);
        out(filepath);
        tmpImage.save(filepath,0,100);
    }
    return 1;
}

int FrameMaker::computePaths()
{
    out(QString("computing paths . . . "));
    qreal unit(100);
    qreal x0=unit,y0=0;
    QPointF pt0(x0,y0);
    QPointF pti(x0,y0);
    for (int i = 0; i < n; ++i) {
        QPainterPath *tmpPath = new QPainterPath();
        tmpPath->moveTo(pt0);
        pti.setX(qCos(i*2*M_PI/n));
        pti.setY(qSin(i*2*M_PI/n));
        out(pti);
        tmpPath->lineTo(pti);
        tmpPath->addEllipse(pti,50,50);
//        paths.append(tmpPath);
        pt0=pti;
    }
    return 1;
}

