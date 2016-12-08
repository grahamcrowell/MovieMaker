#ifndef PLUMBING_H
#define PLUMBING_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QtQuick/QQuickPaintedItem>
#include <QColor>

class Plumbing : public QQuickPaintedItem
{
    Q_OBJECT
    //Q_PROPERTY(QString qml_left_var READ public_cpp_function WRITE public_cpp_function NOTIFY cpp_signal)
    Q_PROPERTY(QString qml_left_var READ getQmlLeftVar WRITE setQmlLeftVar NOTIFY inputChanged)
    Q_PROPERTY(QString qml_right_var READ getQmlRightVar WRITE setQmlRightVar NOTIFY inputChanged)

    //http://doc.qt.io/qt-5/qtqml-cppintegration-exposecppattributes.html#exposing-signals
signals:
    void inputChanged();
private:
    QString _qml_left_var;
    QString _qml_right_var;

public slots:
    void handleButton();
public:
    Plumbing(QQuickItem *parent = 0);
    ~Plumbing();
    QString getQmlLeftVar();
    QString getQmlRightVar();
    void setQmlLeftVar(const QString &f);
    void setQmlRightVar(const QString &f);
    void paint(QPainter *painter);
};

#endif // PLUMBING_H
