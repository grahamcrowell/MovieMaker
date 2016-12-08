#include "framemaker.h"
#include "curve.h"
#include <QTransform>
#include <QPen>
#include <QBrush>
#include <QDir>
#include <QPointF>

#include <QtCore>
#include <math.h>
#include <functional>


FrameMaker::FrameMaker(QSize size, int n, QString dirpath,QList<QPointF> points)
    : size(size), n(n), dirpath(dirpath), points(points)
{
    out(QString("in the future everyone will be famous for 15 minutes."));
    imagePathFormat = QString("%1/%2");
    //    painter = QPainter(size,QImage::Format_RGB32);
    //    image =
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
    //    Frame f()
}

void FrameMaker::makeMovie()
{
    out(QString("making a movie"));
//    QPointF p0 = points[0];
//    QPointF p1 = points[1];
//    auto f = [p0](real t){ return QRectF(p0.x()-t,p0.y()-t,p0.x()+t,p0.y()+t); };

//    QList<QPainterPath> frames;
//    QPainterPath tmp;
//    qreal r(50);
    int steps = 100;
    Curve c0(points[0],points[1],steps);
    frames = c0.growCurve();
    Curve c1(points[1],points[2],steps);
    out(QString("hello ****"));

    QList<QPainterPath> tmp = c1.getPaths();


    for (int i = 0; i < c1.length()-1; ++i) {
        frames[i].addPath(tmp[i]);
    }
//    frames = computePaths();
    toFile(frames);
    runFFmpeg("123");
}
int FrameMaker::toFile(QList<QPainterPath> paths)
{
    QImage tmpImage(size, QImage::Format_RGB32);
    tmpImage.fill(Qt::white);
    QPainter tmpPainter(&tmpImage);
    tmpPainter.setRenderHint(QPainter::Antialiasing);
    tmpPainter.setBrush(Qt::black);
    tmpPainter.setPen(Qt::blue);
    tmpPainter.setWorldTransform(*transform);

    QDir dir(dirpath);
    dir.setFilter(QDir::Files);
    QStringList filters;
    filters << "*.png";
    dir.setNameFilters(filters);
    QStringList filenames(dir.entryList());
    for (int i = 0; i < filenames.length(); ++i)
    {
        QFile file(dir.absoluteFilePath(filenames[i]));
        out(QString("removing %1").arg(filenames[i]));
        if(file.remove())
        {
            out(QString("\tdeletion successful"));
        }
    }

    for (int i = 0; i < paths.length(); ++i) {
        tmpImage.fill(Qt::white);
        tmpPainter.drawPath(paths[i]);
        int width = 3;
        int base = 10;
        QChar fill = '0';
        QString filename = QString("img%1.png").arg(i,width,base,fill);
        QString filepath = imagePathFormat.arg(dirpath).arg(filename);
        tmpImage.save(filepath);
        QString message = QString("saving %1").arg(filepath);
        out(message);
    }
    return paths.length();
}

void FrameMaker::runFFmpeg(QString movieName)
{
    QString message = QString("executing FFmpeg");
    out(message);
    QString program = QString("%1/ffmpeg").arg(dirpath);
    QStringList args;
    QString imgPath = QString(dirpath+"/"+"img%03d.png");
    QString movPath = QString(dirpath+"/"+movieName+".avi");
    QFile movFile(movPath);
    if(movFile.exists())
    {
        if(movFile.remove())
        {
            out(QString("movie deleted"));
        }
        else
        {
            out(QString("unable to delete movie"));
        }
    }

    args << "-framerate" << "25" << "-pattern_type" << "sequence" << "-start_number" << "000" << "-r" << "40" << "-i" << imgPath << movPath;
    out(program);
//    out(args);
    QProcess *myProcess = new QProcess();
    myProcess->start(program, args);
    myProcess->waitForFinished();
    QByteArray result = myProcess->readAll();
    qDebug() << QString(result);
    myProcess->close();
    message = QString("FFmpeg complete");
    out(message);
//    delete myProcess;
    message = QString("playing with VLC . . .");
    out(message);
    myProcess = new QProcess();
    program = QString("/Applications/VLC.app/Contents/MacOS/vlc");
    args.clear();
    args << movPath;
    myProcess->start(program, args);
//    myProcess->waitForFinished();
//    myProcess->close();
//    out(message);
}

FrameMaker::~FrameMaker() {}

