#include <QProcess>
#include <QDebug>
#include <QColor>
#include <QPainter>

#include "plumbing.h"
#include "framemaker.h"


Plumbing::Plumbing(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
}

Plumbing::~Plumbing()
{
}

QString Plumbing::getQmlLeftVar()
{
    qDebug() << "getQmlLeftVar called " << _qml_left_var;
    return _qml_left_var;
}

void Plumbing::setQmlLeftVar(const QString &f)
{
    if (f != _qml_left_var) {
        _qml_left_var = f;
        qDebug() << "setQmlLeftVar " << _qml_left_var;
        emit inputChanged();
    }
}

QString Plumbing::getQmlRightVar()
{
    qDebug() << "getQmlRightVar called " << _qml_right_var;
    return _qml_right_var;
}

void Plumbing::setQmlRightVar(const QString &f)
{
    if (f != _qml_right_var) {
        _qml_right_var = f;
        qDebug() << "setQmlRightVar called " << _qml_right_var;
        emit inputChanged();
    }
}

void Plumbing::paint(QPainter *painter)
{
    qDebug() << "leave me alone while i paint " << _qml_left_var;
    QColor colour = QColor("green");
    QPen pen(colour,2);
    painter->setPen(pen);
    painter->setRenderHints(QPainter::Antialiasing, true);
    painter->drawPie(boundingRect().adjusted(1, 1, -1, -1), 90 * 16, 290 * 16);
    qDebug() << "OK what you want? " << _qml_left_var;
}

void Plumbing::handleButton()
{
    qDebug() << "handleButton called, hello from c++";
     QString message("_qml_left_var: %1");
    // out(QString("executing FrameMaker"));
    int n = _qml_left_var.toInt();
    int width = _qml_right_var.toInt();

    QList<QPointF> pts;
    pts.append(QPointF(0,0));
    pts.append(QPointF(200,200));
    pts.append(QPointF(200,-200));
    qDebug() << message.arg(_qml_left_var);
    qDebug() << message.arg(_qml_right_var);
    qDebug() << "Creating FrameMaker object";
    FrameMaker fm(QSize(width,width),n,QString("/Users/grahamcrowell/Desktop/test_movie"),pts);
    qDebug() << "calling FrameMaker::makeMovie()";
    fm.makeMovie();
}
