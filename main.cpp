#include <QApplication>
#include <QQmlApplicationEngine>
#include "framemaker.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

//
    FrameMaker fm(QSize(500,500),1000,QString("/Users/grahamcrowell/Desktop/movie"));
    fm.allAtOnce();
//    return 0;
    return app.exec();
}
